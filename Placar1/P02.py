from itertools import combinations


N = int(input())
A_n = [int(x) for x in input().split()]
count = 0
possibilities = combinations(range(1, N + 1), 2)
for i, j in possibilities:
    if j - i == A_n[i - 1] + A_n[j - 1]:
        count += 1

print(count)