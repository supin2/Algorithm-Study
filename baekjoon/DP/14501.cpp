// 백준 14501번 : 퇴사
#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 15 + 1;
int N;
pair<int, int> schedule[MAX];
int cache[MAX];

int solution(int num) {
    if (num == N + 1) return 0;
    if (num > N + 1) return -987654321;

    int &ret = cache[num];
    if (ret != -1) return ret;

    return ret = max(schedule[num].second + solution(num + schedule[num].first), solution(num + 1));
}

int main() {
    memset(cache, -1, sizeof(cache));

    cin >> N;
    for (int i = 1; i <= N; ++i) {
        cin >> schedule[i].first >> schedule[i].second;
    }
    cout << solution(1) << '\n';
    return 0;
}