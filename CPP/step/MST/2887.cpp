/*
Problem: 행성 터널 (2887)
Tier: Gold 2
Detail: 때는 2040년, 이민혁은 우주에 자신만의 왕국을 만들었다. 왕국은 N개의 행성으로 이루어져 있다. 민혁이는 이 행성을 효율적으로 지배하기 위해서 행성을 연결하는 터널을 만들려고 한다.
행성은 3차원 좌표위의 한 점으로 생각하면 된다. 두 행성 A(xA, yA, zA)와 B(xB, yB, zB)를 터널로 연결할 때 드는 비용은 min(|xA-xB|, |yA-yB|, |zA-zB|)이다.
민혁이는 터널을 총 N-1개 건설해서 모든 행성이 서로 연결되게 하려고 한다. 이때, 모든 행성을 터널로 연결하는데 필요한 최소 비용을 구하는 프로그램을 작성하시오.
Comment: 100000C2 = ? MLE....
따라서 모든 점을 다 잇는 미친 생각보단 적당히 잘 걸러내서 간선을 생성해야 할 것 같다...
대각선은 어차피 의미 없으니 위아래/좌우/상하 6점만 고려하면 될 듯.
*/

#include <stdio.h>
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


struct edge {
    int u, v, weight;
    bool operator < (edge &e) {
        return weight < e.weight;
    }
};

struct vertex{
    int idx, x, y, z;
    int distance(vertex &v) {
        return min({abs(x - v.x), abs(y - v.y), abs(z - v.z)});
    }
};

bool compare_x(vertex &v1, vertex &v2) {
    return (v1.x < v2.x);
}

bool compare_y(vertex &v1, vertex &v2) {
    return (v1.y < v2.y);
}

bool compare_z(vertex &v1, vertex &v2) {
    return (v1.z < v2.z);
}

int n;
vector<vertex> vec;

int main() {
    scanf("%d", &n);
    vec.reserve(n);
    for(int i = 0; i < n; i++) {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        vec.push_back(vertex({i, x, y, z}));
    }
    vector<edge> vec_edge;
    sort(vec.begin(), vec.end(), compare_x);
    for(int i = 1; i < n; i++) vec_edge.push_back({vec[i-1].idx, vec[i].idx, vec[i-1].distance(vec[i])});
    sort(vec.begin(), vec.end(), compare_y);
    for(int i = 1; i < n; i++) vec_edge.push_back({vec[i-1].idx, vec[i].idx, vec[i-1].distance(vec[i])});
    sort(vec.begin(), vec.end(), compare_z);
    for(int i = 1; i < n; i++) vec_edge.push_back({vec[i-1].idx, vec[i].idx, vec[i-1].distance(vec[i])});
    sort(vec_edge.begin(), vec_edge.end());
    long long result = 0;
    UnionFind uf = UnionFind(n+1);
    for(int i = 0; i < vec_edge.size(); i++) {
        edge e = vec_edge[i];
        if(!uf.isSameSet(e.u, e.v)) {
            result += e.weight;
            uf.unionSet(e.u, e.v);
        }
    }
    printf("%lld", result);
    return 0;
}