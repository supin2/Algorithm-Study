// 백준 1662번 : 압축
#include <bits/stdc++.h>

using namespace std;

bool visited[51];

int dfs(string str, int idx) {
    int cnt = 0;
    for (int i = idx; i < str.size(); i++) {
        if (str[i] == '(' && !visited[i]) {
            visited[i] = true;
            int num = str[i - 1] - '0';
            cnt--;
            cnt += num * dfs(str, i + 1);
        } else if (str[i] == ')' && !visited[i]) {
            visited[i] = true;
            return cnt;
        } else if (!visited[i]) {
            visited[i] = true;
            cnt++;
        }
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    string str;
    cin >> str;

    cout << dfs(str, 0);
    return 0;
}