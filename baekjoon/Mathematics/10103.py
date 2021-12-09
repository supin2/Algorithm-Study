# 백준 10103번 : 주사위 게임
if __name__ == "__main__":
    n = int(input())

    a = b = 100
    for _ in range(n):
        num1, num2 = map(int, input().split())

        if num1 > num2:
            b -= num1
        elif num1 < num2:
            a -= num2

    print(a, b, sep='\n')