def solution(priorities, location):
    answer = 0
    q = [(v, i) for i, v in enumerate(priorities)]
    
    while True:
        item = q.pop(0)
        
        # if q and max(q)[0] > item[0]:
        if any(item[0] < temp[0] for temp in q):
            q.append(item)
        else:
            answer += 1
            if location == item[1]:
                return answer