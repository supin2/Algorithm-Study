// 백준 2789번 : 유학 금지
#include <iostream>

using namespace std;

bool isValid(char ch) {
    if (ch == 'C' || ch == 'A' || ch == 'M' || ch == 'B' || ch == 'R' || ch == 'I' || ch == 'D' || ch == 'G' || ch == 'E') {
        return false;
    }
    return true;
}

int main() {
    string str;
    cin >> str;

    for (char ch : str) {
        if (isValid(ch)) {
            cout << ch;
        }
    }
    return 0;
}