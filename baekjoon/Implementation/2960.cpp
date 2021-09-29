// 백준 2960번 : 에라토스테네스의 체
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    
    set<int> s;
    vector<int> ret;
    
    for (int i = 2; i <= N; i++) {
        s.insert(i);
    }
    
    while (K) {
        int num = *s.begin();
        int tmp = num;
        
        for (int i = 1; tmp <= N; i++) {
            tmp = num * i;

            if (s.find(tmp) != s.end()) {
                s.erase(tmp);
                ret.push_back(tmp);
                --K;
                if (K == 0) {
                    break;
                }
            }
        }
    }
    cout << ret.back();
    return 0;
}