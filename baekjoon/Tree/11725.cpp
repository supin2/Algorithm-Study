// 백준 11725번 : 트리의 부모 찾기
#include <iostream>
#include <vector>

using namespace std;

vector<int> v[100001];

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    return 0;
}