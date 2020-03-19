#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

class UnionFind {
    public:
        UnionFind() {};
        UnionFind(int N) {
            unionData.reserve(N);
            for(int i = 0; i < N; i++) unionData.push_back(i);
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

vector<vector<pair<int, int>>> graph;
vector<pair<int, pair<int, int>>> edges;
UnionFind uf;
int V, E;
int result = 0;

int main() {
    scanf("%d %d", &V, &E);
    graph.reserve(V+1);
    edges.reserve(E);
    uf = UnionFind(V+1);
    for(int i = 0; i < E; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        graph[a].push_back(make_pair(c, b));
        edges.push_back(make_pair(c, make_pair(a, b)));
    }
    sort(edges.begin(), edges.end());
    for(int i = 0; i < E; i++) {
        pair<int, pair<int, int>> p = edges[i];
        int x = p.second.first, y = p.second.second, len = p.first;
        if(!uf.isSameSet(x, y)) {
            result += len;
            uf.unionSet(x, y);
        }
    }
    printf("%d", result);
    return 0;
}