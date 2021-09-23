#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <algorithm>
#include <iostream>

using namespace std;

unordered_map<string, int> um;

vector<int> List[4][3][3][3];

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    um["-"] = 0;
    um["cpp"] = 1;
    um["java"] = 2;
    um["python"] = 3;
    um["backend"] = 1;
    um["frontend"] = 2;
    um["junior"] = 1;
    um["senior"] = 2;
    um["chicken"] = 1;
    um["pizza"] = 2;
    
    for (string str : info) {
        stringstream ss(str);
        string lang, job, career, food;
        int score;
        ss >> lang >> job >> career >> food >> score;
        
        int applicant[4] = { um[lang], um[job], um[career], um[food] };
        
        for (int i = 0; i < (1 << 4); i++) {
            int idx[4] = { 0, };
            for (int j = 0; j < 4; j++) {
                if (i & (1 << j)) {
                    idx[j] = applicant[j];
                }
            }
            List[idx[0]][idx[1]][idx[2]][idx[3]].push_back(score);
        }
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                for (int l = 0; l < 3; l++) {
                    sort(List[i][j][k][l].begin(), List[i][j][k][l].end());
                }
            }
        }
    }
    
    for (string str : query) {
        stringstream ss(str);
        string lang, job, career, food, temp;
        int score;
        ss >> lang >> temp >> job >> temp >> career >> temp >> food >> score;
        
        auto &search = List[um[lang]][um[job]][um[career]][um[food]];
        auto low = lower_bound(search.begin(), search.end(), score);
        
        cout << *low << endl;
        answer.push_back(search.end() - low);
    }
    
    return answer;
}