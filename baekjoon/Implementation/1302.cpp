// 백준 1302번 : 베스트셀러
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int N;
    int maxCnt = -1;
    string ans = "";
    
    map<string, int> m;
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        string book;
        cin >> book;
        m[book]++;
        
        if (maxCnt < m[book]) {
            maxCnt = m[book];
            ans = book;
        } else if (maxCnt == m[book]) {
            if (book.compare(ans) < 0) {
                ans = book;
            }
        }
    }
    cout << ans;
    return 0;
}
