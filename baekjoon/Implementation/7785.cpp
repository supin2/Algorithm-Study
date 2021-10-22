// 백준 7785번 : 회사에 있는 사람
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int N;
    cin >> N;
    
    map<string, bool> m;
    for (int i = 0; i < N; i++) {
        string name, act;
        cin >> name >> act;
        if (act == "enter") {
            m[name] = true;
        } else if (act == "leave") {
            m[name] = false;
        }
    }
    
    vector<string> v;
    for (auto it : m) {
        if (it.second) {
            v.push_back(it.first);
        }
    }
    sort(v.begin(), v.end(), greater<string>());
    
    for (string s : v) {
        cout << s << '\n';
    }
    return 0;
}
