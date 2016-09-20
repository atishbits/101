# 1. ABBA
# 2. AABB
# 3. ABAABAAAAAAAAA
# if consecutive positions of A are apart by even number of positions then word is bubbly --- no this logic does not work for example #3.
import pdb

def isBubbly(word):
    arr_A = []
    arr_B = []
    for i in range(len(word)):
        if word[i] == 'A':
            arr_A.append(i)
        if word[i] == 'B':
            arr_B.append(i)
    if len(arr_A) == 0:
        return True
    if len(arr_A)%2 != 0:
        return False
    prev = -1
    check_B = False
    for i in range(0, len(arr_A)):
        curr = arr_A[i]
        if prev == -1:
            prev = arr_A[i]
            continue
        if (curr-prev)%2 != 0:
            prev = -1
            continue
        else:
            check_B = True
            break
    prev = -1
    if(not check_B):
        return True
    for i in range(0, len(arr_B)):
        curr = arr_B[i]
        if prev == -1:
            prev = arr_B[i]
            continue
        if (curr-prev)%2 != 0:
            prev = -1
            continue
        else:
            return False
    return True
    
if __name__ == "__main__":
    M = int(raw_input())
    #M = 1
    num_bubs = 0
    for i in range(M):
        word = raw_input()
        #word = "ABAABAAAAAAAAA"
        if len(word)%2 != 0:
            continue
        if(isBubbly(word)):
            num_bubs += 1
            print word, "True"
        else:
            print word, "False"
    print num_bubs
