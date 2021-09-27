// 백준 10773번 : 제로
#include <iostream>
#include <stack>

using namespace std;

int main() {
    int K, ans = 0;
    cin >> K;

    stack<int> st;
    while (K--) {
        int num;
        cin >> num;

        if (num == 0) {
            st.pop();
        } else {
            st.push(num);
        }
    }

    while (!st.empty()) {
        ans += st.top();
        st.pop();
    }
    cout << ans;
    return 0;
}