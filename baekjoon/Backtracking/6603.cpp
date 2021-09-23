// 백준 6603번 : 로또
#include <iostream>
#include <vector>

using namespace std;

vector<int> v(13), ret(6);
int k;

void dfs(int cnt, int pos) {
    if (cnt == 6) {
        for (int i = 0; i < 6; i++) {
            cout << ret[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = pos; i < k; i++) {
        ret[cnt] = v[i];
        dfs(cnt + 1, i + 1);
    }
}

int main() {
    while (true) {
        cin >> k;
        if (k == 0) {
            return 0;
        }
        for (int i = 0; i < k; i++) {
            cin >> v[i];
        }
        dfs(0, 0);
        cout << '\n';
    }
}