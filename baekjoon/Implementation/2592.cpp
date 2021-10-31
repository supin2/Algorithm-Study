// 백준 2592번 : 대표값
#include <iostream>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int sum = 0, maxNum, maxCnt = -1;
    map<int, int> m;

    for (int i = 0; i < 10; i++) {
        int num;
        cin >> num;
        sum += num;
        m[num]++;
        if (m[num] > maxCnt) {
            maxNum = num;
            maxCnt = m[num];
        }
    }
    cout << sum / 10 << '\n' << maxNum;
    return 0;
}