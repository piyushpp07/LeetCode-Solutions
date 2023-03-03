class Solution {
public:
    int strStr(string haystack, string needle) {
        int k = needle.size(),n = haystack.size();
        int i = 0,j =0;
        string s = "";
        while(j<n)
        {
            if(s.size() != k)
            {
                s+=haystack[j++];
            }
            if(s.size() == k)
            {
                if(s==needle)
                    return i;
                i++;
                s.erase(s.begin());
            }
        }
        return -1;
    }
};