#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

int convert(string str) {
    stringstream ss(str);
    int H, M, S;
    char colon;
    ss >> H >> colon >> M >> colon >> S;
        
    return H * 60 * 60 + M * 60 + S;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";
    int playTime = convert(play_time);
    int advTime = convert(adv_time);
    
    vector<int> range(playTime + 1, 0);
    
    for (string log : logs) {
        int start = convert(log.substr(0, 8));
        int end = convert(log.substr(9));
        
        for (int i = start; i < end; i++) {
            range[i] += 1;
        }
    }
    
    long long sum = 0;
    for (int i = 0; i < advTime; i++) {
        sum += range[i];
    }
    
    long long ans = sum;
    int idx = 0;
    for (int i = advTime; i < playTime; i++) {
        sum = sum + range[i] - range[i - advTime];
        if (sum > ans) {
            ans = sum;
            idx = i - advTime + 1;
        }
    }
    int HH = (idx / 3600);
    idx %= 3600;
    int MM = (idx / 60);
    idx %= 60;
    int SS = idx;
    if (HH < 10) {
        answer += "0" + to_string(HH);
    } else {
        answer += to_string(HH);
    }
    answer += ":";
    if (MM < 10) {
        answer += "0" + to_string(MM);
    } else {
        answer += to_string(MM);
    }
    answer += ":";
    if (SS < 10) {
        answer += "0" + to_string(SS);
    } else {
        answer += to_string(SS);
    }
    // char buf[10];
    // sprintf(buf, "%02d:%02d:%02d", idx/3600, idx/60%60, idx%60);
    // answer = buf;
    return answer;
}