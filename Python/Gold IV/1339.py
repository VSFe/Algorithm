import sys

number_reference = [9, 8, 7, 6, 5, 4, 3, 2, 1, 0]
adder = {}
sum_target = []
add_num = int(sys.stdin.readline())
answer = 0

for i in range(add_num):
    input_text = sys.stdin.readline().rstrip()
    for j in range(len(input_text)):
        c = input_text[j]
        adder.setdefault(c, 0)
        adder[c] += 10 ** (len(input_text) - j - 1)

for i in adder.values():
    sum_target.append(i)

sum_target.sort(reverse=True)

for i in range(len(sum_target)):
    answer += sum_target[i] * number_reference[i]

print(answer)
        