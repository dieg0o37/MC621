N, M = [int(x) for x in input().split()]
A_n = [int(x) for x in input().split()]
B_n = [int(x) for x in input().split()]

for i in B_n:
    if i in A_n:
        A_n.remove(i)

if A_n != []:
    for j in range(len(A_n)):
        if j == len(A_n) - 1:
            print(A_n[j], end="")
        else:
            print(A_n[j], end=" ")