table = []
answer = 0
dx = [1, -1, 0]
dy = [0, 0, 1]

def getPlus(x, y):
    MAX = 0
    tmp = 0
    if x + 2 < N:
        for i in range(3):
            tmp += table[x + i][y]
        if y + 1 < M:
            MAX = max(MAX, tmp + table[x + 1][y + 1])
        if y - 1 >= 0:
            MAX = max(MAX, tmp + table[x + 1][y - 1])
    tmp = 0
    if y + 2 < M:
        for i in range(3):
            tmp += table[x][y + i]
        if x + 1 < N:
            MAX = max(MAX, tmp + table[x + 1][y + 1])
        if x - 1 >= 0:
            MAX = max(MAX, tmp + table[x - 1][y + 1])
    return MAX

def travel(x, y, prev_x, prev_y, remain, adder):
    MAX = 0
    if remain == 0:
        return adder
    for i in range(3):
        if x + dx[i] == prev_x and y + dy[i] == prev_y:
            continue
        if x + dx[i] < 0 or x + dx[i] == N or y + dy[i] == M:
            continue
        MAX = max(MAX, travel(x + dx[i], y + dy[i], x, y, remain - 1, adder + table[x + dx[i]][y + dy[i]]))
    return MAX

N, M = map(int, input().split(' '))

for i in range(N):
    table.append(list(map(int, input().split(' '))))

for i in range(N):
    for j in range(M):
        answer = max(answer, getPlus(i, j))
        answer = max(answer, travel(i, j, i, j, 3, table[i][j]))

print(answer)