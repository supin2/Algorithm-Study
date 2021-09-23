#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string transform(int num, int n) {
    string ret = "";
    while (num) {
        int tmp = num % n;
        if (tmp == 10) {
            ret += 'A';
        } else if (tmp == 11) {
            ret += 'B';
        } else if (tmp == 12) {
            ret += 'C';
        } else if (tmp == 13) {
            ret += 'D';
        } else if (tmp == 14) {
            ret += 'E';
        } else if (tmp == 15) {
            ret += 'F';
        } else {
            ret += to_string(tmp);
        }
        num /= n;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    
    string str = "0";
    for (int i = 1; i <= t * m; i++) {
        str += transform(i, n);
    }
    for (int i = 0; i < str.length(); i++) {
        if (i % m == p - 1 && answer.length() < t) {
            answer += str[i];
        }
    }
    return answer;
}
























// #include <string>
// #include <vector>
// #include <algorithm>
// #include <iostream>

// using namespace std;

// string transform(int n, int num) {
//     string ret = "";
    
//     if (num == 0) {
//         ret += '0';
//     }
//     while (num) {
//         if (num % n > 9) {
//             switch (num % n) {
//                 case 10 :
//                     ret += 'A';
//                     break;
//                 case 11 :
//                     ret += 'B';
//                     break;
//                 case 12 :
//                     ret += 'C';
//                     break;
//                 case 13 :
//                     ret += 'D';
//                     break;
//                 case 14 :
//                     ret += 'E';
//                     break;
//                 case 15 :
//                     ret += 'F';
//                     break;
//             }
            
//         } else {
//             ret += to_string(num % n);
//         }
//         num /= n;
//     }
//     reverse(ret.begin(), ret.end());
//     return ret;
// }

// string solution(int n, int t, int m, int p) {
//     string answer = "";
//     int num = 0;
//     string notation = "";
//     while (notation.length() < t * m) {
//         notation += transform(n, num++);
//     }

//     for (int i = 0; i < t * m; i++) {
//         if (i % m == p - 1) {
//             answer += notation[i];
//         }
//     }
//     return answer;
// }