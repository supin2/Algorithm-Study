#include <string>
#include <vector>

using namespace std;

vector<vector<int>> Key, Lock;

void key_check(int arr[58][58], int x, int y, int rot) {
    for (int i = 0; i < Key.size(); i++) {
        for (int j = 0; j < Key.size(); j++) {
            if (rot == 0) {
                arr[x + i][y + j] += Key[i][j];
            } else if (rot == 1) {
                arr[x + i][y + j] += Key[j][Key.size() - 1 - i];
            } else if (rot == 2) {
                arr[x + i][y + j] += Key[Key.size() - 1 - i][Key.size() - 1 - j];
            } else {
                arr[x + i][y + j] += Key[Key.size() - 1 - j][i];
            }
        }
    }
}

bool lock_check(int arr[58][58], int offset) {
    for (int i = 0; i < Lock.size(); i++) {
        for (int j = 0; j < Lock.size(); j++) {
            arr[offset + i][offset + j] += Lock[i][j];
            if (arr[offset + i][offset + j] != 1) {
                return false;
            }
        }
    }
    return true;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = true;
    int offset = key.size() - 1;
    Key = key, Lock = lock;
    
    for (int i = 0; i < offset + lock.size(); i++) {
        for (int j = 0; j < offset + lock.size(); j++) {
            for (int rot = 0; rot < 4; rot++) {
                int arr[58][58] = { 0, };
                key_check(arr, i, j, rot);
                if (lock_check(arr, offset)) {
                    return true;
                }
            }
        }
    }
    return false;
}