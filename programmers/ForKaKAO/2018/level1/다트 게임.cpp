#include <string>
#include <cmath>
#include <vector>
#include <iostream>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    
    vector<int> v;
    for (int i = 0; i < dartResult.size(); i++) {
        string str = "";
        char ch = dartResult[i];
        if (isdigit(ch) == true) {
            str += ch;
            if (dartResult[i + 1] == '0') {
                str += '0';
                i++;
            }
            v.push_back(stoi(str));
        } else {
            int num = v.back();
            v.pop_back();
            if (ch == 'S') {
                v.push_back(num);
            } else if (ch == 'D') {
                v.push_back(pow(num, 2));
            } else if (ch == 'T') {
                v.push_back(pow(num, 3));
            } else if (ch == '*') {
                if (v.size() > 0) {
                    int num1 = v.back();
                    v.pop_back();
                    v.push_back(num1 * 2);
                    v.push_back(num * 2);
                } else {
                    v.push_back(num * 2);
                }
            } else if (ch == '#') {
                v.push_back(num * (-1));
            }
        }
    }
    for (int i : v) {
        answer += i;
    }
    
    return answer;
}