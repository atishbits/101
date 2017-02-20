#https://www.hackerearth.com/practice/algorithms/searching/binary-search/practice-problems/algorithm/timely-orders/
#returns the index of the element just larger than or equal to REQ
def binsearch(arr, start, end, req):
    mid = (start + end)/2
    if arr[mid][1] == req:
        return mid
    if arr[mid][1] > req:
        if arr[mid-1][1] < req:
            return mid
        else:
            return binsearch(arr, start, mid-1, req)
    elif arr[mid][1] < req:
            return binsearch(arr, mid+1, end, req)

def cal_weight(arr, start, sum_arr):
    print "arr:", arr, sum_arr
    print "start time", start
    if (start < arr[0][1]):
        index = 0
    elif start > arr[len(arr) - 1][1]: #start time is out of DB range
        return 0
    else:
        index = binsearch(arr, 0, len(arr) -1, start)
    if index == 0:
        return sum_arr[len(arr) - 1]
    return sum_arr[len(arr) - 1] - sum_arr[index-1]

if __name__ == "__main__":
    Q = int(raw_input())
    arr = []
    sum_arr = []
    sumw = 0
    while(Q):
        query = raw_input().split()
        if query[0] == "1":
            arr.append((int(query[1]), int(query[2])))
            sumw += int(query[1])
            sum_arr.append(sumw)
        elif query[0] == "2":
            K = int(query[1])
            T = int(query[2])
            print cal_weight(arr, T-K, sum_arr)
        Q -= 1
