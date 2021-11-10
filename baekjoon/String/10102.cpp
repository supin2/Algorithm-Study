// 백준 10102번 : 개표
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int V;
    string str;
    cin >> V >> str;

    int Acnt = 0, Bcnt = 0;
    for (char ch : str) {
        if (ch == 'A') {
            Acnt++;
        } else {
            Bcnt++;
        }
    }
    if (Acnt > Bcnt) {
        cout << 'A';
    } else if (Acnt < Bcnt) {
        cout << 'B';
    } else {
        cout << "Tie";
    }
    return 0;
}