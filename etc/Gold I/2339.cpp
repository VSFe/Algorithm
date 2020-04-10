/*
Problem: 석판 자르기
Tier: Gold 1
Detail: 하나 이상의 불순물과 보석 결정체로 이루어진 석판을 여러 조각으로 나누어 가공해서, 보다 높은 가치를 얻을 수 있도록 만들려고 한다
 이때, 높은 가치의 석판을 만들기 위해서는 석판을 여러 조각으로 나누되, 각 조각에는 불순물이 없도록 해야하며, 보석 결정체도 단 하나씩만 포함하고 있어야 한다.
또한, 석판에서 불순물을 빼내기 위해서는 불순물을 포함하고 있는 지점을 중심으로 잘라야 되는데, 석판의 결 때문에 가로 또는 세로 방향으로만 석판을 자를 수 있다.
석판을 자를 때에는 이전에 자른 방향과 같은 방향으로는 자를 수 없다. (단, 처음에 자를 때는 가로방향이나, 세로방향 모두 가능하다.)
석판에 있는 불순물과 보석 결정체의 정보가 주어질 때, 이 석판에서 불순물들을 없애면서 석판을 나누되
 각 조각에 반드시 하나의 보석 결정체만이 들어 있도록 석판을 나누는 방법이 모두 몇 가지 존재하는지 계산하시오.
Comment: 조금 골때리는 분할 정복 문제인데, 문제가 너무 모호해서 맞았는데도 찜찜해...
*/

#include <iostream>
using namespace std;

int stone[20][20], N;

int cut(int x_s, int x_e, int y_s, int y_e, int direction) {
    bool is_dust = false;
    int result = 0, cnt_die = 0;
    for(int i = x_s; i <= x_e; i++) {
        for(int j = y_s; j <= y_e; j++) {
            if(stone[i][j] == 1) {
                is_dust = true;
                bool is_row = false, is_column = false;
                if(direction != 1) {
                    for(int k = y_s; k <= y_e; k++) {
                        if(stone[i][k] == 2) {
                            is_row = true;
                            break;
                        }
                    }                    
                }
                else if(direction != 2) {
                    for(int k = x_s; k <= x_e; k++) {
                        if(stone[k][j] == 2) {
                            is_column = true;
                            break;
                        }
                    }                    
                }
                if(!is_row && direction != 1) {
                    int tmp1 = cut(x_s, i-1, y_s, y_e, 1);
                    int tmp2 = cut(i+1, x_e, y_s, y_e, 1);
                    result += (tmp1 * tmp2);
                }
                if(!is_column && direction != 2) {
                    int tmp1 = cut(x_s, x_e, y_s, j-1, 2);
                    int tmp2 = cut(x_s, x_e, j+1, y_e, 2);
                    result += (tmp1 * tmp2);
                }
            }
            if(stone[i][j] == 2) cnt_die++;
        }
    }
    if(cnt_die == 1 & !is_dust) return 1;
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) cin >> stone[i][j];
    }
    int result = cut(0, N-1, 0, N-1, 0);
    if(result == 0) cout << -1; else cout << result;
}
