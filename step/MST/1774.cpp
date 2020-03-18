/*
Problem: 우주신과의 교감 (1774)
Tier: Gold 4
Detail: 우주신들과의 교감은 우주신들과 황선자씨 혹은 우주신들 끼리 이어진 정신적인 통로를 통해 이루어 진다.
하지만 우주신들과 교감하는 것은 힘든 일이기 때문에 황선자씨는 이런 통로들이 긴 것을 좋아하지 않는다. 왜냐하면 통로들이 길 수록 더 힘이 들기 때문이다.
또한 우리들은 3차원 좌표계로 나타낼 수 있는 세상에 살고 있지만 우주신들과 황선자씨는 2차원 좌표계로 나타낼 수 있는 세상에 살고 있다. 통로들의 길이는 2차원 좌표계상의 거리와 같다.
이미 황선자씨와 연결된, 혹은 우주신들과 연결된 통로들이 존재한다. 우리는 황선자 씨를 도와 아직 연결이 되지 않은 우주신들을 연결해 드려야 한다.
새로 만들어야 할 정신적인 통로의 길이들이 합이 최소가 되게 통로를 만들어 “빵상”을 외칠수 있게 도와주자.
Comment: 크루스컬을 시행하기 전에 이미 연결되어 있는 간선에 한해 UnionFind 연산을 시행.
*/

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cmath>
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

vector<pair<double, double>> vertex;
vector<pair<double, pair<int, int>>> edges;
UnionFind uf;
int V, E, C;
double result = 0;

int main() {
    scanf("%d %d", &V, &C);
    E = V * (V - 1) / 2;
    vertex.reserve(V+1);
    edges.reserve(E);
    uf = UnionFind(V+1);
    for(int i = 0; i < V; i++) {
        double a, b;
        scanf("%lf %lf", &a, &b);
        vertex.push_back(make_pair(a, b));
    }
    for(int i = 0; i < V; i++) {
        for(int j = i + 1; j < V; j++) {
            double c = sqrt(pow(vertex[i].first - vertex[j].first, 2) + pow(vertex[i].second - vertex[j].second, 2));
            edges.push_back(make_pair(c, make_pair(i + 1, j + 1)));
        }
    }
    sort(edges.begin(), edges.end());
    for(int i = 0; i < C; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        uf.unionSet(a, b);
    }
    for(int i = 0; i < E; i++) {
        pair<double, pair<int, int>> p = edges[i];
        int x = p.second.first, y = p.second.second;
        double len = p.first;
        if(!uf.isSameSet(x, y)) {
            result += len;
            uf.unionSet(x, y);
        }
    }
    printf("%.2f", result);
    return 0;
}
