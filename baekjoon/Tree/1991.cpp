// 백준 1991번 : 트리 순회
#include <iostream>
#include <vector>

using namespace std;

pair<char, char> tree[26];

void preorder(char root) {
    if (root == '.') return;
    else {
        cout << root;
        preorder(tree[root].first);
        preorder(tree[root].second);
    }
}
void inorder(char root) {
    if (root == '.') return;
    else {
        inorder(tree[root].first);
        cout << root;
        inorder(tree[root].second);
    }
}
void postorder(char root) {
    if (root == '.') return;
    else {
        postorder(tree[root].first);
        postorder(tree[root].second);
        cout << root;
    }
}

int main() {
    int N;
    char parent, left, right;

    cin >> N;

    while (N--) {
        cin >> parent >> left >> right;
        tree[parent] = make_pair(left, right);
    }
    preorder('A');
    cout << '\n';
    inorder('A');
    cout << '\n';
    postorder('A');

    return 0;
}