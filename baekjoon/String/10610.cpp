// 백준 10610번 : 30
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    string str = "";
    cin >> str;

    long long maxNum = 0;

    sort(str.begin(), str.end(), greater<>());

    if (str.back() != '0') {
        cout << -1;
    } else {
        for (char ch : str) {
            maxNum += ch - '0';
        }
        if (maxNum % 3 == 0) {
            cout << str;
        } else {
            cout << -1;
        }
    }
    
    return 0;
}