#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    int num, x, y;
    Node* left;
    Node* right;
};

bool compare(Node n1, Node n2) {
    if (n1.y == n2.y) {
        return n1.x < n2.x;
    }
    return n1.y > n2.y;
}

void makeTree(Node *root, Node *child) {
    if (root->x > child->x) {
        if (root->left == NULL) {
            root->left = child;
        } else {
            makeTree(root->left, child);
        }
    } else {
        if (root->right == NULL) {
            root->right = child;
        } else {
            makeTree(root->right, child);
        }
    }
}

void preorder(vector<int> &v, Node *root) {
    if (root == NULL) return;
    v.push_back(root->num);
    preorder(v, root->left);
    preorder(v, root->right);
}

void postorder(vector<int> &v, Node *root) {
    if (root == NULL) return;
    postorder(v, root->left);
    postorder(v, root->right);
    v.push_back(root->num);
}


vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer = {{}, {}};
    vector<Node> node;
    
    for (int i = 0; i < nodeinfo.size(); i++) {
        node.push_back({ i + 1, nodeinfo[i][0], nodeinfo[i][1] });
    }
    sort(node.begin(), node.end(), compare);
    
    Node *root = &node[0];
    
    for (int i = 1; i < node.size(); i++) {
        makeTree(root, &node[i]);
    }
    preorder(answer[0], root);
    postorder(answer[1], root);
    
    return answer;
}