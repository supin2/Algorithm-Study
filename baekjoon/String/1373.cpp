// 백준 1373번 : 2진수 8진수
#include <iostream>

using namespace std;

void convert(string str) {
    int ret = 0, digit = 1;
    for (int i = 2; i >= 0; i--) {
        ret += (str[i] - '0') * digit;
        digit *= 2; 
    }
    cout << ret;
}

int main() {
    string str = "";
    cin >> str;

    if (str == "0") {
        cout << 0;
        return 0;
    }

    while (str.length() % 3 != 0) {
        str = '0' + str;
    }
    for (int i = 0; i < str.length(); i += 3) {
        convert(str.substr(i, 3));
    }
    return 0;
}