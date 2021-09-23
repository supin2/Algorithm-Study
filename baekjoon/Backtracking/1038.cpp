// 백준 1038번 : 감소하는 수
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> v;

bool isValid(string num) {
    if (stoi(num) <= 10) {
        return true;
    }

    for (int i = 0; i < num.length() - 1; i++) {
        if (num[i] <= num[i + 1]) {
            return false;
        }
    }
    return true;
}

bool dfs(int cnt, string candid) {
    if (cnt == N) {
        
        return true;
    }

    for (int i = 0; i <= 9; i++) {
        char ch = i + '0';
        if (isValid(candid + ch)) {
            int num = stoi(candid + ch);
            cout << num << ' ';
            v.push_back(num);
            if (dfs(cnt + 1, candid + ch)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    cin >> N;
    if (N == 0) {
        cout << "0";
        return 0;
    }

    bool ret = dfs(0, "");
    if (!ret) {
        cout << "-1";
    } else {
        cout << v.back();
    }
    return 0;
}