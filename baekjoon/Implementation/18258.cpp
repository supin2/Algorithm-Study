// 백준 18258번 : 큐 2
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;

    queue<int> q;
    while (N--) {
        string cmd;
        cin >> cmd;

        if (cmd == "push") {
            int num;
            cin >> num;
            q.push(num);
        } else if (cmd == "pop" || cmd == "back" || cmd == "front") {
            if (q.empty()) {
                cout << -1 << '\n';
            } else {
                if (cmd == "pop" || cmd == "front") {
                    cout << q.front() << '\n';
                    if (cmd == "pop") {
                        q.pop();
                    }
                } else {
                    cout << q.back() << '\n';
                }
            }
        } else if (cmd == "size") {
            cout << q.size() << '\n';
        } else if (cmd == "empty") {
            if (q.empty()) {
                cout << 1 << '\n';
            } else {
                cout << 0 << '\n';
            }
        } 
    }
    return 0;
}