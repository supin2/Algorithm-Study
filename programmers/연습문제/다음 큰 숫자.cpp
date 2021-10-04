#include <string>
#include <vector>

using namespace std;

int count(int num) {
    int cnt = 0;
    while (num) {
        if (num % 2) {
            cnt++;
        }
        num /= 2;
    }
    return cnt;
}

int solution(int n) {
    int cnt = count(n);
    
    int next;
    for (next = n + 1; ; next++) {
        if (cnt == count(next)) {
            break;
        }
    }
    return next;
}