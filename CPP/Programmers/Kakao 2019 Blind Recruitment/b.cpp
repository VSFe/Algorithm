#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<double, int> &a, pair<double, int> &b) {
    if(a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}

vector<int> solution(int N, vector<int> stages) {
    double challenge[502] = {0, };
    double failure[502] = {0, };
    vector<pair<double, int>> rate;
    vector<int> answer;
    
    for(int i: stages) {
        challenge[i]++;
        failure[i]++;
    }
    
    for(int i = N; i >= 1; i--) {
        challenge[i] += challenge[i + 1];
    }
    
    for(int i = 1; i <= N; i++) {
        if(!challenge[i]) rate.push_back({0, i});
        else rate.push_back({failure[i] / challenge[i], i});
    }
    
    sort(rate.begin(), rate.end(), compare);
    
    for(int i = 0; i < N; i++) {
        answer.push_back(rate[i].second);
    }
    
    return answer;
}