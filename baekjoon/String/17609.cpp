// 백준 17609번 : 회문
#include <iostream>

using namespace std;

bool isPalindrome(string str) {
    int first = 0, last = str.length() - 1;
    while (first <= last) {
        if (str[first] != str[last]) {
            return false;
        } else {
            first++;
            last--;
        }
    }
    return true;
}

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        string str = "";
        cin >> str;

        int first = 0, last = str.length() - 1;
        if (isPalindrome(str)) {
            cout << 0 << '\n';
        } else {
            while (first <= last) {
                if (str[first] != str[last]) {
                    string copyStr = str;
                    string leftErase = str.erase(first, 1);
                    string rightErase = copyStr.erase(last, 1);

                    if (isPalindrome(leftErase)) {
                        cout << 1 << '\n';
                    } else if (isPalindrome(rightErase)) {
                        cout << 1 << '\n';
                    } else {
                        cout << 2 << '\n';
                    }
                    break;
                } else {
                    first++;
                    last--;
                }
            }
        }
    }
    return 0;
}