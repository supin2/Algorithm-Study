// 백준 10845번 : 큐
#include <iostream>
#include <queue>

using namespace std;

int main() {
    queue<int> q;
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        string command;
        cin >> command;

        if (command == "push") {
            int num;
            cin >> num;
            q.push(num);
        } else if (command == "pop" || command == "front") {
            if (!q.empty()) {
                cout << q.front() << '\n';
                if (command == "pop") {
                    q.pop();
                }
            } else {
                cout << -1 << '\n';
            }
        } else if (command == "size") {
            cout << q.size() << '\n';
        } else if (command == "empty") {
            if (!q.empty()) {
                cout << 0 << '\n';
            } else {
                cout << 1 << '\n';
            }
        } else if (command == "back") {
            if (!q.empty()) {
                cout << q.back() << '\n';
            } else {
                cout << -1 << '\n';
            }
        }
    }
    return 0;
}