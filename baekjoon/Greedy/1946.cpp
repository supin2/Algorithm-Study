// 백준 1946번 : 신입 사원
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int T;
    vector<pair<int, int>> v;

    cin >> T;

    while (T--) {
        int apply;
        cin >> apply;

        for (int i = 0; i < apply; i++) {
            int s1, s2;
            cin >> s1 >> s2;
            v.push_back(make_pair(s1, s2));
        }
        sort(v.begin(), v.end());
        int ans = 1;
        int rank = v[0].second;

        for (int i = 1; i < apply; i++) {
            if (rank > v[i].second) {
                ans++;
                rank = v[i].second;
            }
        }
        v.clear();
        cout << ans << '\n';
    }
    return 0;
}