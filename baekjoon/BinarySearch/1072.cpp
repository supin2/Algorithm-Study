// 백준 1072번 : 게임
#include <iostream>

using namespace std;

int main() {
    long long X, Y;
    cin >> X >> Y;

    int Z = (Y * 100) / X;

    if (Z >= 99) {
        cout << "-1" << '\n';
        return 0;
    }

    int low = 0, high = 1000000000;
    int ans;
    while (low <= high) {
        int mid = (low + high)/2;

        int temp = ((Y + mid) * 100) / (X + mid);
        if (Z >= temp) {
            ans = mid + 1;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    cout << ans << '\n';
    return 0;
}