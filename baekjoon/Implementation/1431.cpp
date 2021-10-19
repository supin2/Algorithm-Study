// 백준 1431번 : 시리얼 번호
#include <bits/stdc++.h>

using namespace std;

struct alpha {
    int len, sum;
    string code;
};

bool cmp(alpha a, alpha b) {
    if (a.len == b.len) {
        if (a.sum == b.sum) {
            return a.code < b.code;
        }
        return a.sum < b.sum;
    }
    return a.len < b.len;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int N;
    cin >> N;

    vector<alpha> v;

    while (N--) {
        string str;
        cin >> str;
        int len = str.length();
        int sum = 0;
        for (char ch : str) {
            if (isdigit(ch)) {
                sum += ch - '0';
            }
        }
        v.push_back({ len, sum, str });
    }
    sort(v.begin(), v.end(), cmp);

    for (auto a : v) {
        cout << a.code << '\n';
    }
    return 0;
}