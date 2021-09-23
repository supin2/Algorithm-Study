// 백준 2798번 : 블랙잭

#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

#define MAX 101

int N, M, ans = INT_MIN;
int cards[MAX];

void input() {
    cin >> N >> M;

    for (int i = 0; i < N; ++i) {
        cin >> cards[i];
    }
}

void solution() {
    int sum = 0;
    for (int i = 0; i < N - 2; i++) {
        for (int j = i + 1; j < N - 1; j++) {
            for (int k = j + 1; k < N; k++) {
                sum = cards[i] + cards[j] + cards[k];
                if (sum <= M && sum > ans) {
                    ans = sum;
                } 
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();
    solution();

    cout << ans << '\n';

    return 0;
}