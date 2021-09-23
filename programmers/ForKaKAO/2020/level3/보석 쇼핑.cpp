#include <string>
#include <vector>
#include <map>
#include <set>
#include <iostream>

using namespace std;

// 투포인터 알고리즘 이용
vector<int> solution(vector<string> gems) {
    vector<int> answer(2);
    set<string> count(gems.begin(), gems.end()); // 보석이 몇 개인지 체크(중복제외)
    map<string, int> m; 

    int start = 0, end = 0;
    for (auto &a : gems) {
        m[a]++; // 같은 보석이 몇 개씩 있는지 체크
        if (m.size() == count.size()) break; // 모든 보석이 하나 이상 들어온 상태
        end++; // 범위를 늘려줌
    }
    
    int diff = end - start;
    answer[0] = start + 1;
    answer[1] = end + 1;
    
    while (end < gems.size()) {
        string now = gems[start];
        m[now]--; // start가 가리키는 보석을 하나 줄임
        start++; // 앞에 포인터를 움직여봄
        
        if (m[now] == 0) { // 줄인 보석 갯수가 현재 범위 내에 0개가 되면
            end++; // 뒤에 포인터를 움직여봄
            while (end < gems.size()) {
                m[gems[end]]++;
                if (now == gems[end]) break; // 0개가 된 보석과 새로 찾은 보석이 같은 종류면
                end++;
            }
            if (end == gems.size()) break; // 마지막에 도달하면 끝내줌
        }
        if (diff > end - start) { // 가장 짧은 범위 갱신
            diff = end - start;
            answer[0] = start + 1;
            answer[1] = end + 1;
        }  
    }
    return answer;
}