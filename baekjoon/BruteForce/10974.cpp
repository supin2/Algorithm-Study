// 백준 10974번 : 모든 순열
#include <iostream>
#include <cstdio>

using namespace std;

int N;
int arr[9], ret[9];
bool visited[9];

void dfs(int idx, int cnt) {
    if (cnt == N) {
        for (int i = 0; i < cnt; i++) {
            printf("%d ", ret[i]);
        }
        printf("\n");
        return;
    }
    
    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            visited[i] = true;
            ret[cnt] = i;
            dfs(1, cnt + 1);
            visited[i] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    scanf("%d", &N);
    
    for (int i = 1; i <= N; i++) {
        arr[i] = i;
    }
    dfs(1, 0);
    
    return 0;
}
