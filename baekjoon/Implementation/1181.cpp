// 백준 1181번 : 단어 정렬
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(string s1, string s2) {
    if (s1.length() == s2.length()) {
        return s1 < s2;
    }
    return s1.length() < s2.length();
}

int main() {
    vector<string> v;
    int N;
    cin >> N;
    
    while (N--) {
        string str;
        cin >> str;
        v.push_back(str);
    }
    sort(v.begin(), v.end(), cmp);
    v.erase(unique(v.begin(), v.end()), v.end());
    
    for (auto it = v.begin(); it != v.end(); it++) {
        cout << *it << '\n';
    }

    return 0;
}