//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


// } Driver Code Ends
//User function Template for C++


class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> lists, int K)
    {
         vector<int> rv;
  int k = lists.size();
  priority_queue<int,vector<int>,greater<int>>pq;
  int maxidx = 0;
  for(int i = 0;i<k;i++)
  {
     if(maxidx<lists[i].size())
     maxidx = lists[i].size();
  }
  int curridx = 0;
  for(int i = 0;i<k;i++)
     pq.push(lists[i][0]);
  curridx++;
  while(curridx < maxidx)
  {
     for(int i = 0;i<lists.size();i++)
     {
        if(lists.size()>curridx)
        {
           pq.push(lists[i][curridx]);
        }
        if(pq.size()>k*k)
        {
           rv.push_back(pq.top());
           pq.pop();
        }
     }
     curridx++;
  }
  while(pq.size())
  {
     rv.push_back(pq.top());
     pq.pop();
  }
   
  return rv;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}






// } Driver Code Ends