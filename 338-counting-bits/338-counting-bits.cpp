class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>v;
        for(int i = 0;i<n+1;i++)
        {
            int no = i;
            int count = 0;
            while(no)
            {
                int mask = no&(-no);
                no = no ^ mask;
                count++;
            }
            v.push_back(count);
        }
        return v;
    }
};