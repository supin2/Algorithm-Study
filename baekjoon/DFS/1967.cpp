// 백준 1967번 : 트리의 지름
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

const int MAX = 10000 + 1;
int n;
vector<pair<int, int>> v[MAX];


int main() {
    cin >> n;

    int parent, child, weight;
    for (int i = 0; i < n - 1; ++i) {
        cin >> parent >> child >> weight;
        v[parent].push_back(make_pair(child, weight));
        v[child].push_back(make_pair(parent, weight));
    }

    return 0;
}