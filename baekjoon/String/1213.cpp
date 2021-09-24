// 백준 1213번 : 팰린드롬 만들기
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    string str = "", ret = "";
    int alpha[26] = { 0, };
    cin >> str;

    for (char ch : str) {
        alpha[ch - 'A']++;
    }
    
    int cnt = 0;
    for (int num : alpha) {
        if (num % 2 == 1) {
            cnt++;
        }
        if (cnt > 1) {
            cout << "I'm Sorry Hansoo";
            return 0;
        }
    }

    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < alpha[i]/2; j++) {
            ret += i + 'A';
        }
    }

    for (int i = 0; i < 26; i++) {
        if (alpha[i] % 2 == 1) {
            ret += i + 'A';
        }
    }

    for (int i = 25; i >= 0; i--) {
        for (int j = 0; j < alpha[i]/2; j++) {
            ret += i + 'A';
        }
    }

    cout << ret;
    return 0;
}