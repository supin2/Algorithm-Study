// 백준 2605번 : 줄 세우기
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, order = 1;
    stack<int> st;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        
        if (num == 0) {
            st.push(order);
            order++;
        } else {
            stack<int> temp;
            for (int j = 0; j < num; j++) {
                temp.push(st.top());
                st.pop();
            }
            st.push(order);
            order++;
            while (!temp.empty()) {
                st.push(temp.top());
                temp.pop();
            }
        }
    }
    vector<int> ret;
    while (!st.empty()) {
        ret.push_back(st.top());
        st.pop();
    }
    for (int i = ret.size() - 1; i >= 0; i--) {
        cout << ret[i] << ' ';
    }
    return 0;
}