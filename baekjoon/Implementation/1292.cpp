// 백준 1292번 : 쉽게 푸는 문제
#include <iostream>

using namespace std;

int main() {
    int A, B;
    cin >> A >> B;

    int num = 1, cnt = 1, sum = 0;
    while (true) {
        for (int i = 0; i < num; i++, cnt++) {
            if (cnt >= A && cnt <= B) {
                sum += num;
            }
        }
        if (cnt > B) {
            break;
        }
        num++;
    }
    cout << sum;
    return 0;
}