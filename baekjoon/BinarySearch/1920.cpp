// 백준 1920번 : 수 찾기
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> vec;

int binarySearch(int num) {
    int first = 0, last = N - 1;
    while (first <= last) {
        int mid = (first + last)/2;
        if (vec[mid] == num) {
            return 1;
        }
        if (vec[mid] < num) {
            first = mid + 1;
        } else {
            last = mid - 1;
        }
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        int input;
        cin >> input;
        vec.push_back(input);
    }
    sort(vec.begin(), vec.end());
    
    cin >> M;

    for (int i = 0; i < M; i++) {
        int num;
        cin >> num;
        cout << binarySearch(num) << '\n';
    }
    return 0;
}