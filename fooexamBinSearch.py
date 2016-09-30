#https://www.hackerearth.com/practice/algorithms/searching/binary-search/practice-problems/algorithm/foo-and-exams-4/

def func(A, B, C, D, t):
    return A*pow(t, 3) + B*pow(t, 2) + C*t + D

def do_recurr(A, B, C, D, st, t, K):
    stress_t = func(A, B, C, D, t)
    stress_t1 = func(A, B, C, D, t+1)
    print stress_t, stress_t1, t
    if stress_t <= K and stress_t1 > K:
        return t
    elif stress_t < K: #can take more stress
        return do_recurr(A, B, C, D, t, (t+t*2)/2, K)
    else: #needs lower stress
        return do_recurr(A, B, C, D, st, (st+t)/2, K)

if __name__ == "__main__":
    T = int(raw_input())
    while(T):
        in_arr = raw_input().split()
        A = int(in_arr[0])
        B = int(in_arr[1])
        C = int(in_arr[2])
        D = int(in_arr[3])
        K = int(in_arr[4])
        T -= 1
        #select a random t
        t = K
        print do_recurr(A, B, C, D, 0, t, K)
