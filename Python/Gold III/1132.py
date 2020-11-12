import sys

cnt = int(input())
chars = [[0, chr(i + ord('A')), False] for i in range(10)]
numbers = [i for i in range(10)]
answer = 0
idx = 0

for _ in range(cnt):
    text = sys.stdin.readline().rstrip()
    for i in range(len(text)):
        c = ord(text[i]) - ord('A')
        chars[c][0] += 10 ** (len(text) - i - 1)
        if i == 0: chars[c][2] = 1

chars.sort()

for data in chars:
    if numbers[idx] == 0 and data[0] != 0 and data[2] == True:
        answer += numbers[idx + 1] * data[0]
        numbers[idx + 1] = 0
        idx += 1
    else:
        answer += numbers[idx] * data[0]
        idx += 1

print(answer)
