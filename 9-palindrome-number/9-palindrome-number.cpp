class Solution {
public:
    bool isPalindrome(int x) {
     string a=to_string(x);
        int n=a.length();
       int i=0;
        while(i<n/2)
        {
            if(a[i]!=a[n-i-1])
                return false;
            i++;
        }
        return true;
    }
};