/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node *solve(vector<vector<int>>grid,int sr,int er,int sc,int ec)
    {
        if(sr>er || sc >ec)
            return NULL;
        bool isLeaf = true;
        int val = grid[sr][sc];
        for(int i =sr;i<=er;i++)
        {
            for(int j = sc;j<=ec;j++)
            {
                if(val != grid[i][j])
                {
                    isLeaf = false;
                    break;
                }
            }
            if(!isLeaf)
                break;
        }
        if(isLeaf)
            return new Node(val,true);
        int midr = (sr + er)/2;
        int midc = (sc + ec)/2;
        
        Node *topLeft = solve(grid,sr,midr,sc,midc);
        Node *topRight = solve(grid,sr,midr,midc+1,ec);
        Node *bottomLeft = solve(grid,midr+1,er,sc,midc);
        Node *bottomRight = solve(grid,midr+1,er,midc+1,ec);
        return new Node(false,false,topLeft,topRight,bottomLeft,bottomRight);
        
    }
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        return solve(grid,0,n-1,0,n-1);
    }
};