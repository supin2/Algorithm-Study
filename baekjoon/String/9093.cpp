// 백준 9093번 : 단어 뒤집기
#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;

    cin.ignore();
    while (T--) {
        string text = "", tmp = "";
        getline(cin, text);
        text += ' ';

        for (char ch : text) {
            if (isalpha(ch)) {
                tmp += ch;
            } else {
                while (tmp.length() > 0) {
                    cout << tmp.back();
                    tmp.pop_back();
                }
                cout << ' ';
            }
        }
        cout << '\n';
    }
    return 0;
}