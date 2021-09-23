#include <string>
#include <vector>

using namespace std;

#define INF 50000000

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = INF;
    int dist[201][201];
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) {
                dist[i][j] = 0;
            } else {
                dist[i][j] = INF;
            }
        }
    }
    for (auto f : fares) {
        dist[f[0]][f[1]] = f[2];
        dist[f[1]][f[0]] = f[2];
    }
    
    // 플로이드 와샬
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    
    for (int i = 1; i <= n; i++) {
        answer = min(answer, dist[s][i] + dist[i][a] + dist[i][b]);
    }
    
    return answer;
}