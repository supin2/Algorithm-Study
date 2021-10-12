// 백준 14697번 : 방 배정하기
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int A, B, C, N;
    cin >> A >> B >> C >> N;

    for (int i = 0; i <= N/A; i++) {
        for (int j = 0; j <= N/B; j++) {
            for (int k = 0; k <= N/C; k++) {
                if (A*i + B*j + C*k == N) {
                    cout << 1;
                    return 0;
                }
            }
        }
    }
    cout << 0;
    return 0;
}