#include <iostream>
#include <vector>
using namespace std;
int t,n;
vector<int> stocks;
long long solve(){
    long long profit=0, max_stock=0;

    for(int i=n-1; i>=0; i--){
        if(stocks[i] > max_stock){
            max_stock = stocks[i];
        }
        else if(stocks[i] < max_stock){
            //차익
            profit += (max_stock - stocks[i]);
        }
    }

    return profit;
}
int main(){
    int tmp;

    cin>>t;
    for(int i=0; i<t; i++){
        cin>>n;
        for(int j=0; j<n; j++){
            cin>>tmp;
            stocks.push_back(tmp);
        }
        cout<< solve() <<endl;

        stocks.clear();
    }

    return 0;
}