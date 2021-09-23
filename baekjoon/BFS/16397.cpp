// 백준 16397번 : 탈출
#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int MAX = 99999 + 1;
int N, T, G;
bool visited[MAX];

int BFS() {
    queue<pair<int, int>> q;
    q.push(make_pair(N, 0)); // 시작숫자, 버튼 누를 수 있는 횟수
    visited[N] = true;

    while(!q.empty()) {
        int now = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if (cnt > T) {
            return -1;
        }
        if (now == G) {
            return cnt;
        }

        int tmp;
        tmp = now + 1;
        if (tmp < MAX && !visited[tmp]) {
            visited[tmp] = true;
            q.push(make_pair(tmp, cnt + 1));
        }
        
        tmp = now * 2;

        int digit = 1;
        int cal = tmp;
        while(cal) {
            cal /= 10;
            digit *= 10;
        }
        digit /= 10;
        if (tmp < MAX) {
            if (tmp - digit < MAX && !visited[tmp - digit]) {
                visited[tmp - digit] = true;
                q.push(make_pair(tmp - digit, cnt + 1));
            }
        }
    }
    return -1;
}

int main() {
    cin >> N >> T >> G;
    memset(visited, false, sizeof(visited));
    int ret = BFS();

    if (ret == -1) {
        cout << "ANG" << '\n';
    } else {
        cout << ret << '\n';
    }
    return 0;
}