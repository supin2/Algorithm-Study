def solution(sizes):
    lst = [sorted(size, reverse=True) for size in sizes]
    
    width = [l[0] for l in lst]
    height = [l[1] for l in lst]
    
    return max(width) * max(height)
    