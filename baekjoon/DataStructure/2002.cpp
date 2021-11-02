// 백준 2002번 : 추월
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int N, ans = 0;
    cin >> N;
    map<string, int> m;
    vector<int> v;
    
    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        m[str] = i;
    }
    
    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        v.push_back(m[str]);
    }
    
    for (int i = 0; i < v.size() - 1; i++) {
        for (int j = i + 1; j < v.size(); j++) {
            if (v[i] > v[j]) {
                ans++;
                break;
            }
        }
    }
    cout << ans;
    return 0;
}
