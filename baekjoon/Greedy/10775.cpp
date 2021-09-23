// 백준 10775번 : 공항
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int G, P;
    cin >> G >> P;
    vector<int> airplane(P);

    for (int i = 0; i < P; i++) {
        cin >> airplane[i];
    }
    return 0;
}