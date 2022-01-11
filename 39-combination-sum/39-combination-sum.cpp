class Solution {
private:
    void cs(vector<vector<int>>&v , vector<int>&a ,vector<int> &c,int tar,int i)
    {
        if(i==c.size())
        {
         if(tar==0)
          {
            v.push_back(a); 
          }
            return ;
        }
        if(c[i]<=tar)
        {
            a.push_back(c[i]);
            cs(v,a,c,tar-c[i],i);
            a.pop_back();
        }
        cs(v,a,c,tar,i+1);
        
    }
public:
    vector<vector<int>> combinationSum(vector<int>& c, int tar) {
        vector<vector<int>>v;
        vector<int>a;
        cs(v,a,c,tar,0);
        return v;
    }
};