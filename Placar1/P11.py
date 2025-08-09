N = int(input())
A = [0]

def find_max_Xor_result(x: int) -> int:
    max_xor = 0
    for a in A:
        result = x ^ a
        if result > max_xor:
            max_xor = result
    return max_xor

for i in range(N):
    command = input()

    number = int(command[1:].strip())

    if command[0] == "+":
        A.append(number)
    elif command[0] == "-":
        A.remove(number)
    elif command[0] == "?":
        print(find_max_Xor_result(number))


