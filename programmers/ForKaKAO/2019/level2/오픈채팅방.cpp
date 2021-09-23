#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

vector<string> split(string input, char delimiter) {
    vector<string> answer;
    stringstream ss(input);
    string temp;
 
    while (getline(ss, temp, delimiter)) {
        answer.push_back(temp);
    }
    return answer;
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> id_info;
    
    for (auto str : record) {
        vector<string> v = split(str, ' ');
        if (v[0] == "Enter") {
            id_info[v[1]] = v[2];
        } else if (v[0] == "Change") {
            id_info[v[1]] = v[2];
        }
    }
    for (auto str : record) {
        vector<string> v = split(str, ' ');
        if (v[0] == "Enter") {
            answer.push_back(id_info[v[1]] + "님이 들어왔습니다.");
        } else if (v[0] == "Leave") {
            answer.push_back(id_info[v[1]] + "님이 나갔습니다.");
        } else {
            continue;
        }
    }
    return answer;
}