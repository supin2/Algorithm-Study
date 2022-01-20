def solution(n, s, a, b, fares):
    INF = 987654321
    answer = INF
    dist = [[INF for _ in range(n)] for _ in range(n)]
    for i in range(n):
        dist[i][i] = 0
    
    for e in fares:
        dist[e[0] - 1][e[1] - 1] = e[2]
        dist[e[1] - 1][e[0] - 1] = e[2]
        
    for k in range(n):
        for i in range(n):
            for j in range(n):
                if dist[i][j] > dist[i][k] + dist[k][j]:
                    dist[i][j] = dist[i][k] + dist[k][j]
    
    s -= 1
    a -= 1
    b -= 1
    
    for k in range(n):
        answer = min(answer, dist[s][k] + dist[k][b] + dist[k][a])
        
    return answer