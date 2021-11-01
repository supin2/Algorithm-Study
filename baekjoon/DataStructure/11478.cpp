// 백준 11478번 : 서로 다른 부분 문자열의 개수
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    string str;
    cin >> str;
    
    set<string> st;
    
    for (int i = 0; i < str.length(); i++) {
        for (int j = 1; j <= str.length() - i; j++) {
            st.insert(str.substr(i, j));
        }
    }
    cout << st.size();
    return 0;
}
