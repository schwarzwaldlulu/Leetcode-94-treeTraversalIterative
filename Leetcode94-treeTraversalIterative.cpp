/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        if( root == nullptr )
            return result;
        else
        {
            result = inorderTraversal( root -> left );
            result.push_back( root -> val );
            vector<int> right = inorderTraversal( root -> right );
            result.insert( result.end(), right.begin(), right.end() );
            
        }
        return result;
    }
    
    // using data structure stack to print out the value of the nodes;
    // first save the left nodes, from the root to the most left leaf, then pop the nodes from the stack. If the node has right children, then push the nodes in the
    // right child tree in stack.
    
    vector<int> inorderTraversal_iterative( TreeNode* root )
    {
        vector<int> result;
        stack< TreeNode* > roots;
        
        while( root != nullptr || !roots.empty() )
        {
            while( root != nullptr )
            {
                roots.push( root );
                root = root -> left;
            }
            
            TreeNode* pCurRoot = roots.top();
            result.push_back( pCurRoot -> val );
            roots.pop();
            
            if ( pCurRoot -> right != nullptr )
                root = pCurRoot -> right;
        }
        
        return result;
    }
};
