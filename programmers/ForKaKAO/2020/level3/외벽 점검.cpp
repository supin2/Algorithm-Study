;#include <string>
#include <vector>

using namespace std;

#define INF 987654321

int N, ret;
vector<int> Weak, Dist;

void check(int cnt, int start, int visit) {
    if (cnt > Dist.size()) {
        return;
    }
    for (int i = 0; i < Weak.size(); i++) {
        int next = (start + i) % Weak.size();
        int dist = Weak[next] - Weak[start];
        if (next < start) {
            dist += N;
        }
        
        if (dist > Dist[Dist.size() - cnt]) {
            break;
        }
        visit |= (1 << next);
    }
    if (visit == (1 << Weak.size()) - 1) {
        ret = min(ret, cnt);
    }
    for (int i = 0; i < Weak.size(); i++) {
        if (visit & (1 << i)) continue;
        check(cnt + 1, i, visit);
    }
}

int solution(int n, vector<int> weak, vector<int> dist) {
    N = n, Weak = weak, Dist = dist;
    ret = INF;
    
    for (int i = 0; i < Weak.size(); i++) {
        check(1, i, 0);
    }
    if (ret == INF) {
        return -1;
    }
    return ret;
}