#include <iostream>
#include <vector>
using namespace std;

const int MAX = 10001;

int main() {
    vector<int> prime;
    bool is_prime[MAX];
    fill(is_prime+2, is_prime+MAX, true);
    for(int i = 4; i <= MAX; i += 2) is_prime[i] = false;
    for(int i = 2; i <= MAX; i++) {
        if(!is_prime[i]) continue;
        prime.push_back(i);
        for(int j = i * i; j <= MAX; j += i * 2) is_prime[j] = false;
    }
    for(int i = 0; i < prime.size(); i++) {
        cout << prime[i] << ' ';
        if(i%10 == 9 || i == prime.size() - 1) cout << '\n';
    }
}