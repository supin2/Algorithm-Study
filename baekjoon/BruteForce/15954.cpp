// 백준 15954번 : 인형들
#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int N, K;
double ans = 987654321;
double arr[501];

void calculate(int first, int last) {
    double sum = 0;
    int total = last - first + 1;
    for (int i = first; i <= last; i++) {
        sum += arr[i];
    }
    double avg = (double) sum / total;
    double vari = 0;
    
    for (int i = first; i <= last; i++) {
        vari += pow(arr[i] - avg, 2);
    }
    vari /= (double) total;
    
    if (ans > sqrt(vari)) {
        ans = sqrt(vari);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; i++) {
        scanf("%lf", &arr[i]);
    }
    
    for (int i = 0; i <= N - K; i++) {
        for (int j = i + K - 1; j < N; j++) {
            calculate(i, j);
        }
    }
    cout.precision(11);
    cout << ans;
    return 0;
}