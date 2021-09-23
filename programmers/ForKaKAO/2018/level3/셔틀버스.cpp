#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int convert(string t) {
    return stoi(t.substr(0, 2)) * 60 + stoi(t.substr(3, 2));
}

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    vector<int> tt;
    for (string str : timetable) {
        tt.push_back(convert(str));
    }
    sort(tt.begin(), tt.end());
    
    int departure = 540; // default : 09:00
    int idx = 0, conn;
    for (int i = 0; i < n; i++) {
        int limit = 0;
        for (int j = idx; j < tt.size(); j++) {
            if (tt[j] <= departure) {
                limit++;
                idx++;
                if (limit == m) {
                    break;
                }
            }
        }
        if (i + 1 < n) { // 막차가 아니면
            departure += t;
        } else { // 막차라면
            if (limit == m) {
                conn = tt[idx - 1] - 1;
            } else if (limit < m) {
                conn = departure;
            }
        }
    }
    char buf[5];
    sprintf(buf, "%02d:%02d", conn / 60, conn % 60);
    answer = buf;
    return answer;
}



















// #include <string>
// #include <vector>
// #include <algorithm>

// using namespace std;

// string solution(int n, int t, int m, vector<string> timetable) {
//     string answer = "";
    
//     vector<int> crew;
//     for (string str : timetable) {
//         string HH = str.substr(0, 2);
//         string MM = str.substr(3);
        
//         int time = stoi(HH) * 60 + stoi(MM);
//         crew.push_back(time);
//     }
//     sort(crew.begin(), crew.end());
    
//     int start = 540;
//     int conTime = 0;
//     int passenger = 0; // 탑승객 체크
//     for (int i = 0; i < n; i++) {
//         int limit = 0;
//         for (int j = passenger; j < crew.size(); j++) {
//             if (crew[j] <= start) { // 셔틀 출발시간 전에 대기중인 사람들이면 모두 탑승
//                 passenger++;
//                 limit++;
//             }
//             if (limit == m) { // 정원이 꽉차면
//                 break;
//             }
//         }
        
//         if (i + 1 == n) { // 현재 셔틀이 마지막 셔틀이면
//             if (limit == m) { // 이미 대기줄 꽉 찼으면
//                 conTime = crew[passenger - 1] - 1; // 대기줄의 마지막 사람보다 1분 일찍오기
//             } else { 
//                 conTime = start; // 자리 있으면 그냥 기준시간에 도착
//             }
//         } else { // 마지막 셔틀이 아니면
//             start += t; // 다음 배차시간으로 넘어감
//         }
//     }
    
//     // "HH:MM" 형식으로 변환
//     int H = conTime / 60;
//     int M = conTime % 60;
//     string hr = "", min = "";
//     if (H < 10) {
//         hr = "0" + to_string(H);
//     } else {
//         hr = to_string(H);
//     }
//     if (M < 10) {
//         min = "0" + to_string(M);
//     } else {
//         min = to_string(M);
//     }
//     answer = hr + ":" + min;
    
//     return answer;
// }