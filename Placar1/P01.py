from itertools import combinations

n, k = [int(i) for i in input().split()]
Primos = [int(i) for i in input().split()]

n_divisores = 0
for i in range(1, k + 1):
    for j in combinations(Primos, i):
        produto = -1

        for p in j:
            produto *= (-1) * p
            if abs(produto) > n:
                break
        if abs(produto) > n:
            continue
        if produto < 0:
            produto = -produto
            n_divisores -= n // produto
        else:
            n_divisores += n // produto

print(n_divisores)
