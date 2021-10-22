// 백준 5568번 : 카드 놓기
#include <bits/stdc++.h>

using namespace std;

int n, k;
vector<int> v;
vector<bool> visited;
set<string> st;

void dfs(int idx, int cnt) {
    if (cnt == k) {
        vector<int> temp;
        for (int i = 0; i < visited.size(); i++) {
            if (visited[i]) {
                temp.push_back(v[i]);
            }
        }
        sort(temp.begin(), temp.end());
        do {
            string str = "";
            for (int i = 0; i < temp.size(); i++) {
                str += to_string(temp[i]);
            }
            st.insert(str);
        } while (next_permutation(temp.begin(), temp.end()));
    }
    
    for (int i = idx; i < v.size(); i++) {
        if (!visited[i]) {
            visited[i] = true;
            dfs(i, cnt + 1);
            visited[i] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> k;
    v.resize(n);
    visited.resize(n);
    
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    dfs(0, 0);
    
    cout << st.size();
    return 0;
}
