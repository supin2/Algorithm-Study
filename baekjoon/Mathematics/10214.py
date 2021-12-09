# 백준 10214번 : Baseball
if __name__ == "__main__":
    T = int(input())

    for _ in range(T):
        Y = K = 0
        for _ in range(9):
            num1, num2 = map(int, input().split())

            Y += num1
            K += num2
        
        if Y > K:
            print("Yonsei")
        elif Y < K:
            print("Korea")
        else:
            print("Draw")