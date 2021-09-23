// 백준 1912번 : 연속합
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAX = 100000 + 1;
int n;
int numbers[MAX];
int cache[MAX];

int solution(int num) {
    int ret = cache[1] = numbers[1];
    
    for (int i = 2; i <= n; ++i) {
        cache[i] = max(cache[i - 1] + numbers[i], numbers[i]);
        ret = max(ret, cache[i]);
    }
    return ret;
}

int main() {
    memset(cache, -1, sizeof(cache));
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        cin >> numbers[i];
    }
    cout << solution(n) << '\n';
    return 0;
}