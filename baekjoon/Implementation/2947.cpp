// 백준 2947번 : 나무 조각
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    vector<int> v(5);

    for (int i = 0; i < 5; i++) {
        cin >> v[i];
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4 - i; j++) {
            if (v[j] > v[j + 1]) {
                int tmp = v[j + 1];
                v[j + 1] = v[j];
                v[j] = tmp;
                for (int k = 0; k < 5; k++) {
                    cout << v[k] << ' ';
                }
                cout << '\n';
            }
        }
    }
    return 0;
}