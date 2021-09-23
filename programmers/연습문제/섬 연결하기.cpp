#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(vector<int> v1, vector<int> v2) {
    return v1[2] < v2[2];
}

int getParent(int parent[], int x) {
    if (parent[x] == x) {
        return x;
    }
    return parent[x] = getParent(parent, parent[x]);
}

void Union(int parent[], int a, int b) {
    a = getParent(parent, a);
    b = getParent(parent, b);
    if (a < b) {
        parent[b] = a;
    } else {
        parent[a] = b;
    }
}

bool Find(int parent[], int a, int b) {
    a = getParent(parent, a);
    b = getParent(parent, b);
    if (a == b) {
        return true;
    } else {
        return false;
    }
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    int parent[101];
    
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }
    sort(costs.begin(), costs.end(), compare);
    
    for (auto c : costs) {
        if (Find(parent, c[0], c[1]) == false) {
            answer += c[2];
            Union(parent, c[0], c[1]);
        }
    }
    return answer;
}