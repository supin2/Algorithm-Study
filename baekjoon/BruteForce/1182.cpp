// 백준 1182번 : 부분수열의 합
#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 20;

int N, S, ans = 0;
int arr[MAX];

void solution(int idx, int sum) {
    sum += arr[idx];

    if (idx >= N) {
        return;
    }
    if (sum == S) {
        ans++;
    }
    solution(idx + 1, sum - arr[idx]);
    solution(idx + 1, sum);
}

int main() {
	cin >> N >> S;
	
	for (int i = 0; i < N; ++i) {
		cin >> arr[i];	
	}

    solution(0, 0);
	
	cout << ans << '\n';
	
	return 0;
}