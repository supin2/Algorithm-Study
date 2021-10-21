// 백준 17298번 : 오큰수
#include <bits/stdc++.h>

using namespace std;

int arr[1000001];
int N;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    stack<int> st;

    vector<int> ret;
    ret.push_back(-1);
    st.push(N - 1);
    for (int i = N - 2; i >= 0; i--) {
        if (arr[i] < arr[st.top()]) {
            ret.push_back(arr[st.top()]);
            st.push(i);
        } else {
            while (!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();
            }
            if (st.empty()) {
                ret.push_back(-1);
                st.push(i);
            } else {
                ret.push_back(arr[st.top()]);
                st.push(i);
            }
        }
    }
    for (int i = ret.size() - 1; i >= 0; i--) {
        cout << ret[i] << ' ';
    }
    return 0;
}