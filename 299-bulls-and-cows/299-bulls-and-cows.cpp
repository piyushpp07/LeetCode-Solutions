class Solution {
public:
    string getHint(string secret, string guess) {
        vector<int>a(10,0),b(10,0);
        int A = 0;
        for(int i = 0;i<secret.size();i++)
        {
            if(secret[i] == guess[i])
                A++;
            else
            {
              a[secret[i]-'0']++;
              b[guess[i]-'0']++;
            }
        }
        int B = 0;
        for(int i = 0;i<10;i++)
        {
            B+=min(a[i],b[i]);
        }
        return to_string(A)+"A"+to_string(B)+"B";
    }
};