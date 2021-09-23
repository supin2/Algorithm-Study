// 백준 2720번 : 세탁소 사장 동혁
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int T, change;
    int money[4] = { 25, 10, 5, 1 };
    vector<int> ret(4, 0);
    cin >> T;
    
    while (T--) {
        ret.clear();
        cin >> change;

        for (int i = 0; i < 4; i++) {
            ret[i] = change / money[i];
            change %= money[i];
        }
        for (int i = 0; i < 4; i++) {
            cout << ret[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}