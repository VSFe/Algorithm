/*
Problem: LCS 3 (1958)
Tier: Gold 3
Comment: 평-범한 3차원
*/

#include <iostream>
using namespace std;

string data[3];
int lcs[101][101][101];

int main() {
    for(int i = 0; i < 3; i++) cin >> data[i];
    int X = data[0].size(), Y = data[1].size(), Z = data[2].size();

    for(int i = 1; i <= X; i++) {
        for(int j = 1; j <= Y; j++) {
            for(int k = 1; k <= Z; k++) {
                if(data[0][i - 1] == data[1][j - 1] && data[1][j - 1] == data[2][k - 1]) {
                    lcs[i][j][k] = lcs[i - 1][j - 1][k - 1] + 1;
                } else {
                    lcs[i][j][k] =  max(max(lcs[i - 1][j][k], lcs[i][j - 1][k]), lcs[i][j][k - 1]);
                }
            }
        }
    }

    cout << lcs[X][Y][Z];
}