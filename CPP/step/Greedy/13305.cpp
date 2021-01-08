#include <iostream>
#include <vector>
using namespace std;

long long answer = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N; cin >> N;
    vector<long long> length(N - 1);
    vector<long long> price(N);

    for(int i = 0; i < N - 1; i++) cin >> length[i];
    for(int i = 0; i < N; i++) cin >> price[i];
    
    for(int i = 0, j = 0; i < N - 1;) {
        while(j < N - 1 && price[i] <= price[j]) {
            answer += length[j] * price[i];
            j++;
        }
        i = j;
    }

    cout << answer;
}