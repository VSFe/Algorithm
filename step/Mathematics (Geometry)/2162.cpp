/*
Problem: 선분 그룹
Tier: Gold 1
Detail: N개의 선분들이 2차원 평면상에 주어져 있다. 선분은 양 끝점의 x, y 좌표로 표현이 된다.
두 선분이 서로 만나는 경우에, 두 선분은 같은 그룹에 속한다고 정의하며, 그룹의 크기는 그 그룹에 속한 선분의 개수로 정의한다.
두 선분이 만난다는 것은 선분의 끝점을 스치듯이 만나는 경우도 포함하는 것으로 한다.
N개의 선분들이 주어졌을 때, 이 선분들은 총 몇 개의 그룹으로 되어 있을까? 또, 가장 크기가 큰 그룹에 속한 선분의 개수는 몇 개일까? 이 두 가지를 구하는 프로그램을 작성해 보자.
Comment: CCW로 선분이 겹치는지 판단하고, 자연스럽게 Union-Find로 묶어주면 된다.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class UnionFind {
    public:
        UnionFind() {};
        UnionFind(int N) {
            unionData.reserve(N);
            for(int i = 0; i < N; i++) unionData[i] = i;
            unionRank.assign(N, 0);
            size = N;
        }
        int findSet(int i);
        int numDisjointSets();
        int sizeOfSets(int i);
        void unionSet(int i, int j);
        void renewSet();
        bool isSameSet(int i, int j);
    private:
    vector<int> unionData;
    vector<int> unionRank;
    int size;  
};

int UnionFind::findSet(int i) {
    return (unionData[i] == i) ? i : (unionData[i] = findSet(unionData[i]));
}

int UnionFind::numDisjointSets() {
    int cnt = 0;
    for(int i = 0; i < size; i++) {
        if(unionData[i] == i) cnt++;
    }
    return cnt;
}

int UnionFind::sizeOfSets(int i) {
    renewSet();
    int cnt = 0;
    for(int j = 0; j < size; j++) {
        if(unionData[j] == i) cnt++;
    }
    return cnt;
}

void UnionFind::renewSet() {
    for(int i = 0; i < size; i++) {
        if(unionData[i] != i) findSet(i);
    }
}

void UnionFind::unionSet(int i, int j) {
    if(!isSameSet(i, j)) {
        int x = findSet(i), y = findSet(j);
        if(unionRank[x] > unionRank[y]) unionData[y] = x;
        else {
            unionData[x] = y;
            if(unionRank[x] == unionRank[y]) unionRank[y]++;
        }
    }
}

bool UnionFind::isSameSet(int i, int j) {
    return findSet(i) == findSet(j);
}

struct point {
    int x; int y;
    point() {}
    point(int x, int y) : x(x), y(y) { }
    bool operator >= (point& p2) {
        if(x == p2.x && y == p2.y) return true;
        else if(x == p2.x) return (y >= p2.y);
        return (x >= p2.x);
    } 
    bool operator == (point& p2) {
        return (x == p2.x && y == p2.y);
    }
};

int CCW(point &x, point &y, point &z) {
    long long cal = (long long)(y.x - x.x) * (long long)(z.y - x.y) - (long long)(y.y - x.y) * (long long)(z.x - x.x);
    if(cal == 0) return 0;
    else if(cal > 0) return 1; //CCW
    else return -1; //CW
}

vector<pair<point, point>> vec; 
UnionFind uf;
int MAX = -1;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;
    uf = UnionFind(N);
    vec.reserve(N);
    for(int i = 0; i < N; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        vec.push_back(make_pair(point(x1, y1), point(x2, y2)));
    }
    for(int i = 0; i < N; i++) {
        for(int j = i + 1; j < N; j++) {
            if(uf.isSameSet(i, j)) continue;
            bool is_meet = false;
            point pi_1 = vec[i].first, pi_2 = vec[i].second, pj_1 = vec[j].first, pj_2 = vec[j].second; 
            int t1 = CCW(pi_1, pi_2, pj_1) * CCW(pi_1, pi_2, pj_2);
            int t2 = CCW(pj_1, pj_2, pi_1) * CCW(pj_1, pj_2, pi_2);
            if(t1 <= 0 && t2 <= 0) {
                if(t1 == 0 && t2 == 0) {
                    if(pi_1 == pj_1 || pi_1 == pj_2 || pi_2 == pj_1 || pi_2 == pj_2 ) is_meet = true;
                    else if(pi_1 >= pj_2) is_meet = (pj_1 >= pi_2) ? true : false;
                    else is_meet = (pi_2 >= pj_1) ? true : false;
                } else is_meet = true;
            } else is_meet = false;
            if(is_meet) uf.unionSet(i, j);
        }
    }
    for(int i = 0; i < N; i++) {
        if(MAX < uf.sizeOfSets(i)) MAX = uf.sizeOfSets(i);
    }
    cout << uf.numDisjointSets() << '\n' << MAX;
    return 0;
}