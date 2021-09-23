// 백준 1744번 : 수 묶기
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    int N, one = 0, zero = 0, sum = 0;
    priority_queue<int> positive; // 내림차순
    priority_queue<int, vector<int>, greater<int>> negative; // 오름차순
    
    cin >> N;
    while (N--) {
        int num;
        cin >> num;

        if (num == 0) zero++;
        else if (num == 1) one++;
        else if (num > 1) positive.push(num);
        else negative.push(num);
    }

    if (positive.size() % 2) { // 양수가 홀수 개이면
        positive.push(1);
    }
    if (negative.size() % 2) { // 음수가 홀수 개이면
        if (zero > 0) {
            negative.push(0);
        } else {
            negative.push(1);
        }
    }
    
    int tmp1, tmp2;
    while(!positive.empty()) {
        tmp1 = positive.top();
        positive.pop();
        tmp2 = positive.top();
        positive.pop();
        sum += (tmp1 * tmp2);
    }

    while(!negative.empty()) {
        tmp1 = negative.top();
        negative.pop();
        tmp2 = negative.top();
        negative.pop();
        sum += (tmp1 * tmp2);
    }

    cout << sum + one << '\n';
    return 0;
}