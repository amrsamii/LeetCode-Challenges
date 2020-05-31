/**
why stack? because push and pop is O(1), if you use vector, push will be O(1) only if the size of the internal array is smaller than the capacity of the vector, otherwise, vector will double the size of the array and copy all the contents of the array to the new one which will be O(n), and since the there will be 150,000 insertion in the vector, we cannot guarantee the O(1) in each insert, also we need to remove numbers when the price is larger than them, to do that in stack, O(1) is required, but with vector, it is overhead.
*/

class StockSpanner {
public:
    // first -> the number second -> max of this day
    stack<pair<int,int>> days;
    
    StockSpanner() {
        ios::sync_with_stdio(false);
        cin.tie(0);
    }
    
    int next(int price) {
        int ans = 1;
        
        while(!days.empty() && days.top().first <= price) {
            
            ans += days.top().second;
            days.pop();
        }
        
        days.push({price,ans});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
