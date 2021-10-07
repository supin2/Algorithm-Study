// 백준 1251번 : 단어 나누기
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    string str, ans = "";
    cin >> str;

    for (int i = 1; i < str.length() - 1; i++) {
        for (int j = 1; j < str.length() - i; j++) {
            string a = str.substr(0, i);
            string b = str.substr(i, j);
            string c = str.substr(i + j);
            reverse(a.begin(), a.end());
            reverse(b.begin(), b.end());
            reverse(c.begin(), c.end());
            
            if (ans == "") {
                ans = a + b + c;
            } else if (ans > a + b + c) {
                ans = a + b + c;
            }
        }
    }
    cout << ans;
    return 0;
}