// 백준 20920번 : 영단어 암기는 어려워
#include <bits/stdc++.h>

using namespace std;

map<string, int> m;

bool cmp(string str1, string str2) {
    if (m[str1] == m[str2]) {
        if (str1.length() == str2.length()) {
            return str1 < str2;
        }
        return str1.length() > str2.length();
    }
    return m[str1] > m[str2];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, M;
    vector<string> v;
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        if (str.length() < M) {
            continue;
        }
        v.push_back(str);
        m[str]++;
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    sort(v.begin(), v.end(), cmp);

    for (string s : v) {
        cout << s << '\n';
    }
    return 0;
}