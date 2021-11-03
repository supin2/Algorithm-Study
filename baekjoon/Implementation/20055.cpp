// 백준 20055번 : 컨베이어 벨트 위의 로봇
#include <bits/stdc++.h>

using namespace std;

int N, K, ans;
deque<int> durability;
deque<bool> onConveyor;

int check() {
    int ret = 0;
    for (int i = 0; i < durability.size(); i++) {
        if (durability[i] == 0) {
            ret++;
        }
    }
    return ret;
}

void rotate() {
    durability.push_front(durability.back());
    durability.pop_back();

    onConveyor.push_front(onConveyor.back());
    onConveyor.pop_back();
    onConveyor[N - 1] = false;
}

void move() {
    for (int i = N - 2; i >= 0; i--) {
        if (onConveyor[i] && !onConveyor[i + 1] && durability[i + 1] > 0) {
            onConveyor[i + 1] = true;
            durability[i + 1]--;
            onConveyor[i] = false;
        }
        onConveyor[N - 1] = false;
    }
}

void putRobot() {
    if (durability[0] > 0) {
        onConveyor[0] = true;
        durability[0]--;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> K;

    for (int i = 0, num; i < 2*N; i++) {
        cin >> num;
        durability.push_back(num);
        onConveyor.push_back(false);
    }

    while (true) {
        if (check() >= K) {
            break;
        }
        ans++;
        rotate();
        move();
        putRobot();
    }
    cout << ans;
    return 0;
}
