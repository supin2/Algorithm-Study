// 백준 2609번 : 최대공약수와 최소공배수
#include <iostream>

using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int main() {
    int a, b;
    cin >> a >> b;

    cout << gcd(a, b) << '\n' << lcm(a, b);
    return 0;
}