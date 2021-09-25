// 백준 1259번 : 팰린드롬수
#include <iostream>

using namespace std;

bool isPalindrome(string num) {
    int len = num.length();
    for (int i = 0; i < len/2; i++) {
        if (num[i] != num[len - 1 - i]) {
            return false;
        }
    }
    return true;
}

int main() {
    while (true) {
        string str;
        cin >> str;
        if (str == "0") {
            break;
        }
        if (isPalindrome(str)) {
            cout << "yes" << '\n';
        } else {
            cout << "no" << '\n';
        }
    }
    return 0;
}