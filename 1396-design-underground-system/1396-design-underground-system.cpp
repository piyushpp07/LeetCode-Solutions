class UndergroundSystem {
public:
    unordered_map<int,pair<string,int>>mp;
    unordered_map<string,unordered_map<string,int>>times,sum;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        mp[id] = {stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
        sum[mp[id].first][stationName] += (t - mp[id].second);
        times[mp[id].first][stationName]++;
    }
    
    double getAverageTime(string startStation, string endStation) {
        return ((double)sum[startStation][endStation]/(double)(times[startStation][endStation]));
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */