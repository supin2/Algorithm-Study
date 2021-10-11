// 백준 1644번 : 소수의 연속합
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, ans = 0;
    cin >> N;
    vector<bool> v(N + 1, true);
    vector<int> prime;

    for (int i = 2; i * i <= N; i++) {
        if (v[i]) {
            for (int j = i * i; j <= N; j += i) {
                v[j] = false;
            }
        }
    }
    for (int i = 2; i <= N; i++) {
        if (v[i]) {
            prime.push_back(i);
        }
    }

    int first = 0, last = 0, sum = 0;
    while (true) {
        if (sum == N) {
            ans++;
            if (last >= prime.size()) {
                break;
            }
            sum += prime[last++];
        } else if (sum < N) {
            if (last >= prime.size()) {
                break;
            }
            sum += prime[last++];
        } else if (sum > N) {
            sum -= prime[first++];
        }
    }
    cout << ans;
    return 0;
}