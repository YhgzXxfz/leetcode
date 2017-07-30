class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int len = price.size(), min_cost = dotproduct(price, needs);
        
        for (auto offer : special) sums.push_back(dotproduct(price, offer));
            
        vector<int> cart(len, 0);
        int cost = min_cost;
        dfs(min_cost, cost, cart, needs, special, price);
        return min_cost;
    }

private:
    void dfs(int& min_cost, int& cost, vector<int>& cart, vector<int>& needs, vector<vector<int>>& special, vector<int>& price) {
        if (overfit(cart, needs)) return;
        
        for (int i = 0; i < special.size(); ++i) {
            auto offer = special[i];
            addTo(cart, offer, cost, price, min_cost, needs, i);
            dfs(min_cost, cost, cart, needs, special, price);
            removeFrom(cart, offer, cost, i);
        }
    }

    void addTo(vector<int>& cart, vector<int>& offer, int& cost, vector<int>& price, int& min_cost, vector<int>& needs, int i) {
        vectorsum(cart, offer);
        cost += (offer[offer.size()-1]-sums[i]);
        if (underfit(cart, needs)) min_cost = min(min_cost, cost);
    }
    
    void removeFrom(vector<int>& cart, vector<int>& offer, int& cost, int i) {
        vectorminus(cart, offer);
        cost -= (offer[offer.size()-1]-sums[i]);
    }
    
    bool overfit(vector<int>& cart, vector<int>& needs) {
        for (int i = 0; i < cart.size(); ++i) {
            if (cart[i] > needs[i]) return true;
        }
        return false;
    }
    
    bool underfit(vector<int>& cart, vector<int>& needs) {
        return !overfit(cart, needs);
    }
    
    int dotproduct(vector<int>& price, vector<int>& quantity) {
        int sum = 0;
        for (int i = 0; i < price.size(); ++i) {
            sum += price[i]*quantity[i];
        }
        return sum;
    }
    
    void vectorsum(vector<int>& v1, vector<int>& v2) {
        for (int i = 0; i < v1.size(); ++i) {
            v1[i] += v2[i];
        }
    }
    
    void vectorminus(vector<int>& v1, vector<int>& v2) {
        for (int i = 0; i < v1.size(); ++i) {
            v1[i] -= v2[i];
        }
    }
    
    vector<int> sums;
};
