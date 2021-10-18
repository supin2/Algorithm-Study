// 백준 8595번 : 히든 넘버
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    string str;
    cin >> n >> str;

    string tmp = "";
    long long sum = 0;
    for (char ch : str) {
        if (isdigit(ch)) {
            tmp += ch;
        } else {
            if (tmp.length() != 0) {
                sum += stoll(tmp);
                tmp = "";
            }
        }
    }
    if (tmp.length() != 0) {
        sum += stoll(tmp);
    }
    cout << sum;
    return 0;
}