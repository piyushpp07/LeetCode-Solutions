class Solution {
    private:
    string arr[10]={"","", "abc","def", "ghi","jkl","mno","pqrs","tuv","wxyz"};
    int first=0;
public:
    
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0&&first==0)
        {   
            vector<string>ans;
            return ans;
        }
        else if (digits.size()==0&&first!=0)
        {
            vector<string>ans;
            ans.push_back("");
            return ans;
            
        }
              first++;
        vector<string>ans;
        int ch=digits[0]-'0';
        vector<string>q=letterCombinations(digits.substr(1,digits.length()));
  
        cout<<q.size();
        for(auto m:q){
    
                      
         for(int i=0;i<arr[ch].length();i++)
 
            {
              cout<<m;
                ans.push_back(arr[ch][i]+m);
            }
        }
        return ans;
    }
};