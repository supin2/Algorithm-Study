// 백준 4740번 : 거울, 오! 거울
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    string str;

    while (true) {
        getline(cin, str);
        if (str == "***") {
            break;
        }
        reverse(str.begin(), str.end());
        cout << str << '\n';
    }
    return 0;
}