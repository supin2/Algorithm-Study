# 백준 10886번 : 0 = not cute / 1 = cute
if __name__ == "__main__":
    N = int(input())

    list = []
    for _ in range(N):
        vote = int(input())
        list.append(vote)

    if list.count(0) > list.count(1):
        print("Junhee is not cute!")
    else:
        print("Junhee is cute!")