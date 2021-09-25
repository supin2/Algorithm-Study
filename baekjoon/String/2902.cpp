// 백준 2902번 : KMP는 왜 KMP일까?
#include <iostream>

using namespace std;

int main() {
    string str = "", ret = "";
    cin >> str;

    for (char ch : str) {
        if (isupper(ch)) {
            ret += ch;
        }
    }
    cout << ret;
    return 0;
}