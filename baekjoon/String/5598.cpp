// 백준 5598번 : 카이사르 암호
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string str;
    cin >> str;

    for (char ch : str) {
        char tmp = ch - 3;
        if (tmp < 'A') {
            tmp += 26;
        }
        cout << tmp;
    }
    return 0;
}