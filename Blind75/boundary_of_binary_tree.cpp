#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class BoundaryOfBinaryTree {
   private:
    bool isLeaf(TreeNode* node) {
        return node && !node->left && !node->right;
    }

    void addLeaves(TreeNode* node, vector<int>& ans) {
        if (!node) return;
        if (isLeaf(node)) {
            ans.push_back(node->val);
            return;
        }
        addLeaves(node->left, ans);
        addLeaves(node->right, ans);
    }

   public:
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        if (!root) return {};

        vector<int> ans;
        if (!isLeaf(root)) ans.push_back(root->val);

        TreeNode* cur = root->left;
        while (cur) {
            if (!isLeaf(cur)) ans.push_back(cur->val);
            cur = cur->left ? cur->left : cur->right;
        }

        addLeaves(root, ans);

        vector<int> rightBoundary;
        cur = root->right;
        while (cur) {
            if (!isLeaf(cur)) rightBoundary.push_back(cur->val);
            cur = cur->right ? cur->right : cur->left;
        }

        for (int i = rightBoundary.size() - 1; i >= 0; --i) {
            ans.push_back(rightBoundary[i]);
        }

        return ans;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    root->right->right = new TreeNode(4);

    BoundaryOfBinaryTree s;
    vector<int> expected = {1, 3, 4, 2};
    assert(s.boundaryOfBinaryTree(root) == expected);

    cout << "Passed\n";
    return 0;
}
