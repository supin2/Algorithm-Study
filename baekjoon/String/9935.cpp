// 백준 9935번 : 문자열 폭발
#include <iostream>
#include <stack>

using namespace std;

int main() {
    string str, bomb;
    string ret = "";

    cin >> str >> bomb;

    for (int i = 0; i < str.length(); i++) {
        int len = bomb.length();
        ret += str[i];

        if (ret[ret.length() - 1] == bomb.back()) {
            if (ret.length() - len >= 0) {
                int cnt = 0;
                for (int j = bomb.length() - 1; j >= 0; j--) { 
                    if (ret[ret.length() - (bomb.length() - j)] == bomb[j]) {
                        cnt++;
                    }
                }
                if (cnt == bomb.length()) {
                    for (int j = 0; j < cnt; j++) {
                        ret.pop_back();
                    }
                }
            }
        }
    }
    if (ret.length() == 0) {
        cout << "FRULA";
    } else {
        cout << ret;
    }
    return 0;
}


// 백준 9935번 : 문자열 폭발
// #include <iostream>
// #include <stack>

// using namespace std;

// int main() {
//     string str, bomb;
//     string ret = "";

//     cin >> str >> bomb;

//     for (int i = 0; i < str.length(); i++) {
//         int len = bomb.length();
//         ret += str[i];

//         if (ret[ret.length() - 1] == bomb.back()) {
//             if (ret.length() - len >= 0) {
//                 string tmp = ret.substr(ret.length() - len, len);

//                 if (tmp.compare(bomb) == 0) {
//                     for (int j = 0; j < cnt; j++) {
//                         ret.pop_back();
//                     }
//                 }
//             }
//         }
//     }
//     if (ret.length() == 0) {
//         cout << "FRULA";
//     } else {
//         cout << ret;
//     }
//     return 0;
// }