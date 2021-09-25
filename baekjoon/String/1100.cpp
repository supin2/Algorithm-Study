// 백준 1100번 : 하얀 칸
#include <iostream>

using namespace std;

int main() {
    string str = "";
    int ans = 0;

    for (int row = 0; row < 8; row++) {
        cin >> str;
        for (int col = 0; col < 8; col++) {
            if (row % 2 == 0) {
                if (col % 2 == 0 && str[col] == 'F') {
                    ans++;
                }
            } else {
                if (col % 2 == 1 && str[col] == 'F') {
                    ans++;
                }
            }
        }
    }
    cout << ans;
    return 0;
}