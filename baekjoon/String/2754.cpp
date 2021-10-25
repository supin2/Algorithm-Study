// 백준 2754번 : 학점계산
#include <bits/stdc++.h>

using namespace std;

int main() {
    string str;
    cin >> str;

    double ret = 0.0;
    switch (str[0]) {
        case 'A' :
            ret = 4.0;
            break;
        case 'B' :
            ret = 3.0;
            break;
        case 'C' :
            ret = 2.0;
            break;
        case 'D' :
            ret = 1.0;
            break;
        case 'F' :
            ret = 0.0;
            break;
    }
    switch (str[1]) {
        case '+' :
            ret += 0.3;
            break;
        case '-' :
            ret -= 0.3;
            break;
    }
    cout << fixed;
    cout.precision(1);
    cout << ret;
    return 0;
}