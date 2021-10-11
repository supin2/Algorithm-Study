// 백준 1978번 : 소수 찾기
#include <iostream>

using namespace std;

bool isPrime(int num) {
    if (num < 2) return false;

    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, ans = 0;
    cin >> N;
    for (int i = 0, num; i < N; i++) {
        cin >> num;
        if (isPrime(num)) {
            ans++;
        }
    }
    cout << ans;
    return 0;
}