import heapq

if __name__ == '__main__':
    heap = []
    inp = "4 3 2 6"
    costarr = []
    for elem in inp.split(" "):
        heapq.heappush(heap, int(elem))
    while heap:
            num1 = heapq.heappop(heap)
            try:
                num2 = heapq.heappop(heap)
            except:
                break;
            cost = num1 * num2
            heapq.heappush(heap, cost)
            costarr.append(cost)
    cost = 0
    for elem in costarr:
        cost+=elem
    print cost
