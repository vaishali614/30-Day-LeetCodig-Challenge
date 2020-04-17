class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i, profit = 0, curr, next, buy = 0, sell = 0;
        bool isBuy = false;
        
        for(i = 0; i < prices.size() - 1; i++){
            curr = prices[i], next = prices[i+1];
            if(isBuy == false && curr < next){
                buy = curr;
                profit -= buy;
                isBuy = true;
            } 
            if(isBuy == true && curr > next){
                sell = curr;
                profit += sell;
                isBuy = false;
            }
            
            // profit += sell - buy;
        }
        
        if(isBuy == true)
            profit += prices[i];
        
        return profit;
    }
};
