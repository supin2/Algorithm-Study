#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

long long calculate(long long a, long long b, char op) {
    switch (op) {
        case '+' :
            return a + b;
        case '-' :
            return a - b;
        case '*' :
            return a * b;
    }
}

long long solution(string expression) {
    long long answer = 0;
    vector<char> optr;
    vector<char> exist_optr;
    vector<long long> opnd;
    
    string temp = "";
    for (int i = 0; i < expression.length(); i++) {
        char ch = expression[i];
        if (ch >= '0' && ch <= '9') {
            temp += ch;
        } else {
            opnd.push_back(stoll(temp));
            optr.push_back(ch);
            exist_optr.push_back(ch);
            temp = "";
        }
    }
    opnd.push_back(stoll(temp));
    
    sort(exist_optr.begin(), exist_optr.end());
    exist_optr.erase(unique(exist_optr.begin(), exist_optr.end()), exist_optr.end());
    
    do {
        vector<long long> temp_opnd = opnd;
        vector<char> temp_optr = optr;
        
        for (int i = 0; i < exist_optr.size(); i++) {
            for (int j = 0; j < temp_optr.size(); ) {
                if (exist_optr[i] == temp_optr[j]) {
                    temp_opnd[j] = calculate(temp_opnd[j], temp_opnd[j + 1], exist_optr[i]);
                    temp_opnd.erase(temp_opnd.begin() + j + 1);
                    temp_optr.erase(temp_optr.begin() + j);
                } else {
                    j++;
                }
            }
        }
        answer = max(answer, abs(temp_opnd[0]));
    } while(next_permutation(exist_optr.begin(), exist_optr.end()));
    return answer;
}