// 백준 2501번 : 약수 구하기
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int N, K;
    scanf("%d %d", &N, &K);
    
    vector<int> v;
    for (int i = 1; i <= N; i++) {
        if (N % i == 0) {
            v.push_back(i);
        }
    }
    sort(v.begin(), v.end());
    
    if (v.size() < K) {
        printf("0");
    } else {
        printf("%d", v[K - 1]);
    }

    return 0;
}
