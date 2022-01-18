def solution(phone_book):
    dic = {}
    
    for pb in phone_book:
        dic[pb] = 1
        
    for pb in phone_book:
        temp = ''
        for ch in pb:
            temp += ch
            if temp in dic and temp != pb:
                return False
    return True