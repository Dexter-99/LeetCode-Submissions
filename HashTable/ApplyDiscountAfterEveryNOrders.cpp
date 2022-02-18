class Cashier {
public:
    unordered_map<int,int> mp;
    int count;
    int cust;
    int  d;
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
        for(int i=0;i<products.size();i++)
        {
            mp[products[i]]=prices[i];
        }
        count=0;
        cust=n;
        d=discount;
    }
    
    double getBill(vector<int> product, vector<int> amount) {
        count++;
        double total=0.0;
        for(int i=0;i<amount.size();i++)
        {
            total+=amount[i]*mp[product[i]];
        }
        
        if(count==cust)
        {
            total=total*((100-d)/100.0);
            count=0;
        }
        return total;
        
        
    }
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */