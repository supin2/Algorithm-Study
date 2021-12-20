# 백준 1543번 : 문서 검색
if __name__ == "__main__":
    text = str(input())
    pattern = str(input())
    txtLen = len(text)
    ptnLen = len(pattern)
    i = ans = 0

    while i <= txtLen - ptnLen:
        cmp = text[i:i + ptnLen]
        if cmp == pattern:
            ans += 1
            i += ptnLen
        else:
            i += 1
    
    print(ans)