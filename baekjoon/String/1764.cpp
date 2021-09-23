// 백준 1764번 : 듣보잡
#include <iostream>
#include <map>

using namespace std;

int main() {
    int N, M, ans = 0;
    map<string, int> m;
    string name = "";

    cin >> N >> M;
    while (N--) {
        cin >> name;
        m[name]++;
    }
    while (M--) {
        cin >> name;
        m[name]++;
        if (m[name] >= 2) {
            ans++;
        }
    }
    cout << ans << '\n';
    for (auto it : m) {
        if (it.second >= 2) {
            cout << it.first << '\n';
        }
    }
    return 0;
}