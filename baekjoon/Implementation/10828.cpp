// 백준 10828번 : 스택
#include <iostream>
#include <stack>

using namespace std;

int main() {
    stack<int> st;

    int N;
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        string command;
        cin >> command;

        if (command == "push") {
            int num;
            cin >> num;
            st.push(num);
        } else if (command == "pop" || command == "top") {
            if (!st.empty()) {
                cout << st.top() << '\n';
                if (command == "pop") {
                    st.pop();
                }
            } else {
                cout << -1 << '\n';
            }
        } else if (command == "size") {
            cout << st.size() << '\n';
        } else if (command == "empty") {
            if (st.empty()) {
                cout << 1 << '\n';
            } else {
                cout << 0 << '\n';
            }
        }
    }
    return 0;
}