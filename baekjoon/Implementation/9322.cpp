// 백준 9322번 : 철벽 보안 알고리즘
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int N;
        string str;
        map<string, pair<int, int>> m;
        string arr[1000];
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> str;
            m[str] = make_pair(i, i);
        }
        for (int i = 0; i < N; i++) {
            cin >> str;
            int tmp = m[str].first;
            m[str] = make_pair(tmp, i);
        }
        for (int i = 0; i < N; i++) {
            cin >> str;
            for (auto it = m.begin(); it != m.end(); it++) {
                if (it->second.second == i) {
                    arr[it->second.first] = str;
                }
            }
        }

        for (int i = 0; i < N; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}