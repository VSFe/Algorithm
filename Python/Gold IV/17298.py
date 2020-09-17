track = []
size = int(input())
data = list(map(int, input().split(' ')))
data.reverse()

for i in range(len(data)):
    prev = i - 1
    while(True):
        if prev < 0:
            track.append(-1)
            break
        elif data[prev] > data[i]:
            track.append(prev)
            break
        elif data[prev] == -1:
            track.append(-1)
            break
        else:
            prev = track[prev]

track.reverse()

for i in track:
    if i == -1:
        print(-1, end = ' ')
    else:
        print(data[i], end = ' ')