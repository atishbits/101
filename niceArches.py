#ABBABB
import pdb
def isBubbly(word):
    pdb.set_trace()
    stack = []
    for elem in word:
        if len(stack) > 0:
            top = stack.pop()
            if top == elem:
                continue
            else:
                stack.insert(0, top)
                stack.insert(0, elem)
        else:
            stack.insert(0, elem)
    if len(stack) > 0:
        return False
    else:
        return True

if __name__ == "__main__":
    M = int(raw_input())
    num_bubs = 0
    for i in range(M):
        word = raw_input()
        if len(word)%2 != 0:
            continue
        if(isBubbly(word)):
            num_bubs += 1
    print num_bubs
