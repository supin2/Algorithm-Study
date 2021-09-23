#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<string> c_user_id;
vector<string> c_banned_id;
bool visited[9] = { false, };
set<string> s;

void DFS(int idx) {
    if (idx == c_banned_id.size()) {
        string tmp = "";
        for (int i = 0; i < 9; i++) {
            if (visited[i]) tmp += to_string(i); // 선택된 user_id들의 index를 string으로 이어붙여줌
        }
        sort(tmp.begin(), tmp.end()); // 중복을 제거하기 위해서 정렬 후 set에 넣어줌
        s.insert(tmp);
        return;
    }
    
    for (int i = 0; i < c_user_id.size(); i++) { // user_id 목록 하나씩 탐색
        string checking_id = c_user_id[i]; // 현재 확인 중인 user_id
        if (checking_id.length() != c_banned_id[idx].length()) { // 현재 확인 중인 banned_id와 길이가 다르면
            continue;
        } 
        if (visited[i]) { // 이미 체크된 user_id이면
            continue;
        } 
        
        bool match_flag = true;
        for (int j = 0; j < c_banned_id[idx].length(); j++) {
            char ch = c_banned_id[idx][j];
            if (ch == '*') { // '*'일 경우 패스
                continue;
            }
            if (checking_id[j] != ch) { // 매칭이 안됨
                match_flag = false;
                break;
            }
        }
        if (match_flag) { // 매칭이 됐을 경우
            visited[i] = true;
            DFS(idx + 1); // 다음 banned_id에 매칭되는 user_id를 찾기 위해 재귀호출
            visited[i] = false;
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    
    c_user_id = user_id; // 전역변수로 이용하기 위해 복사
    c_banned_id = banned_id;
    
    DFS(0); // banned_id[0] 부터 시작
    answer = s.size();
    
    return answer;
}