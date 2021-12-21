# 백준 1302번 : 베스트셀러
if __name__ == "__main__":
    N = int(input())
    books = {}

    for _ in range(N):
        book = input()
        if book not in books:
            books[book] = 1
        else:
            books[book] += 1

    maxCnt = max(books.values())
    lst = []

    for title, cnt in books.items():
        if cnt == maxCnt:
            lst.append(title)
    
    print(sorted(lst)[0])