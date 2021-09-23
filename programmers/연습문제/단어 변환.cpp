#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

#define INF 987654321

string Target;
vector<string> Words;
bool checked[51];
int answer;

void dfs(string begin, int cnt) {
    for (int i = 0; i < Words.size(); i++) {
        if (checked[i] == true) {
            continue;
        }
        int num = 0;
        for (int j = 0; j < Words[i].size(); j++) {
            if (Words[i][j] != begin[j]) {
                num++;
            }
            if (num > 1) {
                break;
            }
        }
        if (num == 1) {
            if (Words[i] == Target) {
                answer = min(answer, cnt + 1);
                return;
            }
            checked[i] = true;
            dfs(Words[i], cnt + 1);
            checked[i] = false;
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    answer = INF;
    Target = target, Words = words;
    memset(checked, false, sizeof(checked));
    
    if (find(words.begin(), words.end(), target) != words.end()) {
        dfs(begin, 0);
    } else {
        return 0;
    }
    
    return answer;
}