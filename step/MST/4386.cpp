/*
Problem: 별자리 만들기 (4386)
Tier: Gold 4
Detail: 도현이는 우주의 신이다. 이제 도현이는 아무렇게나 널브러져 있는 n개의 별들을 이어서 별자리를 하나 만들 것이다. 별자리의 조건은 다음과 같다.
    별자리를 이루는 선은 서로 다른 두 별을 일직선으로 이은 형태이다.
    모든 별들은 별자리 위의 선을 통해 서로 직/간접적으로 이어져 있어야 한다.
별들이 2차원 평면 위에 놓여 있다. 선을 하나 이을 때마다 두 별 사이의 거리만큼의 비용이 든다고 할 때, 별자리를 만드는 최소 비용을 구하시오.
Comment: 좌표 평면이기 때문에 edge를 표현할 때 쪼금 어려울 수 있는데, 그저 V * (V-1) / 2개의 간선이 있다고 하면 해결...
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
int V, E;
double result = 0;

int main() {
    scanf("%d", &V);
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
    for(int i = 0; i < E; i++) {
        pair<double, pair<int, int>> p = edges[i];
        int x = p.second.first, y = p.second.second;
        double len = p.first;
        if(!uf.isSameSet(x, y)) {
            result += len;
            uf.unionSet(x, y);
        }
    }
    printf("%f", result);
    return 0;
}
