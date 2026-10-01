#include <cassert>
#include <iostream>

using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node* parent;

    Node(int x) : val(x), left(nullptr), right(nullptr), parent(nullptr) {}
};

class LowestCommonAncestorBinaryTreeIII {
   private:
    int depth(Node* node) {
        int d = 0;

        while (node) {
            ++d;
            node = node->parent;
        }

        return d;
    }

   public:
    Node* lowestCommonAncestor(Node* p, Node* q) {
        int dp = depth(p);
        int dq = depth(q);

        while (dp > dq) {
            p = p->parent;
            --dp;
        }

        while (dq > dp) {
            q = q->parent;
            --dq;
        }

        while (p != q) {
            p = p->parent;
            q = q->parent;
        }

        return p;
    }
};

int main() {
    Node* root = new Node(3);
    Node* n5 = new Node(5);
    Node* n1 = new Node(1);
    Node* n6 = new Node(6);

    root->left = n5;
    root->right = n1;
    n5->parent = root;
    n1->parent = root;

    n5->left = n6;
    n6->parent = n5;

    LowestCommonAncestorBinaryTreeIII s;
    assert(s.lowestCommonAncestor(n6, n1) == root);

    cout << "Passed\n";
    return 0;
}
