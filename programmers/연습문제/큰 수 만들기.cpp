#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int idx = 0;
    for (int i = 0; i < number.length() - k; i++) {
        char num = -1;
        for (int j = idx; j <= k + i; j++) {
            if (num < number[j]) {
                num = number[j];
                idx = j + 1;
            }
        }
        answer += num;
    }
    return answer;
}