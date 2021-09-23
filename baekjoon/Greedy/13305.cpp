// 백준 13305번 : 주유소
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    long long r, c, ans = 0;
    vector<long long> road;
    vector<long long> city;

    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        cin >> r;
        road.push_back(r);
    }
    for (int i = 0; i < N; i++) {
        cin >> c;
        city.push_back(c);
    }
    long long cheap = city[0];

    for (int i = 0; i < N - 1; i++) {
        if (cheap > city[i]) {
            cheap = city[i];
        } 
        ans += cheap * road[i];
    }
    cout << ans << '\n';
    return 0;
}