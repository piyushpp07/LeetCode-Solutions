/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {

        vector<vector<int>>ans;
                if(!root)
            return ans;
        queue<Node*>q;
        q.push(root);
        while(!q.empty())
        {
           
            int n=q.size();
            vector<int>curr;
            for(int i=0;i<n;i++)
            {
                Node *a=q.front();
                q.pop();
                curr.push_back(a->val);
               
                for(auto i: a->children)
               {
                q.push(i);
               }
           
            }
 ans.push_back(curr);  
        }
        return ans;
    }
};