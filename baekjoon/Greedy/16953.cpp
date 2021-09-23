// 백준 16953번 : A -> B
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int A, B, cnt = 0;
    bool flag = false;

    cin >> A >> B;

    while (true) {
        if (A > B) {
            flag = false;
            break;
        }
        if (A == B) {
            flag = true;
            break;
        }
        if (B % 2 == 0) {
            B /=
        } else if (B % 10 == 1) {
            B--;
            B /= 10;
        } else {
            flag = false;
            break;
        }
        cnt++;
    }
    if (!flag) {
        cout << -1 << '\n';
    } else {
        cout << cnt + 1 << '\n';
    }
    return 0;
}