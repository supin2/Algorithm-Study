// 백준 2023번 : 신기한 소수
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

int N;

bool isPrime(int num) {
    if (num < 2) {
        return false;
    }
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

void dfs(int cnt, int num) {
    if (!isPrime(num)) {
        return;
    }
    if (cnt == N) {
        cout << num << '\n';
        return;
    }

    for (int i = 1; i <= 9; i++) {
        dfs(cnt + 1, num * 10 + i);
    }
}

int main() {
    cin >> N;
    dfs(1, 2);
    dfs(1, 3);
    dfs(1, 5);
    dfs(1, 7);

    return 0;
}