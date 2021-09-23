#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string new_id) {
    string answer = "";
    transform(new_id.begin(), new_id.end(), new_id.begin(), ::tolower);
    
    for (auto it = new_id.begin(); it != new_id.end(); ) {
        if (*it == '-' || *it == '_' || *it == '.' || (*it >= 'a' && *it <= 'z') || (*it >= '0' && *it <= '9')) {
            it++;
            continue;
        } else {
            new_id.erase(it);            
        }
    }
    int cnt = 0;
    for (auto it = new_id.begin(); it != new_id.end(); ) {
        if (*it == '.') {
            cnt++;
            if (cnt >= 2) {
                new_id.erase(it);
                continue;
            }
            it++;
        } else {
            cnt = 0;
            it++;
        }
    }
    if (new_id[0] == '.') {
        new_id.erase(new_id.begin());
    }
    if (new_id.length() == 0) {
        new_id += "a";
    }
    if (new_id.length() >= 16) {
        new_id = new_id.substr(0, 15);
    }
    if (new_id[new_id.length() - 1] == '.') {
        new_id.erase(new_id.end() - 1);
    }
    if (new_id.length() <= 2) {
        char ch = new_id[new_id.length() - 1];
        while (new_id.length() < 3) {
            new_id += ch;
        }
    }
    return new_id;
}