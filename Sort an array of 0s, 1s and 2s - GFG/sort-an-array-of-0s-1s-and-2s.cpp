// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
class Solution
{
    public:
    void sort012(int a[], int n)
    {
    int low = 0,high = n-1,mid = 0;
    while(mid<=high)
    {   int p=0,q=0;
        if(a[mid]==0)
        {
            swap(a[mid++],a[low++]);
            p = 1;
        }
        else if(a[mid]==1)
        {
            mid++;
            q=1;
        }
        else if(a[mid]==2)
        {
            swap(a[mid],a[high--]);
            p=1;
        }
        if(p==0&&q==0)
        break;
     }
    }
    
};

// { Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}

  // } Driver Code Ends