class StockSpanner {
public:
    // first -> the number 
    //second-> max of this day
    vector<pair<int,int>> days;
    int idx = -1;
    StockSpanner() {
        
    }
    
    int next(int price) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        
        if(idx == -1 || price < days[idx].first){
            days.push_back({price,1});
            idx++;
            return 1;
            
        }else {
            int ans = 1;
            int i = idx;
            do {
                ans += days[i].second;
                i -= days[i].second;

            }while(i >= 0 && days[i].first <= price);

            idx++;
            days.push_back({price,ans});
            return ans;
        }
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
