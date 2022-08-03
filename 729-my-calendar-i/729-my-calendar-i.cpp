class MyCalendar
{
    public:
        unordered_map<int, int> mp;
    MyCalendar() {}

    bool book(int start, int end)
    {
        bool ans = true;
        for (auto &i: mp)
        {
            if(start >= i.second)
                continue;
            else if(end <= i.first )
                continue;
            else ans = false;
        }
        if (ans)
        {
            mp[start] = end;
            return true;
        }
        else return false;
    }
};

/**
 *Your MyCalendar object will be instantiated and called as such:
 *MyCalendar* obj = new MyCalendar();
 *bool param_1 = obj->book(start,end);
 */