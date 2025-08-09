n, k = [int(i) for i in input().split()]
inteiros = [int(i) for i in input().split()]

hash_map_janela = {}

for j in range(k):
    if inteiros[j] not in hash_map_janela:
        hash_map_janela[inteiros[j]] = 1
    else:
        hash_map_janela[inteiros[j]] += 1

numeros_distintos = len(hash_map_janela)
print(f"{numeros_distintos}", end=" ")

for i in range(k, n):
    numero_antigo = inteiros[i - k]
    hash_map_janela[numero_antigo] -= 1
    if hash_map_janela[numero_antigo] == 0:
        del hash_map_janela[numero_antigo]

    hash_map_janela[inteiros[i]] = hash_map_janela.get(inteiros[i], 0) + 1

    numeros_distintos = len(hash_map_janela)
    if i == n - 1:
        print(f"{numeros_distintos}")
    else:
        print(f"{numeros_distintos} ", end="")
