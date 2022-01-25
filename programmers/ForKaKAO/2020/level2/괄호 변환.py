def isCorrect(s):
    left = right = 0
    flag = True
    st = []
    
    for i in range(len(s)):
        ch = s[i]
        
        if ch == '(':
            left += 1
            st.append('(')
        else:
            right += 1
            if len(st) == 0:
                flag = False
            else:
                st.pop()
        
        if left == right:
            return i + 1, flag
        
    return 0, False
    
    
def solution(p):    
    if len(p) == 0:
        return p
    
    pos, flag = isCorrect(p)
    u = p[:pos]
    v = p[pos:]
    
    if flag:
        return u + solution(v)
    else:
        answer = '(' + solution(v) + ')'
        
        for i in range(1, len(u) - 1):
            if u[i] == '(':
                answer += ')'
            else:
                answer += '('
        
    return answer