// 백준 1316번 : 그룹 단어 체커
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, ans = 0;
    string str = "";
    vector<int> v(100);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> str;

        bool flag = true;
        v.clear();
        for (int j = 0; j < str.length(); j++) {
            int idx = str[j] - 'a';
            auto iter = find(v.begin(), v.end(), idx);
            
            if (iter == v.end()) { // 같은 게 없을 때
                v.push_back(idx);
            } else { // 같은 게 있을 때
                if (idx == v.back()) {
                    v.push_back(idx);
                } else {
                    flag = false;
                    break;
                }
            }
        }
        if (flag) ans++;
    }
    cout << ans << '\n';
    return 0;
}