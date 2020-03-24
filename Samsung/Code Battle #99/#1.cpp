#include <iostream>
using namespace std;
int t;
float p, q;
int main() {
    scanf("%d", &t);
    for(int i = 0; i < t; i++) {
        scanf("%f %f", &p, &q);
        if((1-p) * q < p * q * (1 - q)) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
} 