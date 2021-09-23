#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

vector<int> candidate_key;

bool isMinimal(int num) {
    for (int i = 0; i < candidate_key.size(); i++) {
        if ((num & candidate_key[i]) == candidate_key[i]) {
            return false;
        }
    }
    candidate_key.push_back(num);
    return true;
}

int solution(vector<vector<string>> relation) {
    int len = relation.size();
    int N = relation[0].size();
    
    int a = 4, b = 7;
    
    cout << (a & b) << endl;

    for (int i = 1; i < (1 << N); i++) {
        set<string> mySet;
        for (int k = 0; k < len; k++) {
            string tmp = "";
            for (int j = 0; j < N; j++) {
                if (i & (1 << j)) {
                    tmp += relation[k][j];
                }
            }
            mySet.insert(tmp);
        }
        if (mySet.size() != len) { // 유일성 검증
            continue;
        }
        if (!isMinimal(i)) { // 최소성 검증
            continue;
        }
    }
    return candidate_key.size();
}