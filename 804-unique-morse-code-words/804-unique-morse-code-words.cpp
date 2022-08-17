class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
       vector<string> k = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        set<string>st;
        for(auto i:words)
        {
            string z = "";
            for(int j = 0;j<i.size();j++)
                z+=k[i[j]-'a'];
            st.insert(z);
        }
        return st.size();
        
    }
};