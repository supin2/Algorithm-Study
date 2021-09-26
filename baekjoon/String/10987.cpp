// 백준 10987번 : 모음의 개수
#include <iostream>

using namespace std;

int main() {
    string str = "";
    int ans = 0;

    cin >> str;

    for (char ch : str) {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            ans++;
        }
    }
    cout << ans;
    return 0;
}