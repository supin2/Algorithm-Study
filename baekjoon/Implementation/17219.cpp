// 백준 17219번 : 비밀번호 찾기
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int N, M;
    cin >> N >> M;
    
    map<string, string> m;
    
    for (int i = 0; i < N; i++) {
        string url, pwd;
        cin >> url >> pwd;
        m[url] = pwd;
    }
    for (int i = 0; i < M; i++) {
        string a;
        cin >> a;
        cout << m[a] << '\n';
    }
    return 0;
}
