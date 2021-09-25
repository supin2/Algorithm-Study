// 백준 11719번 : 그대로 출력하기 2
#include <iostream>

using namespace std;

int main() {
    string text = "";

    while (getline(cin, text)) {
        cout << text << '\n';
    }
    return 0;
}