/*
Problem: sqrt log sin(4172)
Tier: Silver 2
Detail: 
Comment:` 아 귀찮아
*/

#include <stdio.h>
#include <cmath>
using namespace std;

int x[1000001] = {1};

int main(){
    for(int i=1;i<=1000000;++i){
        x[i] = x[(int)(i-sqrt(i))];
        x[i] = (x[i] + x[(int)log(i)]) % 1000000;
        x[i] = (x[i] + x[(int)(i*sin(i)*sin(i))]) % 1000000;
    }
    while(true){
        int n;
        scanf("%d",&n);
        if(n==-1) break;
        printf("%d\n",x[n]);
    }
    return 0;
}