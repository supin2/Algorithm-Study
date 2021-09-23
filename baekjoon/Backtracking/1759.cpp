// 백준 1759번 : 암호 만들기
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;

const int MAX = 15;
int L, C;
char alphabet[MAX];
char vowel[5] = { 'a', 'e', 'i', 'o', 'u' };
vector<string> ans;
vector<char> V1, V2;
map<string, bool> visit;

void solution(int idx, int jdx, int vowel_cnt, int consonant_cnt, string s) {
    if (s.length() == L) { // 암호 완성
        if (vowel_cnt >= 1 && consonant_cnt >= 2) {
            sort(s.begin(), s.end());
            if (!visit.count(s)) { // 암호가 만들어진적 없으면
                visit[s] = true;
                ans.push_back(s);
            }
        }
        return;
    }

    for (int i = idx + 1; i < V1.size(); ++i) {
        solution(i, jdx, vowel_cnt + 1, consonant_cnt, s + V1[i]);
    }
    for (int j = jdx + 1; j < V2.size(); ++j) {
        solution(idx, j, vowel_cnt, consonant_cnt + 1, s + V2[j]);
    }
}

int main() {
    cin >> L >> C;

    for (int i = 0; i < C; ++i) {
        cin >> alphabet[i];
        if (find(vowel, vowel + 5, alphabet[i]) != (vowel + 5)) {
            V1.push_back(alphabet[i]); // 모음
        } else {
            V2.push_back(alphabet[i]); // 자음
        }
    }
    sort(V1.begin(), V1.end());
    sort(V2.begin(), V2.end());

    solution(-1, -1, 0, 0, "");

    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << '\n';
    }
    return 0;
}