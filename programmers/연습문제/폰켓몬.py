def solution(nums):
    answer = 0
    size = len(nums)/2
    st = set(nums)
    
    answer = min(size, len(st))
    
    return answer