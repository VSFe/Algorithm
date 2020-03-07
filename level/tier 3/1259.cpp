/*
Problem: 팰린드롬수(1918)
Tier: Bronze 1
Detail: 어떤 단어를 뒤에서부터 읽어도 똑같다면 그 단어를 팰린드롬이라고 한다. 'radar', 'sees'는 팰린드롬이다.
Comment: 입력 받아서 뒤랑 앞에서 접근 해야지 뭐...
*/

#include <stdio.h>
#include <cmath>
using::log10;

int main() {
    int data;
    int h;
    while(true) {
        scanf("%d", &data);
        if(data == 0) return 0;
        h = log10(data);
        switch(h){
            case 0:
                printf("yes\n");
                continue;
            case 4: {
                int tmp1 = data / 10000;
                int tmp2 = data % 10;
                if(tmp1 != tmp2) {
                    printf("no\n");
                    continue;
                }
                data -= tmp1 * 10000;
                data /= 10;                
            }
            case 2:{
                int tmp1 = data / 100;
                int tmp2 = data % 10;
                if(tmp1 == tmp2) printf("yes\n");
                else printf("no\n");
                continue;                
            }
            case 3:{
                int tmp1 = data / 1000;
                int tmp2 = data % 10;
                if(tmp1 != tmp2) {
                    printf("no\n");
                    continue;
                }
                data -= tmp1 * 1000;
                data /= 10;   
            }
            case 1:{
                int tmp1 = data / 10;
                int tmp2 = data % 10;
                if(tmp1 == tmp2) printf("yes\n");
                else printf("no\n");
                continue;
            }
            default:
                printf("no\n");
                continue;
        }
    }
}