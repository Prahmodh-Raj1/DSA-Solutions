//Problem link: https://leetcode.com/problems/design-an-atm-machine/description/
class ATM {
public:
    int ch=5;
    long long values[5]={0};
    long long mp[5]={20,50,100,200,500};
    ATM() {
        
    }
    
    void deposit(vector<int> banknotesCount) {
        for(int i=0;i<5;i++){
            values[i]+=banknotesCount[i];
        }
    }
    
    vector<int> withdraw(int amount) {
        int nl=5;
        vector<int> val(nl,0);
        int sum=amount;
        for(int i=4;i>=0;i--){
            
                int req = sum/mp[i];
                val[i]=min(values[i],sum/mp[i]);
                sum-=(val[i]*mp[i]);
            
            

            
        }
        if(sum>0){
            return vector<int>({-1});
        }
        for(int i=0;i<5;i++){
            values[i]-=val[i];
        }
        
        return val;
    }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */
