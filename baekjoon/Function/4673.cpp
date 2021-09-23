// 백준 4673번 : 셀프 넘버
#include <iostream>
#include <cstring>

using namespace std;

int isSelfNumber(int num) {
    int sum = num;
    while (num) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int main() {
    bool check[10001];
    memset(check, false, sizeof(check));

    for (int i = 1; i <= 10000; i++) {
        int ret = isSelfNumber(i);
        if (ret <= 10000) check[ret] = true;
    }
    for (int i = 1; i <= 10000; i++) {
        if (!check[i]) cout << i << '\n';
    }
    return 0;
}