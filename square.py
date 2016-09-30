#https://www.hackerearth.com/practice/algorithms/searching/binary-search/practice-problems/algorithm/square-transaction-20/
#1 2 1 3 4
#[1, 3, 4, 7, 11]
def getsum(arr):
    sums = []
    csum = 0
    for elem in arr:
        elem = int(elem)
        csum += elem
        sums.append(csum)
    return sums
        
def binsearch(arr, start, end, req):
    mid = (start + end)/2
    if arr[mid] == req:
        return mid
    if arr[mid] > req:
        if arr[mid-1] < req:
            return mid
        else:
            return binsearch(arr, start, mid-1, req)
    elif arr[mid] < req:
            return binsearch(arr, mid+1, end, req)

if __name__ == "__main__":
    T = int(raw_input())
    arr = raw_input().split()
    sum_arr = getsum(arr)
    print sum_arr
    Q = int(raw_input())
    while (Q):
        req = int(raw_input())
        if sum_arr[len(sum_arr)-1] < req:
            print -1
        elif sum_arr[0] > req:
            print 1
        else:
            print ((binsearch(sum_arr, 0, len(sum_arr) - 1, req)) + 1)
        Q -= 1
