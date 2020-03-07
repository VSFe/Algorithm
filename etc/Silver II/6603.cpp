/*
Problem: 로또(6603)
Tier: Silver 2
Detail: 집합 S와 k가 주어졌을 때, 수를 고르는 모든 방법을 구하는 프로그램을 작성하시오.
Comment: 6중 for 문 쓸 바엔 라이브러리 쓰고 만다...
*/

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    while(true) {
        int x;
        scanf("%d", &x);
        if(x == 0) return 0;
        vector<int> v(x);
        for(int i = 0; i < x; i++) {
            scanf("%d", &v[i]);
        }
	vector<int> ind;
	for(int i=0; i<6; i++){
		ind.push_back(0);
	}
    int v_size = v.size();
	for(int i=0; i < v_size-6; i++){
		ind.push_back(1);
	}
	sort(ind.begin(), ind.end());
	do{
		for(int i=0; i<ind.size(); i++){
			if(ind[i] == 0){
				printf("%d ", v[i]);
			}
		}
		printf("\n");

	}while(next_permutation(ind.begin(), ind.end()));
    printf("\n");
    }
	return 0;
}
