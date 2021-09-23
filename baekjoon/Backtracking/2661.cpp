// 백준 2661번 : 좋은수열
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
bool findFlag = false;

bool isValid(string str) {
    int idx = str.length() - 1;

    for (int len = 1; len <= str.length()/2; len++) {
        string base = str.substr(idx - len, len);
        string comp = str.substr(idx, len);

        if (base.compare(comp) == 0) {
            return false;
        }
        idx--;
    }
    return true;
}

void dfs(string candid) {
    if (findFlag) {
        return;
    }
    if (!isValid(candid)) {
        return;
    }
    if (candid.length() == N) {
        cout << candid;
        findFlag = true;
        return;
    }
    for (int i = 1; i <= 3; i++) {
        char ch = i + '0';
        dfs(candid + ch);
    }
}

int main() {
    cin >> N;

    dfs("");

    return 0;
}
