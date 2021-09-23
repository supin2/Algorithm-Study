// 백준 1654번 : 랜선 자르기
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int K, N;
vector<long long> wire;

int check(long long base) {
    int sum = 0;
    for (int i = 0; i < K; i++) {
        sum += (wire[i] / base);
    }
    return sum;
}

long long BinarySearch() {
    long long ans = 0;
    long long low = 1, high = wire[K - 1];

    while (low <= high) {
        long long mid = (low + high)/2;

        if (check(mid) >= N) {
            ans = max(ans, mid);
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> K >> N;

    for (int i = 0; i < K; i++) {
        long long length;
        cin >> length;
        wire.push_back(length);
    }
    sort(wire.begin(), wire.end());

    cout << BinarySearch() << '\n';
    return 0;
}