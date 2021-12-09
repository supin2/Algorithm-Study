# 백준 5717번 : 상근이의 친구들
if __name__ == "__main__":
    while True:
        M, F = map(int, input().split())

        if M == 0 and F == 0:
            break
        
        print(M + F)