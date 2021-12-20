# 백준 11656번 : 접미사 배열
if __name__ == "__main__":
    S = str(input())
    lst = []

    for i in range(len(S)):
        lst.append(S[i:])
    
    lst.sort()

    for s in lst:
        print(s)