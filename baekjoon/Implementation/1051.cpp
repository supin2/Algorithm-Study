// 백준 1051번 : 숫자 정사각혁
#include <iostream>

using namespace std;

int main() {
    int N, M, ans = 1;
    cin >> N >> M;

    int arr[51][51];

    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < M; j++) {
            arr[i][j] = str[j] - '0';
        }
    }
    int scope = N > M ? M : N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int cnt = 1;
            int corner = arr[i][j];

            while (cnt < scope) {
                if (i + cnt < N && j + cnt < M) {
                    if (corner == arr[i][j + cnt] && corner == arr[i + cnt][j] && corner == arr[i + cnt][j + cnt]) {
                        ans = max(ans, cnt + 1);
                    }
                }
                cnt++;
            }
        }
    }
    cout << ans * ans;
    return 0;
}