#include <string>
#include <vector>
#include <set>
#include <sstream>
#include <iostream>

using namespace std;

string solution(int n, int k, vector<string> cmd) {
    string answer = "";
    set<int> s;
    vector<int> deleted;
    
    for (int i = 0; i < n; i++) {
        s.insert(i);
    }
    auto iter = s.find(k);
    
    for (auto c : cmd) {
        stringstream ss(c);
        char command;
        int count;
        ss >> command >> count;
        
        if (command == 'U') {
            while (count--) {
                iter--;
            }
        } else if (command == 'D') {
            while (count--) {
                iter++;
            }
        } else if (command == 'C') {
            deleted.push_back(*iter);
            if (*iter == *s.rbegin()) { // 마지막 행을 지울 경우
                iter--;
            } else {
                iter++;
            }
            s.erase(deleted.back());
        } else if (command == 'Z') {
            s.insert(deleted.back());
            deleted.pop_back();
        }
    }
    vector<int> temp(n);
    for (int i : s) {
        temp[i] = 1;
    }
    for (int i = 0; i < n; i++) {
        if (temp[i] == 1) {
            answer += 'O';
        } else {
            answer += 'X';
        }
    }
    return answer;
}




#include <string>
#include <vector>
#include <stack>

using namespace std;

struct Node {
    bool removed;
    Node *prev;
    Node *next;
};

Node arr[1000000];

string solution(int n, int k, vector<string> cmd) {
    string answer = "";
    

    for (int i = 1; i < n; i++) {
        arr[i - 1].next = &arr[i];
        arr[i].prev = &arr[i - 1];
    }
    
    Node *curr = &arr[k];
    
    stack<Node*> st;
    for (string str : cmd) {
        if (str[0] == 'U') {
            int x = stoi(str.substr(2));
            for (int i = 0; i < x; i++) {
                curr = curr->prev;
            }
        } else if (str[0] == 'D') {
            int x = stoi(str.substr(2));
            for (int i = 0; i < x; i++) {
                curr = curr->next;
            }
        } else if (str[0] == 'C') {
            st.push(curr);
            curr->removed = true;
            Node *up = curr->prev;
            Node *down = curr->next;
            if (up != nullptr) {
                up->next = down;
            }
            if (down != nullptr) {
                down->prev = up;
                curr = down;
            } else {
                curr = up;
            }
        } else if (str[0] == 'Z') {
            Node *temp = st.top();
            st.pop();
            temp->removed = false;
            Node *up = temp->prev;
            Node *down = temp->next;
            if (up != nullptr) {
                up->next = temp;
            }
            if (down != nullptr) {
                down->prev = temp;
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        if (arr[i].removed) {
            answer.push_back('X');
        } else {
            answer.push_back('O');
        }
    }
    return answer;
}