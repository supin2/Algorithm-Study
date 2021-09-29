// 백준 14890번 : 경사로
#include <iostream>

using namespace std;

int main() {
    int N, L, ans = 0;
    cin >> N >> L;
    
    int arr[200][100] = { 0, };
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            arr[i + N][j] = arr[j][i];
        }
    }
    
    for (int i = 0; i < 2*N; i++) {
        int cnt = 1;
        bool flag = true;
        for (int j = 0; j < N - 1; j++) {
            if (arr[i][j] == arr[i][j + 1]) {
                cnt++;
            } else if (arr[i][j] - arr[i][j + 1] == -1) {
                if (cnt < L) {
                    flag = false;
                    break;
                } else {
                    cnt = 1;
                }
            } else if (arr[i][j] - arr[i][j + 1] == 1) {
                if (cnt < 0) {
                    flag = false;
                    break;
                } else {
                    cnt = -L + 1;
                }
            } else {
                flag = false;
                break;
            }
        }
        if (flag && cnt >= 0) {
            ans++;
        }
    }
    cout << ans;
    return 0;
}