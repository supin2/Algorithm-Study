// 백준 12018번 : Yonsei TOTO
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, m, ans = 0;
    cin >> n >> m;
    
    priority_queue<int, vector<int>, greater<int>> pq;
    
    while (n--) {
        int P, L;
        priority_queue<int, vector<int>, greater<int>> tmp;
        cin >> P >> L;
        for (int i = 0, num; i < P; i++) {
            cin >> num;
            tmp.push(num);
        }
        
        if (P < L) {
            pq.push(1);
        } else if (P == L) {
            pq.push(tmp.top());
        } else {
            while (tmp.size() > L) {
                tmp.pop();
            }
            pq.push(tmp.top());
        }
    }
    
    while (!pq.empty()) {
        if (m - pq.top() >= 0) {
            ans++;
            m -= pq.top();
            pq.pop();
        } else {
            break;
        }
    }
    cout << ans;
    return 0;
}
