// 백준 1244번 : 스위치 켜고 끄기
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, T;
    cin >> N;
    vector<int> sw(N);
    
    for (int i = 0; i < N; i++) {
        cin >> sw[i];
    }
    cin >> T;
    
    while (T--) {
        int a, b;
        cin >> a >> b;
        
        if (a == 1) {
            for (int i = 0; i < N; i++) {
                if ((i + 1) % b == 0) {
                    sw[i] = sw[i] == 1 ? 0 : 1;
                }
            }
        } else {
            int cnt = 1;
            int idx = b - 1;
            while (true) {
                if (idx - cnt >= 0 && idx + cnt < N) {
                    if (sw[idx - cnt] == sw[idx + cnt]) {
                        cnt++;
                    } else {
                        cnt--;
                        break;
                    }
                } else {
                    cnt--;
                    break;
                }
            }
            for (int i = idx - cnt; i <= idx + cnt; i++) {
                sw[i] = sw[i] == 1 ? 0 : 1;
            }
        }
    }
    for (int i = 0; i < N; i++) {
        cout << sw[i] << ' ';
        if ((i + 1) % 20 == 0) {
            cout << '\n';
        }
    }
    return 0;
}