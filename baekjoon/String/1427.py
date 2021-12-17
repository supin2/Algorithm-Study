# 백준 1427번 : 소트인사이드
if __name__ == "__main__":
    N = str(input())
    lst = []

    for ch in N:
        lst.append(ch)

    lst.sort(reverse=True)

    for ch in lst:
        print(ch, end='') 