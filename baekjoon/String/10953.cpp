// 백준 10953번 : A + B - 6
#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int a, b;
        string line;
        cin >> line;

        a = stoi(line.substr(0, 1));
        b = stoi(line.substr(2));

        cout << a + b << '\n';
    }
    return 0;
}