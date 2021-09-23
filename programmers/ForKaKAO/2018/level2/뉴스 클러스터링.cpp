#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string str1, string str2) {
    double answer = 0;
    if (str1 == "" && str2 == "") {
        return 1 * 65536;
    }
    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
    
    vector<string> subset1, subset2;
    for (int i = 0; i < str1.length() - 1; i++) {
        string str = str1.substr(i, 2);
        if (str1[i] >= 'a' && str1[i] <= 'z' && str1[i + 1] >= 'a' && str1[i + 1] <= 'z') {
            subset1.push_back(str);
        }
    }
    for (int i = 0; i < str2.length() - 1; i++) {
        string str = str2.substr(i, 2);
        if (str2[i] >= 'a' && str2[i] <= 'z' && str2[i + 1] >= 'a' && str2[i + 1] <= 'z') {
            subset2.push_back(str);
        }
    }
    
    int unionSize = subset1.size() + subset2.size();
    int intersectSize = 0;
    if (subset1.size() < subset2.size()) {
        for (auto a : subset1) {
            auto iter = find(subset2.begin(), subset2.end(), a);
            if (iter != subset2.end()) {
                intersectSize++;
                subset2.erase(iter);
            }
        }
    } else {
        for (auto a : subset2) {
            auto iter = find(subset1.begin(), subset1.end(), a);
            if (iter != subset1.end()) {
                intersectSize++;
                subset1.erase(iter);
            }
        }
    }
    unionSize -= intersectSize;
    
    if (unionSize == 0) {
        return 65536;
    }
    
    answer = (double) intersectSize / unionSize;
    return answer * 65536;
}