// 백준 9417번 : 최대 GCD
#include <bits/stdc++.h>

using namespace std;

vector<int> v;
vector<bool> visited;
int ret = -1e8;

int gcd(int a, int b) {
    while (b != 0) {
        int c = a % b;
        a = b;
        b = c;
    }
    return a;
}

void dfs(int idx, int cnt) {
    if (cnt == 2) {
        vector<int> nums;
        for (int i = 0; i < visited.size(); i++) {
            if (visited[i]) {
                nums.push_back(v[i]);
            }
        }
        ret = max(ret, gcd(nums[0], nums[1]));
        return;
    }

    for (int i = idx; i < v.size(); i++) {
        if (!visited[i]) {
            visited[i] = true;
            dfs(i, cnt + 1);
            visited[i] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    cin.ignore();

    for (int i = 0; i < N; i++) {
        string nums = "";
        getline(cin, nums);
        
        v.clear();
        visited.resize(101, false);

        stringstream ss(nums);
        string temp;
        while (getline(ss, temp, ' ')) {
            v.push_back(stoi(temp));
        }
        dfs(0, 0);
        
        cout << ret << '\n';
        ret = -1e8;
    }
    return 0;
}