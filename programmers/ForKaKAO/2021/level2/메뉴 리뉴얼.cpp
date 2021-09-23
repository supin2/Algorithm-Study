#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

map<string, int> m[11];
int maxCnt[11] = { 0, };


void sol(string str, int pos, string candi) {
    if (pos >= str.length()) {
        int len = candi.length();
        if (len >= 2) {
            m[len][candi]++;
            maxCnt[len] = max(maxCnt[len], m[len][candi]);
        }
        return;
    }
    sol(str, pos + 1, candi);
    sol(str, pos + 1, candi + str[pos]);
}


vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    
    for (string str : orders) {
        sort(str.begin(), str.end());
        sol(str, 0, "");
    }
    for (int len : course) {
        for (auto item : m[len]) {
            if (item.second >= 2 && item.second == maxCnt[len]) {
                answer.push_back(item.first);
            }
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}