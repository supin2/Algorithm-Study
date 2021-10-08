// 백준 2571번 : 수 정렬하기 2
#include <iostream>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    set<int> s;
    int N;
    cin >> N;

    for (int i = 0, num; i < N; i++) {
        cin >> num;
        s.insert(num);
    }
    for (auto it = s.begin(); it != s.end(); it++) {
        printf("%d\n", *it);
    }
    return 0;
}