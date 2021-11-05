// 백준 1550번 : 16진수
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string str;
    map<char, int> m;
    cin >> str;

    for (int i = 0; i < 6; i++) {
        char ch = 'A' + i;
        m[ch] = 10 + i;
    }
    
    int len = str.length();
    int n = 1, ans = 0;

    for (int i = len - 1; i >= 0; i--, n *= 16) {
        char ch = str[i];
        if (isalpha(ch)) {
            ans += n * m[ch];
        } else {
            ans += n * (ch - '0');
        }
    }
    cout << ans;
    return 0;
}