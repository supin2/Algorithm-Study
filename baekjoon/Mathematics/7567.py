# 백준 7567번 : 그릇
if __name__ == "__main__":
    list = str(input())
    ans = 0

    for i in range(len(list)):
        if i == 0:
            ans += 10
        elif list[i - 1] == list[i]:
            ans += 5
        elif list[i - 1] != list[i]:
            ans += 10

    print(ans)