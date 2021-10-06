#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;
int N;
bool isPrime[4000001];
vector<int> pn;
void eratos(){ //에라토스테네스의 체
    isPrime[0] = isPrime[1] = false;
    int num = int(sqrt(4000000));
    for(int i=2; i<=num; i++){
        if(isPrime[i]){
            for(int j=i*i; j<4000001; j+=i) isPrime[j] = false;
        }
    }

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ans=0, start=0, end=0, sum=0, size;
    memset(isPrime, true, sizeof(isPrime));

    cin>>N;
    if(N==1){
        cout<<0;
        return 0;
    }
    eratos(); //에라토스테네스의 체

    for(int i=0; i<=N; i++){
        if(isPrime[i]) pn.push_back(i);
    }

    size = pn.size()-1;
    sum=pn[start];
    while(start<=size && end<=size){

        if(sum==N) ans++, sum += pn[++end];
        else if(sum<N) sum += pn[++end];
        else sum -= pn[start++];
    }

    cout<<ans;

    return 0;
}