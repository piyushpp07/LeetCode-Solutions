class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int>v;
        sort(potions.begin(),potions.end());
        for(int i = 0;i<spells.size();i++)
        {
            int lo = 0,hi = potions.size() - 1,fi = -1;
            while(lo<=hi)
            {
                int mid = (lo + hi)/2;
                if((long long int)spells[i] * (long long int)potions[mid] < success)
                {
                    lo = mid + 1;
                }
                else{
                    hi = mid - 1;
                    fi = mid;
                }
            }
            if(fi>-1)
            v.push_back(potions.size() - fi);
            else v.push_back(0);
        }
        return v;
        
    }
};