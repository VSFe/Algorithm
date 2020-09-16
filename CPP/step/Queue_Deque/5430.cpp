/*
Problem: AC(5430)
Tier: Silver 2
Detail: 함수 R은 배열에 있는 숫자의 순서를 뒤집는 함수이고, D는 첫 번째 숫자를 버리는 함수이다. 배열이 비어있는데 D를 사용한 경우에는 에러가 발생한다.
함수는 조합해서 한 번에 사용할 수 있다. 예를 들어, "AB"는 A를 수행한 다음에 바로 이어서 B를 수행하는 함수이다. 예를 들어, "RDD"는 배열을 뒤집은 다음 처음 두 숫자를 버리는 함수이다.
배열의 초기값과 수행할 함수가 주어졌을 때, 최종 결과를 구하는 프로그램을 작성하시오.
Comment: 반복을 줄이고, 깔끔하게 짜는 방법을 배웠으면...
*/

#include <stdio.h>
#include <deque>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

deque<int> deck;
char opcode[100001];
char input[600001];
int n;

int del(int r) {
	if (deck.empty()) {
		return -1;
	}
	if (r == 1) {
		deck.pop_back();
	}
	else if (r == 0) {
		deck.pop_front();
	}
	
	return 0;
}


int main() {
	int testcase;
	scanf("%d", &testcase);
	while (testcase--) {
		int flag = 0;
		int revers_flag = 0;
		scanf("%s %d", opcode, &n);
		int size = strlen(opcode);
		scanf("%s", input);
		input[strlen(input) - 1] = 0;
		char* ptr = strtok(&input[1], ",");
		while (ptr != NULL) {
			int num = atoi(ptr);
			deck.push_back(num);
			ptr = strtok(NULL, ",");
		}
		for (int i = 0; i < size; i++) {
			if (opcode[i] == 'R') {
				revers_flag = !revers_flag;
			}
			else if (opcode[i] == 'D') {
				flag = del(revers_flag);
				if (flag == -1) {
					printf("error\n");
					break;
				}
			}
		}
		if (flag != -1) {
			printf("[");
			while (!deck.empty()) {
				int num;
				if (revers_flag == 0) {
					num = deck.front();
					deck.pop_front();
				}
				else {
					num = deck.back();
					deck.pop_back();
				}

				printf("%d", num);
				if (deck.empty()) {
					break;
				}
				printf(",");
			}
			printf("]\n");
		}

	}
}