// 백준 10815번 : 숫자 카드
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> cards;

int BinarySearch(int num) {
    int first = 0, last = N - 1;
    while (first <= last) {
        int mid = (first + last)/2;

        if (cards[mid] == num) {
            return 1;
        } else if (cards[mid] < num) {
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
        int card;
        cin >> card;
        cards.push_back(card);
    }
    sort(cards.begin(), cards.end());
    
    cin >> M;
    for (int i = 0; i < M; i++) {
        int num;
        cin >> num;
        cout << BinarySearch(num) << " ";
    }
    return 0;
}