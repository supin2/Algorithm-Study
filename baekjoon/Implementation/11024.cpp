// 백준 11024번 : 더하기 4
#include <iostream>
#include <sstream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    cin.ignore();

    while (T--) {
        string str;
        getline(cin, str);

        string tmp = "";
        int sum = 0;
        for (int i = 0; i < str.length(); i++) {
            if (isdigit(str[i])) {
                tmp += str[i];
            } else {
                sum += stoi(tmp);
                tmp = "";
            }   
        }
        sum += stoi(tmp);
        cout << sum << '\n';
    }
    return 0;
}