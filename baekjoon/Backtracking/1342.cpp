// 백준 1342번 : 행운의 문자열
#include <bits/stdc++.h>

using namespace std;

int ans;
string str;

bool isValid() {
    for (int i = 1; i < str.length() - 1; i++) {
        char ch = str[i];
        if (str[i - 1] == ch || str[i + 1] == ch) {
            return false;
        }
    }
    return true;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> str;

    sort(str.begin(), str.end());
    do {
        if (isValid()) {
            ans++;
        }
    } while (next_permutation(str.begin(), str.end()));

    cout << ans;
    return 0;
}