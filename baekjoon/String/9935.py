# 백준 9935번 : 문자열 폭발

if __name__ == "__main__":
    string = input()
    bomb = input()
    lst = []

    for ch in string:
        lst.append(ch)
        if ch == bomb[-1] and ''.join(lst[-len(bomb):]) == bomb:
            del lst[-len(bomb):]
    
    ans = ''.join(lst)

    if ans == '':
        print("FRULA")
    else:
        print(ans)