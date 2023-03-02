class Solution {
public:
    int compress(vector<char>& chars) {
        int ans = 0;
        vector<char>v;
        int i = 0,j = 0,n = chars.size();
        while(j<n)
        {
            int k = 0;
            while(j<n && chars[i] == chars[j])
            {
                j++;
                k++;
            }
            if(k == 1)
                v.push_back(chars[i]);
            else
            {
                v.push_back(chars[i]);
                while(true)
                {
                    string s = to_string(k);
                    int no = stoi(s);
                    vector<char>c;
                    while(no)
                    {
                        int rem = no % 10;
                        c.push_back(rem+'0');
                        no = no / 10;
                    }
                    reverse(c.begin(),c.end());
                    for(int l = 0;l<c.size();l++)
                    {
                        v.push_back(c[l]);
                    }
                    break;
                }
            }
            i = j;
        }
        chars = v;
       
        return v.size();
    }
};