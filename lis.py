from itertools import permutations
from collections import OrderedDict


comb = OrderedDict.fromkeys(permutations(("F", "F", "F", "F", "V", "V", "V", "V"), 4))

for i in comb:
    print("(", end="")
    for j in range(len(i)):
        print(i[j], end="")
        if j != len(i) - 1:
            print(", ", end="")
    print(")", end= ", ");