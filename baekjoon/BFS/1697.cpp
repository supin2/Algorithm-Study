// 백준 1697번 : 숨바꼭질
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX 100001

int N, K;
int cache[MAX];

int BFS() {
    queue<int> q;
    q.push(N);

    while(!q.empty()) {
        int now = q.front();
        q.pop();

        if (now == K) {
            return cache[K];
        }
        int nextStep[3] = { now + 1, now - 1, now * 2 };

        for (int i = 0; i < 3; ++i) {
            if (nextStep[i] >= 0 && nextStep[i] < MAX && cache[nextStep[i]] == 0) {
                cache[nextStep[i]] = cache[now] + 1;
                q.push(nextStep[i]);
            }
        }
    }
}

int main() {
    cin >> N >> K;

    cout << BFS() << '\n';
    return 0;
}