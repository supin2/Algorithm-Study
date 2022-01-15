def solution(lottos, win_nums):
    answer = []
    rank = [ 6, 6, 5, 4, 3, 2, 1 ]
    zero = cnt = 0

    for l in lottos:
        if l == 0:
            zero += 1
        else:
            if l in win_nums:
                cnt += 1
    
    return rank[zero + cnt], rank[cnt]