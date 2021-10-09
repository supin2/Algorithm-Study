// 백준 1874번 : 스택 수열
#include <iostream>
#include <stack>

using namespace std;

int main() {
    int N;
    string ret = "";
    cin >> N;

    stack<int> st;
    int num = 1;
    for (int i = 0, target; i < N; i++) {
        cin >> target;

        while (num <= target) {
            st.push(num++);
            ret += '+';
        }
        if (st.top() == target) {
            st.pop();
            ret += '-';
        } else {
            cout << "NO";
            return 0;
        }
    }
    for (char ch : ret) {
        cout << ch << '\n';
    }
    return 0;
}