// 백준 1062번 : 가르침
#include <iostream>
#include <vector>

using namespace std;

int N, K, ans = -1;
vector<string> v;
bool selected[26] = { false, };

void dfs(int idx, int cnt) {
    if (cnt == K - 5) {
        int ret = 0;
        for (string str : v) {
            bool flag = true;
            if (str.length() > 8) {
                for (int i = 4; i < str.length() - 4; i++) {
                    char ch = str[i];
                    if (!selected[ch - 'a']) {
                        flag = false;
                        break;
                    }
                }
            }
            if (flag) {
                ret++;
            }
        }
        ans = max(ans, ret);
        return;
    }
    for (int i = idx; i < 26; i++) {
        if (selected[i]) {
            continue;
        }
        selected[i] = true;
        dfs(i, cnt + 1);
        selected[i] = false;
    }
}

int main() {
    cin >> N >> K;

    if (K < 5) {
        cout << 0;
        return 0;
    } else if (K == 26) {
        cout << N;
        return 0;
    }

    string antatica = "antic";
    for (char ch : antatica) {
        selected[ch - 'a'] = true;
    }

    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        v.push_back(str);
    }
    dfs(0, 0);

    cout << ans;
    return 0;
}