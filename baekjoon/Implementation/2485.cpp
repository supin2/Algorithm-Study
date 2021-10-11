// 백준 2485번 : 가로수
#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, before, ans = 0;
    vector<int> v;
    cin >> N;
    cin >> before;

    for (int i = 0, next; i < N - 1; i++) {
        cin >> next;
        v.push_back(next - before);
        before = next;
    }

    int diff = v[0];
    for (int i = 1; i < v.size(); i++) {
        diff = gcd(diff, v[i]);
    }
    for (int i = 0; i < v.size(); i++) {
        ans += v[i] / diff - 1;
    }
    cout << ans;
    return 0;
}