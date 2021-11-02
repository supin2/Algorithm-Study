// 백준 13417번 : 카드 문자열
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int T;
    cin >> T;
    
    while (T--) {
        int N;
        char ch;
        string str = "";
        cin >> N;
        
        for (int i = 0; i < N; i++) {
            cin >> ch;
            if (str.empty()) {
                str += ch;
            } else {
                if (str.front() >= ch) {
                    str = ch + str;
                } else {
                    str += ch;
                }
            }
        }
        cout << str << '\n';
    }
    return 0;
}
