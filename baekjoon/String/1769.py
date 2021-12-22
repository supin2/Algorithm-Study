# 백준 1769번 : 3의 배수

def func(num, cnt):
    if len(num) > 1:
        sum = 0
        for ch in num:
            sum += int(ch)
        func(str(sum), cnt + 1)

    elif len(num) == 1:
        if int(num) % 3 == 0:
            print(cnt)
            print("YES")
        else:
            print(cnt)
            print("NO")

if __name__ == "__main__":
    string = str(input())
    func(string, 0)