# 백준 10156번 : 과자
if __name__ == "__main__":
    K, N, M = map(int, input().split())
    total = K*N

    if total > M:
        print(total - M)
    else:
        print(0)