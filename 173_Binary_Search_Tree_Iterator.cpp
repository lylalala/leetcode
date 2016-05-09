/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
private:
    stack<TreeNode*> node;
public:
    BSTIterator(TreeNode *root) {
        TreeNode* temp=root;
        while(temp!=NULL){
            node.push(temp);
            temp=temp->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !node.empty();
    }

    /** @return the next smallest number */
    int next() {
        int res=node.top()->val;
        TreeNode* temp=node.top();
        node.pop();
        if(temp->right!=NULL){
            temp=temp->right;
            while(temp!=NULL){
                node.push(temp);
                temp=temp->left;
            }
        }
        return res;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
