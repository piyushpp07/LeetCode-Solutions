//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*
The structure of the class is as follows
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
*/

class Solution{

    stack<int> st;
    map<int,int>mp;
    public:
    
       /*returns min element from stack*/
       int getMin(){
            if(st.size() == 0)
        return -1;
        int no = 0;
        for(auto i : mp)
        {
            no = i.first;
            break;
        }
        return no;
       }
       
       /*returns poped element from stack*/
       int pop(){
           
           //Write your code here
        if(st.size() == 0)
        return -1;
        int no = st.top();
        st.pop();
        mp[no]--;
        if(mp[no] == 0)
        mp.erase(no);
        return no;
       }
       
       /*push element x into the stack*/
       void push(int val){
        st.push(val);
        mp[val]++;
       }
};

//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int q;
        cin>>q;
        Solution ob;
        while(q--){
           int qt;
           cin>>qt;
           if(qt==1)
           {
              //push
              int att;
              cin>>att;
              ob.push(att);
           }
           else if(qt==2)
           {
              //pop
              cout<<ob.pop()<<" ";
           }
           else if(qt==3)
           {
              //getMin
              cout<<ob.getMin()<<" ";
           }
       }
       cout<<endl;
    }
    return 0;
}

// } Driver Code Ends