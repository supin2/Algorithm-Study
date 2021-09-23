#include <string>
#include <vector>
#include <iostream>

using namespace std;

#define INF 987654321

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    int arr[101][101];
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) {
                arr[i][j] = 0;
            } else {
                arr[i][j] = INF;
            }
        }
    }
    for (auto r : results) {
        arr[r[0]][r[1]] = 1;
    }
    
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (arr[i][j] > arr[i][k] + arr[k][j]) {
                    arr[i][j] = arr[i][k] + arr[k][j];
                }
            }
        }
    }
    
    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        for (int j = 1; j <= n; j++) {
            if (i == j) {
                continue;
            } else {
                if (arr[i][j] != INF || arr[j][i] != INF) {
                    cnt++;
                }
            }
        }
        if (cnt == n - 1) {
            answer++;
        }
    }
    return answer;
}