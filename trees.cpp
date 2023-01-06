#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    public:
    TreeNode* buildTree(vector<int> &A, vector<int> &B);
};

TreeNode* bT(vector<int> &postOrder, vector<int> &inOrder, int POS, int POE, int IOS, int IOE, unordered_map <int, int> &hM) {
    // base case?
    if( POS > POE )
        return NULL;

    // looking at the inorder traversal, you can figure out    
    
    int curRoot = postOrder[POE]; // given post order traversal, you can say what is the root of the tree
    TreeNode* root = new TreeNode(curRoot);
    int idx = hM[curRoot]; // where the root lies

    // the left of root is left sub tree
    root->left = bT(postOrder, inOrder, POS, POE-1 - (IOE-(idx+1))-1,IOS, idx-1, hM);

    // the right of root is right sub tree
    root->right = bT(postOrder, inOrder, POE-1 - (IOE-(idx+1)), POE-1,idx+1, IOE, hM);

    return root;


}

unordered_map <int, int> bHM (vector<int> inOrder) {
    // this is built to facilitate faster search
    unordered_map <int, int> ans;
    for(int i=0; i<inOrder.size(); i++) {
        ans.insert({inOrder[i], i}); // not writing any else cases because my array has unique elements
    }
    return ans;
}

TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {
    unordered_map <int, int> helperMap;
    helperMap = bHM(B);
    return bT(B, A, 0, B.size()-1, 0, A.size()-1, helperMap);
}

int main() {
    Solution myObj;
    vector<int> A = { 2, 1, 3 };
    vector<int> B = { 2, 3, 1 };
    myObj.buildTree(A, B);
    cout << "testing...";
    return 0;
}
