// 백준 2529번 : 부등호
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
char arr[10];
bool selected[10] = { false };

vector<string> v;

void dfs(int idx, int cnt, string candid) {
    if (cnt == N + 1) {
        v.push_back(candid);
        return;
    }
    for (int now = 0; now <= 9; now++) {
        if (selected[now]) {
            continue;
        }
        char ch_now = now + '0';
        int before = candid[idx] - '0';

        selected[now] = true;
        if (arr[idx] == '<' && before < now) {
            dfs(idx + 1, cnt + 1, candid + ch_now);
        } else if (arr[idx] == '>' && before > now) {
            dfs(idx + 1, cnt + 1, candid + ch_now);
        }
        selected[now] = false;
    }
}

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i <= 9; i++) {
        string tmp = "";
        char ch = i + '0';
        tmp += ch;
        selected[i] = true;
        dfs(0, 1, tmp);
        selected[i] = false;
    }
    sort(v.begin(), v.end());
    auto ret = minmax_element(v.begin(), v.end());
    
    cout << *ret.second << '\n' << *ret.first;
    return 0;
}