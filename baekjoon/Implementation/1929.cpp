// 백준 1929번 :  소수 구하기
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

    int M, N;
    cin >> M >> N;

    for (int i = M; i <= N; i++) {
        if (isPrime(i)) {
            cout << i << '\n';
        }
    }
    
    return 0;
}