/*
Problem: 친구 네트워크 (4195)
Tier: Gold 2
Detail: 어떤 사이트의 친구 관계가 생긴 순서대로 주어졌을 때, 두 사람의 친구 네트워크에 몇 명이 있는지 구하는 프로그램을 작성하시오.
친구 네트워크란 친구 관계만으로 이동할 수 있는 사이를 말한다.
Comment: 해싱을 하던지 해야하는데... map을 씁시다.
*/

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class UnionFind {
    public:
        UnionFind() {};
        UnionFind(int N) {
            unionData.reserve(N);
            for(int i = 0; i < N; i++) unionData.push_back(i);
            unionRank.assign(N, 0);
            unionLen.assign(N, 1);
            size = N;
        }
        int findSet(int i);
        int numDisjointSets();
        int sizeOfSets(int i);
        int unionSet(int i, int j);
        void renewSet();
        void renewSet(int len);
        bool isSameSet(int i, int j);
    private:
    vector<int> unionData;
    vector<int> unionRank;
    vector<int> unionLen;
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
    return unionLen[i];
}


void UnionFind::renewSet() {
    for(int i = 0; i < size; i++) {
        if(unionData[i] != i) findSet(i);
    }
}

void UnionFind::renewSet(int len) {
    for(int i = 0; i < len; i++) {
        if(unionData[i] != i) findSet(i);
    }
}

int UnionFind::unionSet(int i, int j) {
    int x = findSet(i), y = findSet(j); 
    if(x != y) {
        unionData[y] = x;
        unionLen[x] += unionLen[y];
    }
    return unionLen[x];
}

bool UnionFind::isSameSet(int i, int j) {
    return findSet(i) == findSet(j);
}

int t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    for(int i = 0; i < t; i++) {
        map<string, int> m;
        int c;
        int len = 0;
        cin >> c;
        UnionFind uf(c+1);
        for(int i = 0; i < c; i++) {
            string a, b;
            cin >> a >> b;
            if(m.find(a) == m.end()) { m.insert(pair<string, int>(a, len)); len++; }
            if(m.find(b) == m.end()) { m.insert(pair<string, int>(b, len)); len++; }
            map<string, int>::iterator afind = m.find(a);
            map<string, int>::iterator bfind = m.find(b);
            cout << uf.unionSet(afind->second, bfind->second) << "\n";
        }
    }
    return 0;
} 