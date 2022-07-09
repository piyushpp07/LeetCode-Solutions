// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long price[], int n)
    {  stack<pair<int,int>>st;
       vector<long long>ans;
       for(int i = 0;i<n;i++)
       {
           if(st.size()==0)
           ans.push_back(-1);
           else if(st.size()>0&&st.top().first<price[i])
           {
               ans.push_back(st.top().second);
           }
           else if(st.size()>0&&st.top().first>=price[i])
           {
               while(st.size()&&st.top().first>=price[i])
               {
                   st.pop();
               }
               if(st.size()==0)
               ans.push_back(-1);
               else{
                ans.push_back(st.top().second);
               }
           }
           st.push({price[i],i});
       }
       while(!st.empty())
       st.pop();
       vector<long long>ans2;
       
       for(int i = n-1;i>=0;i--)
       {
           if(st.size()==0)
           ans2.push_back(n);
           else if(st.size()>0&&st.top().first<price[i])
           {
               ans2.push_back(st.top().second);
           }
           else if(st.size()>0&&st.top().first>=price[i])
           {
               while(st.size()&&st.top().first>=price[i])
               {
                   st.pop();
               }
               if(st.size()==0)
               ans2.push_back(n);
               else{
                ans2.push_back(st.top().second);
               }
           }
           st.push({price[i],i});
       }
       reverse(ans2.begin(),ans2.end());

       long long answer=INT_MIN;
       for(int i = 0;i<n;i++)
       {
           answer = max(answer,price[i]*(ans2[i]-ans[i]-1));
       }
       return answer;
    }
};


// { Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}
  // } Driver Code Ends