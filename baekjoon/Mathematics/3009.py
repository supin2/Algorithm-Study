# 백준 3009번 : 네 번째 점
if __name__ == "__main__":
    x_ = []
    y_ = []
    for _ in range(3):
        x, y = map(int, input().split())
        x_.append(x)
        y_.append(y)

    for i in range(3):
        if x_.count(x_[i]) == 1:
            retX = x_[i]
        if y_.count(y_[i]) == 1:
            retY = y_[i]

    print(retX, retY)
