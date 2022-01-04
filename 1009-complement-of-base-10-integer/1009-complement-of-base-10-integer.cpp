class Solution {
public:
    int bitwiseComplement(int n) {
        string s="";
        if(n==0)
            return 1;
        while(n>0)
        {
            s+=to_string(1-n%2);
            n=n/2;
        }
        int i=1;
        int q=s.size();
   
        int ans=0;
        for(int i=0;i<q;i++)
        {
            ans=ans+(s[i]-'0')*pow(2,i);
        }
        return ans;
            
    }
};