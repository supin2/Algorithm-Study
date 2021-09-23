// 백준 2810번 : 컵홀더
#include <iostream>

using namespace std;

int main() {
    int N;
    string str;

    cin >> N >> str;
    int ans = N + 1;
    int cnt = 0;
    for (int i = 0; i < str.length(); i++) {
        char ch = str[i];
        if (ch == 'L') cnt++;
    }
    ans = (cnt == 0) ? N : ans - (cnt / 2);

    cout << ans << '\n';
    return 0;
}