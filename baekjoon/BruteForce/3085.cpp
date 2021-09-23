// 백준 3085번 : 사탕 게임
#include <iostream>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

const int MAX = 51;

int N, ans;
string candy[MAX];

int calculate() {
    for (int i = 0; i < N; ++i) {
        int temp = 1;
        for (int j = 1; j < N; ++j) {
            if (candy[i][j - 1] == candy[i][j]) {
                temp++;
            } else {
                ans = max(ans, temp);
                temp = 1;
            }
        }
        ans = max(ans, temp);
    }

    for (int i = 0; i < N; ++i) {
        int temp = 1;
        for (int j = 0; j < N - 1; ++j) {
            if (candy[j][i] == candy[j + 1][i]) {
                temp++;
            } else {
                ans = max(ans, temp);
                temp = 1;
            }
        }
        ans = max(ans, temp);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> candy[i];
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N - 1; ++j) {
            swap(candy[i][j], candy[i][j + 1]);
            ans = max(ans, calculate());
            swap(candy[i][j], candy[i][j + 1]);

            swap(candy[j][i], candy[j + 1][i]);
            ans = max(ans, calculate());
            swap(candy[j][i], candy[j + 1][i]);
        }
    }

    cout << ans << '\n';
    return 0;
}