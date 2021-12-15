# 백준 1316번 : 그룹 단어 체커
if __name__ == "__main__":
    N = int(input())
    ans = N

    for _ in range(N):
        word = str(input())
        for i in range(len(word) - 1):
            if word[i] == word[i + 1]:
                pass
            else:
                if word[i] in word[i + 1:]:
                    ans -= 1
                    break
    print(ans)
