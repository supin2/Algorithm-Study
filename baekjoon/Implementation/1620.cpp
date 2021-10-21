// 백준 1620번 : 나는야 포켓몬 마스터 이다솜
#include <bits/stdc++.h>

using namespace std;

string arr[100001];
map<string, int> m;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, M;
    cin >> N >> M;
    
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        m[arr[i]] = i;
    }

    for (int i = 0; i < M; i++) {
        string str;
        cin >> str;
        if (isdigit(str[0])) {
            cout << arr[stoi(str)] << '\n';
        } else {
            cout << m[str] << '\n';
        }     
    }
    return 0;
}