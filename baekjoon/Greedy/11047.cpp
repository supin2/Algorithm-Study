// 백준 11047번 : 동전 0
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, K, coin, ans = 0;
    vector<int> coins(10);
    coins.clear();

    cin >> N >> K;
    
    for (int i = 0; i < N; i++) {
        cin >> coin;
        coins.push_back(coin);
    }

    for (int i = N - 1; i >= 0; i--) {
        ans += K / coins[i];
        K %= coins[i];
        if (K == 0) break;
    }
    cout << ans << '\n';
    return 0;
}