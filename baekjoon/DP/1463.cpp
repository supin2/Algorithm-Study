// 백준 1463번 : 1로 만들기
#include <iostream>
#include <cstring>

using namespace std;

#define MAX 1000001

int N;
int cache[MAX];

int solution(int num) {
    int &ret = cache[num];
    if (ret != -1) {
        return ret;
    }
    if (num == 1) {
        return 0;
    }

    ret = solution(num - 1) + 1;
    if (num % 2 == 0) ret = min(ret, solution(num / 2) + 1);
    if (num % 3 == 0) ret = min(ret, solution(num / 3) + 1);

    return ret;
}


int main() {
    cin >> N;
    memset(cache, -1, sizeof(cache));

    cache[0] = 0;

    cout << solution(N) << '\n';

    return 0;
}