#include <algorithm>
#include <cassert>
#include <iostream>
#include <tuple>
#include <vector>
using namespace std;
struct TreeNode {
    int val; TreeNode* left; TreeNode* right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};
class VerticalOrderTraversalBinaryTree {
    vector<tuple<int,int,int>> nodes;
    void dfs(TreeNode* node,int row,int col){
        if(!node) return;
        nodes.push_back({col,row,node->val});
        dfs(node->left,row+1,col-1);
        dfs(node->right,row+1,col+1);
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root){
        nodes.clear();
        dfs(root,0,0);
        sort(nodes.begin(),nodes.end());
        vector<vector<int>> ans;
        int lastCol=0; bool first=true;
        for(auto [col,row,val]:nodes){
            if(first||col!=lastCol){ ans.push_back({}); lastCol=col; first=false; }
            ans.back().push_back(val);
        }
        return ans;
    }
};
int main(){
    TreeNode* root=new TreeNode(3);
    root->left=new TreeNode(9); root->right=new TreeNode(20);
    root->right->left=new TreeNode(15); root->right->right=new TreeNode(7);
    VerticalOrderTraversalBinaryTree s;
    vector<vector<int>> expected={{9},{3,15},{20},{7}};
    assert(s.verticalTraversal(root)==expected);
    cout<<"Passed\n";
    return 0;
}
