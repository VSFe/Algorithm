/*
Problem: 큐빙 (5373)
Tier: Gold 1
Detail:  루빅스 큐브는 삼차원 퍼즐이다. 보통 루빅스 큐브는 3×3×3개의 작은 정육면체로 이루어져 있다. 퍼즐을 풀려면 각 면에 있는 아홉 개의 작은 정육면체의 색이 동일해야 한다.
큐브는 각 면을 양방향으로 90도 만큼 돌릴 수 있도록 만들어져 있다. 회전이 마친 이후에는, 다른 면을 돌릴 수 있다. 이렇게 큐브의 서로 다른 면을 돌리다 보면, 색을 섞을 수 있다.
이 문제에서는 루빅스 큐브가 모두 풀린 상태에서 시작한다. 윗 면은 흰색, 아랫 면은 노란색, 앞 면은 빨간색, 뒷 면은 오렌지색, 왼쪽 면은 초록색, 오른쪽 면은 파란색이다.
루빅스 큐브를 돌린 방법이 순서대로 주어진다. 이때, 모두 돌린 다음에 가장 윗 면의 색상을 구하는 프로그램을 작성하시오.
Comment: 미친구현 살려주세요
*/

#include <iostream>
#include <string>
using namespace std;

char textSet[6] = {'w', 'r', 'b', 'o', 'g', 'y'};

void rotate(char cube[6][3][3], int pos, char direc) {
    char tmp[3];
    if(direc == '+') {
        for(int i = 0; i < 3; i++) tmp[i] = cube[pos][0][i];
        for(int i = 0; i < 3; i++) cube[pos][0][2 - i] = cube[pos][i][0];
        for(int i = 0; i < 3; i++) cube[pos][i][0] = cube[pos][2][i];
        for(int i = 0; i < 3; i++) cube[pos][2][i] = cube[pos][2 - i][2];
        for(int i = 0; i < 3; i++) cube[pos][i][2] = tmp[i];
    } else {
        for(int i = 0; i < 3; i++) tmp[i] = cube[pos][0][i];
        for(int i = 0; i < 3; i++) cube[pos][0][i] = cube[pos][i][2];
        for(int i = 0; i < 3; i++) cube[pos][i][2] = cube[pos][2][2 - i];
        for(int i = 0; i < 3; i++) cube[pos][2][2 - i] = cube[pos][2 - i][0];
        for(int i = 0; i < 3; i++) cube[pos][i][0] = tmp[2 - i];
    }
}

