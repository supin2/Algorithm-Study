// 백준 1063번 : 킹
#include <bits/stdc++.h>

using namespace std;

int arr[8][8];

bool isValid(int y, int x) {
    if (y < 0 || y >= 8 || x < 0 || x >= 8) {
        return false;
    }
    return true;
}

void func(int nkY, int nkX, int nsY, int nsX) {

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    string king, stone;
    int move;
    cin >> king >> stone >> move;
    
    int ky = 8 - (king[1] - '0');
    int kx = king[0] - 'A';
    int sy = 8 - (stone[1] - '0');
    int sx = stone[0] - 'A';
    arr[ky][kx] = 1;
    arr[sy][sx] = 2;
    
    for (int i = 0; i < move; i++) {
        string s;
        cin >> s;
        
        int nkY = ky, nkX = kx;
        int nsY = sy, nsX = sx;
        if (s == "R") {
            nkX = kx + 1;
            if (isValid(nkY, nkX)) {
                if (arr[nkY][nkX] == 2) {
                    nsX = sx + 1;
                    if (isValid(nsY, nsX)) {
                        arr[nsY][nsX] = 2;
                        arr[nkY][nkX] = 1;
                        arr[ky][kx] = 0;
                        ky = nkY, kx = nkX;
                        sy = nsY, sx = nsX;
                    }
                } else {
                    arr[ky][kx] = 0;
                    arr[nkY][nkX] = 1;
                    ky = nkY, kx = nkX;
                }
            }
        } else if (s == "L") {
            nkX = kx - 1;
            if (isValid(nkY, nkX)) {
                if (arr[nkY][nkX] == 2) {
                    nsX = sx - 1;
                    if (isValid(nsY, nsX)) {
                        arr[nsY][nsX] = 2;
                        arr[nkY][nkX] = 1;
                        arr[ky][kx] = 0;
                        ky = nkY, kx = nkX;
                        sy = nsY, sx = nsX;
                    }
                } else {
                    arr[ky][kx] = 0;
                    arr[nkY][nkX] = 1;
                    ky = nkY, kx = nkX;
                }
            }
        } else if (s == "B") {
            nkY = ky + 1;
            if (isValid(nkY, nkX)) {
                if (arr[nkY][nkX] == 2) {
                    nsY = sy + 1;
                    if (isValid(nsY, nsX)) {
                        arr[nsY][nsX] = 2;
                        arr[nkY][nkX] = 1;
                        arr[ky][kx] = 0;
                        ky = nkY, kx = nkX;
                        sy = nsY, sx = nsX;
                    }
                } else {
                    arr[ky][kx] = 0;
                    arr[nkY][nkX] = 1;
                    ky = nkY, kx = nkX;
                }
            }
        } else if (s == "T") {
            nkY = ky - 1;
            if (isValid(nkY, nkX)) {
                if (arr[nkY][nkX] == 2) {
                    nsY = sy - 1;
                    if (isValid(nsY, nsX)) {
                        arr[nsY][nsX] = 2;
                        arr[nkY][nkX] = 1;
                        arr[ky][kx] = 0;
                        ky = nkY, kx = nkX;
                        sy = nsY, sx = nsX;
                    }
                } else {
                    arr[ky][kx] = 0;
                    arr[nkY][nkX] = 1;
                    ky = nkY, kx = nkX;
                }
            }
        } else if (s == "RT") {
            nkY = ky - 1;
            nkX = kx + 1;
            if (isValid(nkY, nkX)) {
                if (arr[nkY][nkX] == 2) {
                    nsY = sy - 1;
                    nsX = sx + 1;
                    if (isValid(nsY, nsX)) {
                        arr[nsY][nsX] = 2;
                        arr[nkY][nkX] = 1;
                        arr[ky][kx] = 0;
                        ky = nkY, kx = nkX;
                        sy = nsY, sx = nsX;
                    }
                } else {
                    arr[ky][kx] = 0;
                    arr[nkY][nkX] = 1;
                    ky = nkY, kx = nkX;
                }
            }
        } else if (s == "LT") {
            nkY = ky - 1;
            nkX = kx - 1;
            if (isValid(nkY, nkX)) {
                if (arr[nkY][nkX] == 2) {
                    nsY = sy - 1;
                    nsX = sx - 1;
                    if (isValid(nsY, nsX)) {
                        arr[nsY][nsX] = 2;
                        arr[nkY][nkX] = 1;
                        arr[ky][kx] = 0;
                        ky = nkY, kx = nkX;
                        sy = nsY, sx = nsX;
                    }
                } else {
                    arr[ky][kx] = 0;
                    arr[nkY][nkX] = 1;
                    ky = nkY, kx = nkX;
                }
            }
        } else if (s == "RB") {
            nkY = ky + 1;
            nkX = kx + 1;
            if (isValid(nkY, nkX)) {
                if (arr[nkY][nkX] == 2) {
                    nsY = sy + 1;
                    nsX = sx + 1;
                    if (isValid(nsY, nsX)) {
                        arr[nsY][nsX] = 2;
                        arr[nkY][nkX] = 1;
                        arr[ky][kx] = 0;
                        ky = nkY, kx = nkX;
                        sy = nsY, sx = nsX;
                    }
                } else {
                    arr[ky][kx] = 0;
                    arr[nkY][nkX] = 1;
                    ky = nkY, kx = nkX;
                }
            }
        } else if (s == "LB") {
            nkY = ky + 1;
            nkX = kx - 1;
            if (isValid(nkY, nkX)) {
                if (arr[nkY][nkX] == 2) {
                    nsY = sy + 1;
                    nsX = sx - 1;
                    if (isValid(nsY, nsX)) {
                        arr[nsY][nsX] = 2;
                        arr[nkY][nkX] = 1;
                        arr[ky][kx] = 0;
                        ky = nkY, kx = nkX;
                        sy = nsY, sx = nsX;
                    }
                } else {
                    arr[ky][kx] = 0;
                    arr[nkY][nkX] = 1;
                    ky = nkY, kx = nkX;
                }
            }
        }
    }
    
    string A = "";
    char ch = (8 - ky) + '0';
    char ch2 = kx + 'A';
    A += ch2;
    A += ch;
    
    cout << A << '\n';

    A = "";
    ch = (8 - sy) + '0';
    ch2 = sx + 'A';
    A += ch2;
    A += ch;

    cout << A;
    return 0;
}
