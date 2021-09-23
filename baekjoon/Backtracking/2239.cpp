// 백준 2239번 : 스도쿠
#include <iostream>
#include <vector>

using namespace std;

vector<string> v;
vector<pair<int, int>> zero;
int zero_cnt = 0;
bool findFlag = false;

bool isValid(int y, int x) {
    char ch = v[y][x];
    for (int i = 0; i < 9; i++) {
        if (v[i][x] == ch && y != i) {
            return false;
        }
        if (v[y][i] == ch && x != i) {
            return false;
        }
    }

    int y_scope = y / 3;
    int x_scope = x / 3;

    for (int i = y_scope * 3; i < y_scope * 3 + 3; i++) {
        for (int j = x_scope * 3; j < x_scope * 3 + 3; j++) {
            if (v[i][j] == ch && i != y && j != x) {
                return false;
            }
        }
    }
    return true;
}

void dfs(int cnt) {
    if (findFlag) {
        return;
    }
    if (cnt == zero_cnt) {
        for (string s : v) {
            cout << s << '\n';
        }
        findFlag = true;
        return;
    }
    for (int num = 1; num <= 9; num++) {
        v[zero[cnt].first][zero[cnt].second] = num + '0';
        if (isValid(zero[cnt].first, zero[cnt].second)) {
            dfs(cnt + 1);
        }
    }
    v[zero[cnt].first][zero[cnt].second] = '0';
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < 9; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < str.length(); j++) {
            char ch = str[j];
            if (ch == '0') {
                zero_cnt++;
                zero.push_back(make_pair(i, j));
            }
        }
        v.push_back(str);
    }
    dfs(0);

    return 0;
}