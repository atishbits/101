# ABBA
# AABB
# if consecutive positions of A are apart by even number of positions then word is bubbly2
import pdb

def isBubbly(word):
    arr_A = []
    for i in range(len(word)):
        if word[i] == 'A':
            arr_A.append(i)
    if len(arr_A) == 0:
        return True
    if len(arr_A)%2 != 0:
        return False
    prev = -1
    for i in range(0, len(arr_A)):
        curr = arr_A[i]
        if prev == -1:
            prev = arr_A[i]
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
        #word = "AABAAAAAABAAAA"
        if len(word)%2 != 0:
            continue
        if(isBubbly(word)):
            num_bubs += 1
        else:
            print word, "false"
    print num_bubs
