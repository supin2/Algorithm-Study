#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct File {
    int idx;
    string HEAD;
    int NUMBER;
    string TAIL;
};

bool compare(File f1, File f2) {
    if (f1.HEAD.compare(f2.HEAD) == 0) {
        return f1.NUMBER < f2.NUMBER;
    } 
    return f1.HEAD < f2.HEAD;
}

// bool compare(tuple<int, string, int, string> t1, tuple<int, string, int, string> t2) {
//     if (get<1>(t1) == get<1>(t2)) {
//         return get<2>(t1) < get<2>(t2);
//     }
//     return get<1>(t1) < get<1>(t2);
// }

vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<string> cFiles = files;
    vector<File> file_info;
    
    for (int i = 0; i < cFiles.size(); i++) {
        transform(cFiles[i].begin(), cFiles[i].end(), cFiles[i].begin(), ::tolower);
        
        for (int j = 0; j < cFiles[i].size(); j++) {
            if (isdigit(cFiles[i][j]) == true) {
                int pos = j;
                while (true) {
                    if (isdigit(cFiles[i][j]) == true) {
                        j++;
                    } else {
                        break;
                    }
                }
                file_info.push_back({ i, cFiles[i].substr(0, pos), stoi(cFiles[i].substr(pos, j - pos)), cFiles[i].substr(j)});
                break;
            }
        }
    }
    stable_sort(file_info.begin(), file_info.end(), compare);
    
    for (auto a : file_info) {
        answer.push_back(files[a.idx]);
    }
    
    return answer;
}

// #include <string>
// #include <vector>
// #include <algorithm>
// #include <iostream>

// using namespace std;

// bool compare(pair<pair<string, string>, string> p1, pair<pair<string, string>, string> p2) {
//     transform(p1.first.first.begin(), p1.first.first.end(), p1.first.first.begin(), ::tolower);
//     transform(p2.first.first.begin(), p2.first.first.end(), p2.first.first.begin(), ::tolower);
    
//     int num1 = stoi(p1.first.second);
//     int num2 = stoi(p2.first.second);
    
//     if (p1.first.first == p2.first.first) {
//         return num1 < num2;
//     }
//     return p1.first.first < p2.first.first;
// }


// vector<string> solution(vector<string> files) {
//     vector<string> answer;
//     vector<pair<pair<string, string>, string>> vec;
    
//     int order = 1;
//     for (string str : files) {
//         int idx = 0;
//         for (int i = 0; i < str.length(); i++) {
//             if (str[i] >= '0' && str[i] <= '9') {
//                 break;
//             } else {
//                 idx++;
//             }
//         }
        
//         int jdx = idx;
//         for (int j = idx; j < str.length(); j++) {
//             if (str[j] >= '0' && str[j] <= '9') {
//                 jdx++;
//             } else {
//                 break;
//             }
//         }
//         string head = str.substr(0, idx);
//         string number = str.substr(idx, jdx - idx);
//         string tail = str.substr(jdx);
//         vec.push_back({ { head, number }, tail });
//     }
//     stable_sort(vec.begin(), vec.end(), compare);
    
//     for (int i = 0; i < vec.size(); i++) {
//         string tmp = vec[i].first.first + vec[i].first.second + vec[i].second;
//         answer.push_back(tmp);
//     }
//     return answer;
// }