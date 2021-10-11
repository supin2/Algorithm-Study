// 백준 2869번 : 달팽이는 올라가고 싶다
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int A, B, V;
    cin >> A >> B >> V;

    int ans = 0, pos = 0;
    while (true) {
        if (pos >= V) {
            break;
        }
        pos += A;
        pos -= B;
        ans++;
    }
    cout << ans;
    return 0;
}