// 백준 2490번 : 윷놀이
#include <iostream>

using namespace std;

int main() {
    for (int i = 0; i < 3; i++) {
        int cnt = 0;
        for (int j = 0; j < 4; j++) {
            int a;
            cin >> a;
            if (a == 0) {
                cnt++;
            }
        }
        switch (cnt) {
            case 0 :
                cout << "E\n";
                break;
            case 1 :
                cout << "A\n";
                break;
            case 2 :
                cout << "B\n";
                break;
            case 3 :
                cout << "C\n";
                break;
            case 4 :
                cout << "D\n";
                break;
        }
    }
    return 0;
}