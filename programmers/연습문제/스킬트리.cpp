#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    
    for (string st : skill_trees) {
        string tmp = "";
        for (char ch : st) {
            if (skill.find(ch) != string::npos) {
                tmp += ch;
            }
        }
        if (skill.find(tmp) == 0) {
            answer++;
        }
    }
    return answer;
}


// #include <string>
// #include <vector>
// #include <iostream>

// using namespace std;

// int solution(string skill, vector<string> skill_trees) {
//     int answer = 0;
    
//     for (string str : skill_trees) {
//         bool flag = true;
//         for (int i = 0; i < skill.size(); i++) {
//             char ch = skill[i];
//             if (str.find(ch) != string::npos) {
//                 int pos = str.find(ch);
//                 for (int j = i + 1; j < skill.size(); j++) {
//                     if (str.find(skill[j]) != string::npos) {
//                         if (pos > str.find(skill[j])) {
//                             flag = false;
//                             break;
//                         } else {
//                             pos = str.find(skill[j]);
//                         }
//                     }
//                 }
//             } else {
//                 for (int j = i + 1; j < skill.size(); j++) {
//                     if (str.find(skill[j]) != string::npos) {
//                         flag = false;
//                         break;
//                     } 
//                 }
//             }
//             if (flag == false) {
//                 break;
//             }
//         }
//         if (flag == true) {
//             answer++;
//         }
//     }
    
//     return answer;
// }