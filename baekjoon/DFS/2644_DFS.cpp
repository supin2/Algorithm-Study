#include <iostream>
#include <cstring>

const int MAX = 101;
int N, Start, End, relations, ans;
int family[MAX][MAX];
bool dist[MAX];

using namespace std;

void DFS(int s, int e, int chonsu) {
    dist[s] = true;

    if (s == e) {
        ans = chonsu;
        return;
    }
    for (int i = 1; i <= N; i++) {
        if (family[s][i] == 1 && !dist[i]) {
            DFS(i, e, chonsu + 1);
        }
    }
    return;
}


int main() {
    cin >> N;
    cin >> Start >> End;
    cin >> relations;

    memset(family, 0, sizeof(family));
    memset(dist, false, sizeof(dist));

    for (int i = 0; i < relations; i++) {
        int parent, child;
        cin >> parent >> child;

        family[parent][child] = 1;
        family[child][parent] = 1;
    }
    DFS(Start, End, 0);
    
    cout << (ans == 0 ? -1 : ans) << '\n';

    return 0;
}