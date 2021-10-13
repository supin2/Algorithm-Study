// 백준 2502번 : 떡 먹는 호랑이
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int D, K, A[31], B[31];
    cin >> D >> K;
    
    A[1] = 1, A[2] = 0;
    B[1] = 0, B[2] = 1;

    for (int i = 3; i <= D; i++) {
        A[i] = A[i - 1] + A[i - 2];
        B[i] = B[i - 1] + B[i - 2];
    }

    int first, second;
    for (int i = 1; i <= K; i++) {
        int spare = K - A[D] * i;
        if (spare % B[D] == 0) {
            first = i;
            second = spare / B[D];
            break;
        }
    }
    cout << first << '\n' << second;
    return 0;
}