// 백준 1212번 : 8진수 2진수
#include <iostream>
#include <algorithm>

using namespace std;

string convert(int num) {
    string ret = "";
    while (ret.length() != 3) {
        ret += to_string(num % 2);
        num /= 2;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

int main() {
    string num = "", ret = "";
    cin >> num;

    if (num == "0") {
        cout << 0;
        return 0;
    }

    for (char ch : num) {
        ret += convert(ch - '0');
    }
    while (ret.front() == '0') {
        ret = ret.substr(1);
    }
    cout << ret;
    return 0;
}