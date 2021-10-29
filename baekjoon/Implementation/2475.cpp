// 백준 2475번 : 검증수
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    long long sum = 0;

    for (int i = 0; i < 5; i++) {
        long long num;
        cin >> num;
        sum += pow(num, 2);
    }
    cout << sum % 10;
    return 0;
}