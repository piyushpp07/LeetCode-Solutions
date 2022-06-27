class Solution {
public:
    int minPartitions(string n) {
        sort(n.begin(),n.end());
            cout<<n;
        return n[n.size()-1]-'0';
    }
};