// 백준 2992번 : 크면서 작은 수
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string str;
    cin >> str;

    string tmp = str;

    sort(str.begin(), str.end());
    do {
        if (str > tmp) {
            cout << str;
            exit(0);
        }
    } while (next_permutation(str.begin(), str.end()));
    cout << 0;
    return 0;
}