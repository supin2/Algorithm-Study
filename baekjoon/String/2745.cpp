// 백준 2745번 : 진법 변환
#include <iostream>
#include <cmath>

using namespace std;

int arr[26] = { 0, };

void convert(string str, int num) {
    int len = str.length() - 1;
    int ret = 0, digit = 1;

    for (int i = len; i >= 0; i--) {
        char ch = str[i];
        digit = pow(num, len - i);

        if (isdigit(ch)) {
            ret += (ch - '0') * digit;
        } else {
            ret += arr[ch - 'A'] * digit;
        }
    }
    cout << ret;
}

int main() {
    string str = "";
    int num = 0;

    cin >> str >> num;

    for (int i = 0; i < 26; i++) {
        arr[i] = 10 + i;
    }
    convert(str, num);
    
    return 0;
}