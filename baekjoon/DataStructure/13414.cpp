// 백준 13414번 : 수강신청
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int K, L;
    cin >> K >> L;
    
    vector<string> v, ret;
    set<string> st;
    
    for (int i = 0; i < L; i++) {
        string str;
        cin >> str;
        v.push_back(str);
    }
    for (int i = v.size() - 1; i >= 0; i--) {
        if (st.find(v[i]) == st.end()) {
            st.insert(v[i]);
            ret.push_back(v[i]);
        }
    }
    for (int i = ret.size() - 1; i >= 0 && K > 0; i--, K--) {
        cout << ret[i] << '\n';
    }
    return 0;
}
