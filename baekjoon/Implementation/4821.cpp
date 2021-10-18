// 백준 4821번 : 페이지 세기
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    while (true) {
        int n;
        cin >> n;
        if (n == 0) {
            break;
        }
        cin.ignore();
        
        string text = "";
        getline(cin, text);
        stringstream ss(text);
        string temp;
        vector<bool> check(n + 1, false);
        
        while (getline(ss, temp, ',')) {
            auto pos = temp.find('-');
            if (pos == string::npos) {
                if (stoi(temp) <= n && stoi(temp) >= 1) {
                    check[stoi(temp)] = true;
                }
                continue;
            }
            int from = stoi(temp.substr(0, pos));
            int to = stoi(temp.substr(pos + 1));
            if (from > to) {
                continue;
            }

            for (int i = max(from, 1); i <= min(to, n); i++) {
                if (!check[i]) {
                    check[i] = true;
                }
            }
        }
        int cnt = 0;
        for (int i = 0; i < check.size(); i++) {
            if (check[i]) {
                cnt++;
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}