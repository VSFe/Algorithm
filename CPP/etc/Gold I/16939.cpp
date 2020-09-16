#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int cube[6][4];
vector<vector<pair<int, int>>> direc(6);

bool is_correct() {
    for(int i = 0; i < 6; i++) {
        int st = cube[i][0];
        for(int j = 1; j < 4; j++) {
            if(st != cube[i][j]) return false;
        }
    }
    return true;
}

void rotate(int idx, bool front) {
    if(front) {
        for(int i = 3; i > 0; i--) {
            int x = direc[idx][i].first - 1, y = direc[idx][i].second - 1;
            int X = direc[idx][i - 1].first - 1, Y = direc[idx][i - 1].second - 1;
            swap(cube[x/4][x%4], cube[X/4][X%4]);
            swap(cube[y/4][y%4], cube[Y/4][Y%4]);
        }
    } else {
        for(int i = 0; i < 3; i++) {
            int x = direc[idx][i].first - 1, y = direc[idx][i].second - 1;
            int X = direc[idx][i + 1].first - 1, Y = direc[idx][i + 1].second - 1;
            swap(cube[x/4][x%4], cube[X/4][X%4]);
            swap(cube[y/4][y%4], cube[Y/4][Y%4]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    for(int i = 0; i < 6; i++)
        for(int j = 0; j < 4; j++)
            cin >> cube[i][j];

    direc[0] = {{13, 14}, {5, 6}, {17, 18}, {21, 22}};
    direc[1] = {{15, 16}, {7, 8}, {19, 20}, {23, 24}};
    direc[2] = {{1, 3}, {5, 7}, {9, 11}, {24, 22}};
    direc[3] = {{2, 4}, {6, 8}, {10, 12}, {23, 21}};
    direc[4] = {{3, 4}, {17, 19}, {10, 9}, {16, 14}};
    direc[5] = {{1, 2}, {18, 20}, {12, 11}, {15, 13}};

    bool answer = false;

    for(int i = 0; i < 6; i++) {
        rotate(i, 0);
        if(is_correct()) {
            answer = true;
            break;
        }
        rotate(i, 1);
        rotate(i, 1);
        if(is_correct()) {
            answer = true;
            break;
        }
        rotate(i, 0);
    }

    cout << answer;
}