#include <string>
#include <vector>

using namespace std;

int solution(int n) { // 투포인터
    int answer = 0;
    int a = 1, b = 1;
    int sum = 1;
    
    while (true) {
        if (a > n) {
            break;
        }
        if (sum == n) {
            answer++;
            b++;
            sum += b;
        } else {
            if (sum < n) {
                b++;
                sum += b;
            } else {
                sum -= a;
                a++;
            }
        }
    }
    return answer;
}


// #include <string>
// #include <vector>

// using namespace std;

// int solution(int n) { // 완전탐색
//     int answer = 0;
    
//     for (int i = 1; i <= n; i++) {
//         int sum = 0;
//         for (int j = i; j <= n; j++) {
//             sum += j;
//             if (sum > n) {
//                 break;
//             } else if (sum == n) {
//                 answer++;
//                 break;
//             }
//         }
//     }
//     return answer;
// }