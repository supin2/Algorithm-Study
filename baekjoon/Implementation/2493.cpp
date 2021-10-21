// 백준 2493번 : 탑
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N;
    cin >> N;

    stack<int> st;
    int arr[500001];
    for (int i = 0; i < N; i++) {
        int num;
        cin >> arr[i];
    }

    vector<int> ret;
    st.push(0);
    ret.push_back(0);
    for (int i = 1; i < N; i++) {
        if (arr[st.top()] > arr[i]) {
            ret.push_back(st.top() + 1);
            st.push(i);
        } else {
            while (!st.empty() && arr[st.top()] < arr[i]) {
                st.pop();
            }
            if (st.empty()) {
                ret.push_back(0);
            } else {
                ret.push_back(st.top() + 1);
            }
            st.push(i);
        }
    }
    for (int i = 0; i < ret.size(); i++) {
        cout << ret[i] << ' ';
    }
    return 0;
}