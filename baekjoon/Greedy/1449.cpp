// 백준 1449번 : 수리공 항승
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, L, ans = 0;
    cin >> N >> L;

    vector<int> hole(N);
    bool fixed[1001] = { false, };

    for (int i = 0; i < N; i++) {
        cin >> hole[i];
    }
    sort(hole.begin(), hole.end());

    for (int i = 0; i < N; i++) {
        if (!fixed[hole[i]]) {
            for (int j = hole[i]; j < min(hole[i] + L, 1001); j++) {
                fixed[j] = true;
            }
            ans++;
        }
    }
    cout << ans << '\n';
    return 0;
}