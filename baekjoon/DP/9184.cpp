// 백준 9384번 :  신나는 함수 실행
#include <iostream>
#include <cstring>

using namespace std;

int w[21][21][21];


int func(int a, int b, int c) {
    if (a <= 0 || b <= 0 || c <= 0) {
        return 1;
    } else if (a > 20 || b > 20 || c > 20) {
        return func(20, 20, 20);
    }
    int &ret = w[a][b][c];
    if (ret != 0) return ret;

    if (a < b && b < c) {
        ret = func(a, b, c - 1) + func(a, b - 1, c - 1) - func(a, b - 1, c);
    } else {
        ret = func(a - 1, b, c) + func(a - 1, b - 1, c) + func(a - 1, b, c - 1) - func(a - 1, b - 1, c - 1);
    }
    return ret;
}


int main() {
    int a, b, c;
    memset(w, 0, sizeof(w));

    while (true) {
        cin >> a >> b >> c;

        if (a == -1 && b == -1 && c == -1) {
            break;
        }
        cout << "w(" << a << ", " << b << ", " << c << ") = " << func(a, b, c) << '\n';

    }
    return 0;
}