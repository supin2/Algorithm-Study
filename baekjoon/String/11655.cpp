// 백준 11655번 : ROT13
#include <iostream>

using namespace std;

int main() {
    string text = "", ret = "";
    getline(cin, text);
    
    for (char ch : text) {
        if (isalpha(ch)) {
            if ((ch >= 'A' && ch <= 'M') || (ch >= 'a' && ch <= 'm')) {
                ret += (char) (ch + 13);
            } else {
                ret += (char) (ch - 13);
            }
        } else {
            ret += ch;
        }
    }
    cout << ret;
    return 0;
}