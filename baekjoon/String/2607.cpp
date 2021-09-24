// 백준 2607번 : 비슷한 단어
#include <iostream>

using namespace std;

int main() {
    int N = 0, ans = 0;
    string first_str = "";
    int total_cnt = 0;
    int firstWord[26] = { 0, };

    cin >> N >> first_str;

    for (char ch : first_str) {
        firstWord[ch - 'A']++;
        total_cnt++;
    }

    for (int i = 0; i < N - 1; i++) {
        int used[26] = { 0, };
        int used_cnt = 0;
        string str = "";
        cin >> str;

        for (char ch : str) {
            used[ch - 'A']++;
            used_cnt++;
        }

        if (abs(total_cnt - used_cnt) > 1) { // 문자열 길이 차이가 2이상
            continue;
        }

        int diff1 = 0, diff2 = 0;
        bool flag = true;
        for (int i = 0; i < 26; i++) {
            if (abs(firstWord[i] - used[i]) > 1) { // 사용하는 갯수가 2개 이상 차이나면
                flag = false;
                break;
            } else if (firstWord[i] > used[i]) {
                diff1++;
            } else if (firstWord[i] < used[i]) {
                diff2++;
            }

            if (diff1 > 1 || diff2 > 1) {
                flag = false;
                break;
            }
        }
        if (flag) {
            ans++;
        }
    }
    cout << ans;
    return 0;
}