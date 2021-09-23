// 백준 1541번 : 잃어버린 괄호
#include <iostream>

using namespace std;

int main() {
    string input = "", tmp = "";
    bool minus = false;
    int ans = 0;
    
    cin >> input;

    for (int i = 0; i <= input.length(); i++) {
        char ch = input[i];
        if (ch == '+' || ch == '-' || ch == '\0') {
            if (minus) ans -= stoi(tmp);
            else ans += stoi(tmp);

            if (ch == '-') minus = true;

            tmp = "";
            continue;
        } else { // 숫자일 경우
            tmp += ch;
        }
    }
    cout << ans << '\n';
    return 0;
}