// 백준 10546번 : 배부른 마라토너
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int N, ans = 0;
    cin >> N;
    map<string, int> m;
    
    string name;
    for (int i = 0; i < N; i++) {
        cin >> name;
        m[name]++;
    }
    
    for (int i = 0; i < N - 1; i++) {
        cin >> name;
        m[name]--;
    }
    
    for (auto it = m.begin(); it != m.end(); it++) {
        if (it->second != 0) {
            cout << it->first;
        }
    }
    return 0;
}
