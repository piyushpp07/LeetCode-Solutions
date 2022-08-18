bool comp(int a,int b)
{
    return a>b;
}
class Solution {
public:
    int minSetSize(vector<int>& arr) {
        vector<int>mp(100005);
        for(int i = 0;i<arr.size();i++)
            mp[arr[i]]++;
        sort(mp.begin(),mp.end(),comp);
        int cnt = 0,n = arr.size(),num=0;
        for(int i = 0;i<100001;i++){
            cnt+=mp[i];
            num++;
            if(cnt>=(n/2))
                return num;
        }
        return num;
        
    }
};