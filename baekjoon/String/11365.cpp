// 백준 11365번 : !밀비 급일
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string text = "";
    while (getline(cin, text)) {
        if (text == "END") {
            break;
        }
        reverse(text.begin(), text.end());
        cout << text << '\n';
    }
    return 0;
}