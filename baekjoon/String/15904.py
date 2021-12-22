# 백준 15904번 : UCPC는 무엇의 약자일까?
if __name__ == "__main__":
    text = input()
    lst = ['U', 'C', 'P', 'C']
    isExist = True

    for idx in range(len(lst)):
        if lst[idx] in text:
            isExist = True
            pos = text.find(lst[idx])
            text = text[pos + 1:]
        else:
            isExist = False
            break

    if isExist == True:
        print("I love UCPC")
    else:
        print("I hate UCPC")