void solve(char cube[6][3][3], char pos, char direc) {
    char tmp[3];
    if(pos == 'U') {
        if(direc == '+') {
            for(int i = 0; i < 3; i++) tmp[i] = cube[1][0][i];
            for(int i = 0; i < 3; i++) cube[1][0][i] = cube[2][0][i];
            for(int i = 0; i < 3; i++) cube[2][0][i] = cube[3][0][i];
            for(int i = 0; i < 3; i++) cube[3][0][i] = cube[4][0][i];
            for(int i = 0; i < 3; i++) cube[4][0][i] = tmp[i];
        } else {
            for(int i = 0; i < 3; i++) tmp[i] = cube[1][0][i];
            for(int i = 0; i < 3; i++) cube[1][0][i] = cube[4][0][i];
            for(int i = 0; i < 3; i++) cube[4][0][i] = cube[3][0][i];
            for(int i = 0; i < 3; i++) cube[3][0][i] = cube[2][0][i];
            for(int i = 0; i < 3; i++) cube[2][0][i] = tmp[i];
        }
        rotate(cube, 0, direc);
    }
    else if(pos == 'D') {
        if(direc == '+') {
            for(int i = 0; i < 3; i++) tmp[i] = cube[1][2][i];
            for(int i = 0; i < 3; i++) cube[1][2][i] = cube[4][2][i];
            for(int i = 0; i < 3; i++) cube[4][2][i] = cube[3][2][i];
            for(int i = 0; i < 3; i++) cube[3][2][i] = cube[2][2][i];
            for(int i = 0; i < 3; i++) cube[2][2][i] = tmp[i];
        } else {
            for(int i = 0; i < 3; i++) tmp[i] = cube[1][2][i];
            for(int i = 0; i < 3; i++) cube[1][2][i] = cube[2][2][i];
            for(int i = 0; i < 3; i++) cube[2][2][i] = cube[3][2][i];
            for(int i = 0; i < 3; i++) cube[3][2][i] = cube[4][2][i];
            for(int i = 0; i < 3; i++) cube[4][2][i] = tmp[i];
        }
        rotate(cube, 5, direc);
    }    
    else if(pos == 'F') {
        if(direc == '+') {
            for(int i = 0; i < 3; i++) tmp[i] = cube[0][2][i];
            for(int i = 0; i < 3; i++) cube[0][2][i] = cube[4][2 - i][2];
            for(int i = 0; i < 3; i++) cube[4][i][2] = cube[5][0][i];
            for(int i = 0; i < 3; i++) cube[5][0][i] = cube[2][2 - i][0];
            for(int i = 0; i < 3; i++) cube[2][i][0] = tmp[i];
        } else {
            for(int i = 0; i < 3; i++) tmp[i] = cube[0][2][i];
            for(int i = 0; i < 3; i++) cube[0][2][i] = cube[2][i][0];
            for(int i = 0; i < 3; i++) cube[2][i][0] = cube[5][0][2 - i];
            for(int i = 0; i < 3; i++) cube[5][0][i] = cube[4][i][2];
            for(int i = 0; i < 3; i++) cube[4][i][2] = tmp[2 - i];
        }
        rotate(cube, 1, direc);
    }  
    else if(pos == 'B') {
        if(direc == '+') {
            for(int i = 0; i < 3; i++) tmp[i] = cube[0][0][i];
            for(int i = 0; i < 3; i++) cube[0][0][i] = cube[2][i][2];
            for(int i = 0; i < 3; i++) cube[2][i][2] = cube[5][2][2 - i];
            for(int i = 0; i < 3; i++) cube[5][2][i] = cube[4][i][0];
            for(int i = 0; i < 3; i++) cube[4][i][0] = tmp[2 - i];
        } else {
            for(int i = 0; i < 3; i++) tmp[i] = cube[0][0][i];
            for(int i = 0; i < 3; i++) cube[0][0][i] = cube[4][2 - i][0];
            for(int i = 0; i < 3; i++) cube[4][i][0] = cube[5][2][i];
            for(int i = 0; i < 3; i++) cube[5][2][i] = cube[2][2 - i][2];
            for(int i = 0; i < 3; i++) cube[2][i][2] = tmp[i];
        }
        rotate(cube, 3, direc);
    }    
    else if(pos == 'R') {
        if(direc == '+') {
            for(int i = 0; i < 3; i++) tmp[i] = cube[0][i][2];
            for(int i = 0; i < 3; i++) cube[0][i][2] = cube[1][i][2];
            for(int i = 0; i < 3; i++) cube[1][i][2] = cube[5][i][2];
            for(int i = 0; i < 3; i++) cube[5][i][2] = cube[3][2 - i][0];
            for(int i = 0; i < 3; i++) cube[3][2 - i][0] = tmp[i];
        } else {
            for(int i = 0; i < 3; i++) tmp[i] = cube[0][i][2];
            for(int i = 0; i < 3; i++) cube[0][i][2] = cube[3][2 - i][0];
            for(int i = 0; i < 3; i++) cube[3][2 - i][0] = cube[5][i][2];
            for(int i = 0; i < 3; i++) cube[5][i][2] = cube[1][i][2];
            for(int i = 0; i < 3; i++) cube[1][i][2] = tmp[i];
        }
        rotate(cube, 2, direc);
    }
    else if(pos == 'L') {
        if(direc == '+') {
            for(int i = 0; i < 3; i++) tmp[i] = cube[0][i][0];
            for(int i = 0; i < 3; i++) cube[0][i][0] = cube[3][2 - i][2];
            for(int i = 0; i < 3; i++) cube[3][2 - i][2] = cube[5][i][0];
            for(int i = 0; i < 3; i++) cube[5][i][0] = cube[1][i][0];
            for(int i = 0; i < 3; i++) cube[1][i][0] = tmp[i];
        } else {
            for(int i = 0; i < 3; i++) tmp[i] = cube[0][i][0];
            for(int i = 0; i < 3; i++) cube[0][i][0] = cube[1][i][0];
            for(int i = 0; i < 3; i++) cube[1][i][0] = cube[5][i][0];
            for(int i = 0; i < 3; i++) cube[5][i][0] = cube[3][2 - i][2];
            for(int i = 0; i < 3; i++) cube[3][2 - i][2] = tmp[i];
        }
        rotate(cube, 4, direc);
    }
}

void solveInput(char cube[6][3][3]) {
    int n; string s;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> s;
        solve(cube, s[0], s[1]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int TC; cin >> TC;
    for(int tc = 0; tc < TC; tc++) {
        char cube[6][3][3];
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                for(int k = 0; k < 6; k++) {
                    cube[k][i][j] = textSet[k];
                }
            }
        }
        solveInput(cube);
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                cout << cube[0][i][j];
            } cout << '\n';
        }
    }
}