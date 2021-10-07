// 백준 1969번 : DNA
#include <iostream>
#include <vector>

using namespace std;

int cache[51][4];

int main() {
    int N, M, ans = 0;
    string ret = "";
    cin >> N >> M;
    
    vector<string> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            switch (v[j][i]) {
                case 'A' :
                    cache[i][0]++;
                    continue;
                case 'C' :
                    cache[i][1]++;
                    continue;
                case 'G' :
                    cache[i][2]++;
                    continue;
                case 'T' : 
                    cache[i][3]++;
                    continue;
            }
        }
    }
    
    for (int i = 0; i < M; i++) {
        int dna = 0, maxCnt = 0;
        for (int j = 0; j < 4; j++) {
            if (cache[i][j] > maxCnt) {
                dna = j;
                maxCnt = cache[i][j];
            }
        }
        ans += (N - maxCnt);
        
        switch (dna) {
            case 0 :
                ret += 'A';
                continue;
            case 1 :
                ret += 'C';
                continue;
            case 2 :
                ret += 'G';
                continue;
            case 3 :
                ret += 'T';
                continue;
        }
    }
    cout << ret << '\n' << ans;
    return 0;
}
