# 백준 1755번 : 숫자놀이
if __name__ == "__main__":
    dic = {'1':'one', '2':'two', '3':'three', '4':'four', '5':'five', '6':'six', '7':'seven', '8':'eight', '9':'nine', '0':'zero'}
    M, N = map(int, input().split())

    lst = []
    for i in range(M, N + 1):
        s = ' '.join([dic[c] for c in str(i)])
        lst.append([i, s])
    lst.sort(key=lambda x:x[1])
    for idx in range(len(lst)):
        if idx != 0 and idx % 10 == 0:
            print()
        print(lst[idx][0], end=' ')