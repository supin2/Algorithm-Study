#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <iostream>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    for (int i = 0; i < n; i++) {
        int row = arr1[i] | arr2[i];
        
        string str = "";
        while(str.length() != n) {
            if (row % 2 == 1) str += "#";
            else str += " ";
            row /= 2;
        }
        reverse(str.begin(), str.end());
        answer.push_back(str);
    }
    return answer;
}