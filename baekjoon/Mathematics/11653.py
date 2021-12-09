# 백준 11653번 : 소인수분해
if __name__ == "__main__":
    N = int(input())

    # while N != 1:
    #     for i in range(2, N + 1):
    #         if N % i == 0:
    #             print(i)
    #             N = N // i
    #             break
    
    i = 2
    while i * i <= N:
        while not N % i:
            print(i)
            N = N // i
        i += 1

    if N > 1:
        print(N)
