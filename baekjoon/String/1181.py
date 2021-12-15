# 백준 1181번 : 단어 정렬
if __name__ == "__main__":
    N = int(input())
    lst = []

    for _ in range(N):
        lst.append(input())

    st = set(lst)
    lst = list(st)

    lst.sort()
    lst.sort(key = len)

    for i in lst:
        print(i)