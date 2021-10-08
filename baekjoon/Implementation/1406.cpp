// 백준 1406번 : 에디터
#include <iostream>
#include <string>
#include <list>

using namespace std;

int main() {
    string str;
    int N;
    cin >> str;
    cin >> N;

    list<char> li(str.begin(), str.end());
    auto pos = li.end();

    while (N--) {
        char command;
        cin >> command;

        if (command == 'L') {
            if (pos != li.begin()) {
                pos--;
            }
        } else if (command == 'D') {
            if (pos != li.end()) {
                pos++;
            }
        } else if (command == 'B') {
            if (pos != li.begin()) {
                pos--;
                pos = li.erase(pos);
            }
        } else if (command == 'P') {
            char alpha;
            cin >> alpha;
            li.insert(pos, alpha);
        }
    }

    for (auto it = li.begin(); it != li.end(); it++) {
        cout << *it;
    }
    return 0;
}