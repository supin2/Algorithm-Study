// 백준 10988번 : 팰린드롬인지 확인하기
#include <iostream>

using namespace std;

bool isPalindrome(string str) {
    int len = str.length();
    for (int i = 0; i < len/2; i++) {
        if (str[i] != str[len - 1 - i]) {
            return false;
        }
    }
    return true;
}

int main() {
    string str = "";
    cin >> str;

    if (isPalindrome(str)) {
        cout << 1;
    } else {
        cout << 0;
    }
    return 0;
}