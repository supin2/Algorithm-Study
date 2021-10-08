// 백준 10866번 : 덱
#include <iostream>
#include <deque>

using namespace std;

int main() {
    deque<int> dq;

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        string command;
        cin >> command;

        int num;
        if (command == "push_back") {
            cin >> num;
            dq.push_back(num);
        } else if (command == "push_front") {
            cin >> num;
            dq.push_front(num);
        } else if (command == "pop_front" || command == "front") {
            if (!dq.empty()) {
                cout << dq.front() << '\n';
                if (command == "pop_front") {
                    dq.pop_front();
                }
            } else {
                cout << -1 << '\n';
            }
        } else if (command == "pop_back" || command == "back") {
            if (!dq.empty()) {
                cout << dq.back() << '\n';
                if (command == "pop_back") {
                    dq.pop_back();
                }
            } else {
                cout << -1 << '\n';
            }
        } else if (command == "size") {
            cout << dq.size() << '\n';
        } else if (command == "empty") {
            if (!dq.empty()) {
                cout << 0 << '\n';
            } else {
                cout << 1 << '\n';
            }
        }
    }
    return 0;
}