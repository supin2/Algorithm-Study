// 백준 1254번 : 팰린드롬 만들기
#include <iostream>

using namespace std;

string S = "";

bool isPalindrome(int pos) {
    for (int i = 0; i < (S.length() - pos)/2; i++) {
        if (S[pos + i] != S[S.length() - 1 - i]) {
            return false;
        }
    }
    return true;
}

int main() {
    cin >> S;

    for (int i = 0; i < S.length(); i++) {
        if (isPalindrome(i)) {
            cout << S.length() + i;
            break;
        }
    }
    return 0;
}