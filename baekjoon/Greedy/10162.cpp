// 백준 10162번 : 전자레인지
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int button[3] = { 300, 60, 10 };
    vector<int> v;
    int T, ans = 0;;
    cin >> T;
    string str = to_string(T);

    if (str[str.length() - 1] != '0') ans = -1;
    else {
        for (int i = 0; i < 3; i++) {
            v.push_back(T / button[i]);
            T = T % button[i];
        }
    }
    if (ans == -1) {
        cout << ans << '\n';
    } else {
        for (int i = 0; i < 3; i++) {
            cout << v[i] << ' ';
        }
    }
    return 0;
}