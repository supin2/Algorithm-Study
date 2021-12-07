# 백준 5355번 : 화성 수학

if __name__ == "__main__":
    T = int(input())
    for _ in range(T):
        expr = list(map(str, input().split()))
        ans = 0
        for i in range(len(expr)):
            if i == 0:
                ans += float(expr[i])
            else:
                if expr[i] == '@':
                    ans *= 3
                elif expr[i] == '%':
                    ans += 5
                elif expr[i] == '#':
                    ans -= 7
        print("%0.2f" % ans)