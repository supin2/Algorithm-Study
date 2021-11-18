// 백준 1652번 : 누울 자리를 찾아라
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    vector<string> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    
    int hor = 0, ver = 0;
    for (int i = 0; i < N; i++) {
        int dot = 0;
        for (int j = 0; j < N; j++) {
            if (v[i][j] == '.') {
                dot++;
            }
            if (v[i][j] == 'X' || j == N - 1) {
                if (dot >= 2) {
                    hor++;
                }
                dot = 0;
            }

        }
    }
    for (int i = 0; i < N; i++) {
        int dot = 0;
        for (int j = 0; j < N; j++) {
            if (v[j][i] == '.') {
                dot++;
            }
            if (v[j][i] == 'X' || j == N - 1) {
                if (dot >= 2) {
                    ver++;
                }
                dot = 0;
            }

        }
    }
    cout << hor << ' ' << ver;
    return 0;
}