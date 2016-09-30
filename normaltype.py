#https://www.hackerearth.com/practice/algorithms/searching/linear-search/practice-problems/algorithm/the-normal-type/
#1 2 2 1 1
#algorithm: 1. Count number of actual_uniq elements (linear time) 2. Start a sliding window: a) if uniq_window == actual_uniq then result += len(arr) - curr_pos and slide the window forward b) else grow the window until a) is true -- repeat until we reach end of array. (linear time)
import sys
if __name__ == "__main__":
    N = int(raw_input())
    ints = raw_input()
    arr = ints.split()
    elems = {}
    result = 0
    for elem in arr:
        if elem not in elems:
            elems[elem] = True
    uniq_elem = len(elems)
    if uniq_elem == 1:
        print len(arr)*(len(arr) + 1)/2
        sys.exit(0)
    start_i = 0
    curr_i = 0
    elems = {}
    uniq = 0
    result = 0
    start = arr[start_i]
    while(curr_i != len(arr) - 1):
        curr = arr[curr_i]
        if curr not in elems or elems[curr] == 0:
            elems[curr] = 1
            uniq += 1
            while uniq == uniq_elem:
                elems[start] -= 1
                if elems[start] == 0:
                    uniq -= 1
                start_i += 1
                start = arr[start_i]
                result += (len(arr) - curr_i)
        else:
            elems[curr] += 1
        curr_i += 1
    print result 
