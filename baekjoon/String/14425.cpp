// 백준 14425번 : 문자열 집합
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N, M, ans = 0;
    map<string, int> m;

    cin >> N >> M;

    string str;
    for (int i = 0; i < N; i++) {
        cin >> str;
        m[str]++;
    }

    for (int i = 0; i < M; i++) {
        cin >> str;
        if (m[str] != 0) {
            ans++;
        }
    }
    cout << ans;
    return 0;
}