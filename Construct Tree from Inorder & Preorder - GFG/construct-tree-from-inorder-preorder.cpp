// { Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

 // } Driver Code Ends


/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    private:
    map<int,int>mp;
    public:
    Node *solve(int pre[],int ps,int pe,int in[],int ins,int ine)
    {
        if(ps>pe||ins>ine)
        return NULL;
        Node *root = new Node(pre[ps]);
        int inRoot = mp[root->data];
        int numsLeft = inRoot - ins;
        root->left = solve(pre,ps+1,ps+numsLeft,in,ins,inRoot-1);
        root->right = solve(pre,ps+numsLeft+1,pe,in,inRoot+1,ine);
        return root;
        
    }
    Node* buildTree(int in[],int pre[], int n)
    {   
        for(int i = 0;i<n;i++)
        mp[in[i]] = i;
        return solve(pre,0,n-1,in,0,n-1);
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}
  // } Driver Code Ends