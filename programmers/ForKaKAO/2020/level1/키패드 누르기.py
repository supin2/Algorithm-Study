def solution(numbers, hand):
    answer = ''
    
    dic = {
        1: [0, 0], 2: [0, 1], 3: [0, 2],
        4: [1, 0], 5: [1, 1], 6: [1, 2],
        7: [2, 0], 8: [2, 1], 9: [2, 2],
        '*': [3, 0], 0: [3, 1], '#': [3, 2]
    }
    
    lpos = dic['*']
    rpos = dic['#']
    
    for num in numbers:
        now = dic[num]
        
        if num in [1, 4, 7]:
            answer += 'L'
            lpos = dic[num]
        elif num in [3, 6, 9]:
            answer += 'R'
            rpos = dic[num]
        else:
            ltmp = rtmp = 0
            for a, b, c in zip(lpos, rpos, now):
                ltmp += abs(a - c)
                rtmp += abs(b - c)
            
            if ltmp < rtmp:
                answer += 'L'
                lpos = dic[num]
            elif ltmp > rtmp:
                answer += 'R'
                rpos = dic[num]
            else:
                if hand == "left":
                    answer += 'L'
                    lpos = dic[num]
                else:
                    answer += 'R'
                    rpos = dic[num]
                
    return answer