def solution(s):
    answer = len(s)
    
    for i in range(1, int(len(s)/2) + 1):
        pos = 0
        compress = len(s)
        
        while pos + i <= len(s):
            unit = s[pos:pos + i]
            pos += i
            cnt = 0
            
            while pos + i <= len(s):
                if unit == s[pos:pos + i]:
                    cnt += 1
                    pos += i
                else:
                    break
            
            if cnt > 0:
                compress -= i * cnt
                
                if cnt < 9:
                    compress += 1
                elif cnt < 99:
                    compress += 2
                elif cnt < 999:
                    compress += 3
                else:
                    compress += 4
                    
        answer = min(answer, compress)
                    
    return answer