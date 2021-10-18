// 백준 5363번 : 요다
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    cin.ignore();
    for (int i = 0; i < N; i++) {
        string text = "";
        getline(cin, text);
        int blank = 0;
        string str1 = "", ret = "";
        for (char ch : text) {
            if (blank < 2) {
                if (ch == ' ') {
                    blank++;
                }
                str1 += ch;
                continue;
            }
            ret += ch;
        }
        cout << ret + ' ' + str1 << '\n';
    }
    return 0;
}