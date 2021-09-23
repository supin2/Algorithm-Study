// 백준 3020번 : 개똥벌레
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int ans = 987654321;
    int route = 1;
    int N, H;
    cin >> N >> H;

    vector<int> bottom; // 석순
    vector<int> top; // 종유석

    for (int i = 0; i < N/2; i++) {
        int a, b;
        cin >> a >> b;
        bottom.push_back(a);
        top.push_back(b);
    }
    sort(bottom.begin(), bottom.end());
    sort(top.begin(), top.end());

    for (int i = 1; i <= H; i++) {
        int stones = bottom.size() - (lower_bound(bottom.begin(), bottom.end(), i) - bottom.begin()); // 통과하는 석순 갯수
        stones += top.size() - (upper_bound(top.begin(), top.end(), H - i) - top.begin()); // 통과하는 종유석 갯수

        if (ans > stones) {
            route = 1;
            ans = stones;
        } else if (ans == stones) {
            route++;
        }
    }
    cout << ans << " " << route << '\n';
    return 0;
}