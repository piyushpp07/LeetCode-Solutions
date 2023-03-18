class BrowserHistory {
public:
    vector<string>v;
    int iptr;
    BrowserHistory(string homepage) {
        v.push_back(homepage);
        iptr =0;
    }
    
    void visit(string url) {
        
        int n = v.size()-1;
        for(int i = iptr;i<n;i++)
            v.pop_back();
        v.push_back(url);
        iptr++;
    }
    
    string back(int steps) {
        int curr = iptr;
        if(steps>=iptr)
        {
            iptr = 0;
            return v[iptr]; 
        }
        else{
            iptr-= steps;
            return v[iptr];
        }
    }
    
    string forward(int steps) {
        int n = v.size() -1 ;
        if(iptr + steps >= n)
        {
            iptr = n;
            return v[iptr];
        }
        else{
            iptr += steps;
            return v[iptr];
        }
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */