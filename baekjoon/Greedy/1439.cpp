// 백준 1439번 : 뒤집기
#include <iostream>

using namespace std;

int main() {
    string str;
    int zero = 0, one = 0;
    cin >> str;

    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '0') zero++;
        else one++;
    }

    return 0;
}