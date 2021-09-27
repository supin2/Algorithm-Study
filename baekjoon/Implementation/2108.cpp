#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> v;
    int count[8001] = { 0, };
    int sum = 0;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        sum += num;
        count[num + 4000]++;
        v.push_back(num);
    }
    sort(v.begin(), v.end());

    int maxCnt = *max_element(count, count + 8001);
    int mostNum, cnt = 0;
    for (int i = 0; i < 8001; i++) {
        if (cnt == 2) {
            break;
        }
        if (count[i] == maxCnt) {
            mostNum = i;
            cnt++;
        }
    }
    mostNum -= 4000;

    cout << round((double) sum/N) << '\n' << v[N/2] << '\n' << mostNum << '\n' << v.back() - v.front();
    return 0;
}