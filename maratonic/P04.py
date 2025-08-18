N = int(input())
L = int(input())
max_val = L - 1
min_val = -L
vec = [int(i) for i in input().split()]
output = []

sum = 0
vec = sorted(vec)
max_vec = vec[len(vec) - 1]
min_vec = vec[0]

run = True
if N == 1:
    run = False
    if (min_vec < min_val or min_vec > max_val):
        print("N")
    else:
        print("S")
        print(min_vec)
else:
    sum = min_vec + max_vec
    output.append(min_vec)
    output.append(max_vec)
    vec.remove(min_vec)
    vec.remove(max_vec)
    if min_vec + max_vec > max_val or min_vec + max_vec < min_val:
        print("N")
        run = False

while vec != [] and run:
    max_vec = vec[len(vec) - 1]
    min_vec = vec[0]


    if min_vec == max_vec:
        val = min_vec
        if sum + val > max_val or sum + val < min_val:
            print("N")
            break
        else:
            sum += val
            vec.pop()
            output.append(val)
            continue

   
    if sum + min_vec > max_val or sum + min_vec < min_val:
        if sum + max_vec < min_val or sum + max_vec > max_val:
            print("N")
            break
        else:
            sum = sum + max_vec
            output.append(max_vec)
            vec.pop()
    else:
        sum = sum + min_vec
        output.append(min_vec)
        vec.pop(0)
        
        
    
    

        

    

    
if vec == []:
    print("S")
    for i in range(len(output)- 1) :
        print(output[i], end=" ")
    print(output[i + 1])
    

