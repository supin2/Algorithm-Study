def solution(s):
    lst = []
    
    for ch in s:
        if len(lst) == 0 or lst[-1] != ch:
            lst.append(ch)
        elif lst[-1] == ch:
            lst.pop()
    
    if len(lst) == 0:
        return 1
    else:
        return 0