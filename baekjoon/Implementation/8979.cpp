// 백준 8979번 : 올림픽
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Nation {
    int country, gold, silver, bronze;
};

bool cmp(Nation a, Nation b) {
    if (a.gold == b.gold) {
        if (a.silver == b.silver) {
            return a.bronze > b.bronze;
        }
        return a.silver > b.silver;
    }
    return a.gold > b.gold;
}

int main()
{
    int N, K;
    cin >> N >> K;
    
    vector<Nation> v(N);
    
    for (int i = 0; i < N; i++) {
        cin >> v[i].country >> v[i].gold >> v[i].silver >> v[i].bronze;
    }
    sort(v.begin(), v.end(), cmp);
    
    int i;
    for (i = 0; i < v.size(); i++) {
        if (v[i].country == K) {
            break;
        }
    }
    
    Nation n = v[i];
    int same = 0;
    for (int j = i - 1; j >= 0; j--) {
        Nation temp = v[j];
        if (temp.gold == n.gold && temp.silver == n.silver && temp.bronze == n.bronze) {
            same++;
        }
    }
    int rank = i - same + 1;
    
    cout << rank;
    return 0;
}
