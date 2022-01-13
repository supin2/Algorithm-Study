def solution(s):
    lst = []
    words = s.split(' ')
    
    for word in words:
        answer = ""
        for i in range(len(word)):
            answer += word[i].upper() if i % 2 == 0 else word[i].lower()
            
        lst.append(answer)
    return " ".join(lst)