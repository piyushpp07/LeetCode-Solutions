class Solution {
public:
    void solve(int n,vector<string>&v)
    {
        if(n%3 == 0 and n% 5 ==0)
            v.push_back("FizzBuzz");
        else if(n%3 == 0)
            v.push_back("Fizz");
        else if(n%5 == 0)
            v.push_back("Buzz");
        else
            v.push_back(to_string(n));
    }
    vector<string> fizzBuzz(int n) {
        vector<string>v;
        for(int i = 1;i<=n;i++)
        {
            solve(i,v);
        }
        return v;

    }
};