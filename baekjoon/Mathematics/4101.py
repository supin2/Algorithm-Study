# 백준 4101번 : 크냐?
if __name__ == "__main__":
    while True:
        a, b = map(int, input().split())
        if a == 0 and b == 0 :
            break

        if a > b :
            print("Yes")
        else :
            print("No")