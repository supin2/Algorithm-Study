#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int M;
    cin >> M;
    
    int ret = 0;
        
    while (M--) {
        string action = "";
        int num;
        
        cin >> action;
        
        if (action == "add") {
            cin >> num;
            ret |= (1 << (num - 1));
        } else if (action == "remove") {
            cin >> num;
            ret &= ~(1 << (num - 1));
        } else if (action == "check") {
            cin >> num;
            if (ret & (1 << (num - 1))) {
                cout << 1 << '\n';
            } else {
                cout << 0 << '\n';
            }
        } else if (action == "toggle") {
            cin >> num;
            ret ^= (1 << (num - 1));
        } else if (action == "all") {
            ret = (1 << 20) - 1;
        } else if (action == "empty") {
            ret = 0;
        }
    }
    return 0;
}