#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <map>

using namespace std;

struct MUSIC {
    int time;
    string title;
    string sheet;
};

map<string, char> transformer;

string transform(string str) {
    string ret = "";
    for (int i = 0; i < str.length(); ) {
        if (str[i + 1] == '#') {
            ret += transformer[str.substr(i, 2)];
            i += 2;
        } else {
            ret += str[i];
            i++;
        }
    }
    return ret;
}

vector<string> split(string input, char delimiter) {
    vector<string> answer;
    stringstream ss(input);
    string temp;
 
    while (getline(ss, temp, delimiter)) {
        answer.push_back(temp);
    }
    return answer;
}

bool compare(pair<int, string> &p1, pair<int, string> &p2) {
    return p1.first > p2.first;
}

string solution(string m, vector<string> musicinfos) {
    string answer = "";
    vector<MUSIC> musics;

    transformer["C#"] = 'V';
    transformer["D#"] = 'W';
    transformer["F#"] = 'X';
    transformer["G#"] = 'Y';
    transformer["A#"] = 'Z';
    
    string t_m = transform(m); // #붙은 음 치환하기
    
    for (int i = 0; i < musicinfos.size(); i++) {
        vector<string> temp = split(musicinfos[i], ','); // (0 : 시작), (1 : 끝시간), (2 : 제목), (3 : 악보)
        int start = stoi(temp[0].substr(0, 2)) * 60 + stoi(temp[0].substr(3, 2));
        int end = stoi(temp[1].substr(0, 2)) * 60 + stoi(temp[1].substr(3, 2));
        int rtime = end - start; // running time 계산
        string sheet = transform(temp[3]);
        
        if (sheet.length() > rtime) {
            sheet = sheet.substr(0, rtime);
        } else {
            for (int j = 0; j < (sheet.length() / rtime) - 1; j++) {
                sheet += sheet;
            }
            for (int j = 0; j < (sheet.length() % rtime); j++) {
                sheet += sheet[j];
            }
        }
        musics.push_back({ rtime, temp[2], sheet });
        temp.clear();
    }
        
    vector<pair<int, string>> ret;
    for (int i = 0; i < musics.size(); i++) {
        if (musics[i].sheet.find(t_m) != string::npos) { // 일치하는 악보가 존재하면
            ret.push_back(make_pair(musics[i].time, musics[i].title));
            sort(ret.begin(), ret.end(), compare); // 재생시간이 긴 순서로 정렬
        }
    }
    if (ret.empty()) {
        answer = "(None)";
    } else {
        answer = ret[0].second;
    }
    
    return answer;
}