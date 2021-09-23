// 백준 10816번 : 숫자 카드 2
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    vector<int> cards;
    
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
        cout << upper_bound(cards.begin(), cards.end(), num) - lower_bound(cards.begin(), cards.end(), num) << " ";
    }

    return 0;
}