/*
Problem: 제21대 국회의원 선거 (18891)
Tier: Gold 1
Detail: 정당들의 지역구 의석 수와 비례대표 득표 결과가 각각 주어질 때, 각 정당이 21대 국회의원 선거 결과에 따라 얻게 되는 총 의석 수를 각각 계산해 보자.
의원정수는 300명이며 지역구국회의원이 253명, 비례대표국회의원이 47명이다. 비례대표 의석은 비례대표국회의원선거 유효투표총수의 3% 이상을 득표했거나 지역구국회의원선거에서 5석 이상의 의석을 차지한 정당에만 배분된다(봉쇄조항).
비례대표 의석을 배분받는 정당을 의석할당정당이라 한다. 제21대 국회의원 선거에 한해, 비례대표 의석 배분 방식은 다음과 같다.
(1단계) 30석에 대해 전국단위 준연동(연동비율 50%) 방식으로 각 정당별 연동배분의석수 산정
(2-1단계) 각 정당별 연동배분의석수의 합계 < 30석일 경우 ☞ 잔여의석에 대해 기존 의석배분방식(병립형) 적용 배분
(2-2단계) 각 정당별 연동배분의석수의 합계 > 30석 ☞ 각 정당별 연동배분의석수비율대로 배분
(3단계) 17석에 대해 기존 의석배분방식(병립형) 적용 배분
Comment: 다 끊어버리고 합치면 될 것 같은데...
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <queue>
using namespace std;

struct party {
    string name;
    int local, vote, result;
    double rate;
    bool is_enable;
    party() {}
    party(string s, int a, int b) : name(s), local(a), vote(b) {}
};

party parties[50];
int P, V, total_vote;

void get_last(vector<int> &vec, vector<pair<double, int>> &new_vec, int target) {
    int total = 0;
    for(auto i : vec) total += i;
    if(total < target) {
        sort(new_vec.begin(), new_vec.end(), [](auto a, auto b) {
            return a.first > b.first;
        });
        for(int i = 0; i < new_vec.size(); i++) {
            vec[new_vec[i].second]++;
            total++;
            if(total == target) break;
        }
    }
}

void get_ans() {
    int N = 300, R = 253;
    for(int i = 0; i < P; i++) {
        if(parties[i].is_enable) R -= parties[i].local;
    }
    vector<int> vec(P, 0);
    int total = 0;
    for(int i = 0; i < P; i++) {
        party p = parties[i];
        if(p.is_enable) {
            double val = (p.rate * (N - R) - p.local) / 2;
            if(val >= 1) vec[i] = round(val);
            total += vec[i];
        }
    }
    if(total != 30) {
        vector<pair<double, int>> ratio;
        for(int i = 0; i < P; i++) {
            party p = parties[i];
            if(p.is_enable) {
                double new_ratio;
                if(total < 30) new_ratio = (vec[i] + (30 - total) * p.rate);
                else new_ratio = (30.0 * vec[i] / total);
                ratio.push_back({new_ratio - floor(new_ratio), i});
                vec[i] = floor(new_ratio);
            }
        }
        get_last(vec, ratio, 30);
    }
    vector<int> v(P, 0);
    vector<pair<double, int>> ratio;
    for(int i = 0; i < P; i++) {
        party &p = parties[i];
        if(!p.is_enable) continue;
        double v_val = 17.0 * p.rate;
        v[i] = floor(v_val);
        ratio.push_back({v_val - floor(v_val), i});
    }
    get_last(v, ratio, 17);
    for(int i = 0; i < P; i++) {
        party &p = parties[i];
        p.result = vec[i] + v[i] + p.local;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> P >> total_vote;
    total_vote = 0;
    for(int i = 0; i < P; i++) {
        string s; int local, pp_vote;
        cin >> s >> local >> pp_vote;
        parties[i] = party(s, local, pp_vote);
        total_vote += pp_vote;
    }
    int total_enable_vote = 0;
    for(int i = 0; i < P; i++) {
        party &p = parties[i];
        if(p.local >= 5 || 1.0 * p.vote / total_vote >= 0.03) {
            p.is_enable = true;
            total_enable_vote += p.vote;
        }
        else p.is_enable = false;
    }
    for(int i = 0; i < P; i++) {
        party &p = parties[i];
        p.rate = 1.0 * p.vote / total_enable_vote;
    }
    get_ans();
    sort(parties, parties + P, [](party &a, party &b) {
        if(a.result != b.result)
            return a.result > b.result;
        return a.name < b.name;
    });

    for(int i = 0; i < P; i++) {
        cout << parties[i].name << ' ' << parties[i].result << '\n';
    }
}