// 백준 5397번 : 키로거
#include <iostream>
#include <list>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;

    while (T--) {
        list<char> li;
        string str;
        cin >> str;

        auto pos = li.begin();
        for (char ch : str) {
            if (ch == '<') {
                if (pos != li.begin()) {
                    pos--;
                }
            } else if (ch == '>') {
                if (pos != li.end()) {
                    pos++;
                }
            } else if (ch == '-') {
                if (pos != li.begin()) {
                    pos = li.erase(--pos);
                }
            } else {
                li.insert(pos, ch);
            }
        }
        for (auto it = li.begin(); it != li.end(); it++) {
            cout << *it;
        }
        cout << '\n';
    }    
    return 0;
}