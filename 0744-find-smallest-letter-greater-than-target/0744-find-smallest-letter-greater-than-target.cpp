class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char ans = 'z';
        bool flag = false;
        for(auto i : letters)
        {
            if(i > target && i <= ans)
            {
                ans = i;
                flag = true;
            }
        }
        if(flag )
            return ans;
        return letters[0];
    }
};