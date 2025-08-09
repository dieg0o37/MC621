string = input()

n_diff = 0
for i in range((len(string)//2)):
    if string[i] != string[len(string) - i - 1]:
        n_diff += 1
        if n_diff > 1:
            print("NO")
            break

if n_diff == 1:
    print("YES")

if n_diff == 0 and (len(string) % 2 == 1):
    print("YES")

if n_diff == 0 and (len(string) % 2 == 0):
    print("NO")