// 백준 1339번 : 단어 수학
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, ans = 0;
    vector<string> v;
    int alphabet[26] = { 0, };

    cin >> N;
    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        
        int cnt = 1;
        for (int j = str.length() - 1; j >= 0; j--) {
            alphabet[str[j] - 'A'] += cnt;
            cnt *= 10;
        }
    }
    sort(alphabet, alphabet + 26, greater<int>());

    int num = 9;
    for (int i = 0; i < 26; i++) {
        if (alphabet[i] == 0) break;
        ans += alphabet[i] * num;
        num--;
    }
    cout << ans << '\n';
    return 0;
}