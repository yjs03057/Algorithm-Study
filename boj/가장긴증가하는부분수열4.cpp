#include <iostream>
#include <cstring>
#include <stack>
using namespace std;
int main(){
    int A[1000];
    int dp[1000][2]; //dp[i][0]: max_cnt, dp[i][1]: 바로 전 index
    int N,ans=0,idx=0;
    stack<int> s;
    memset(dp, 0, sizeof(dp));

    cin>>N;
    for(int i=0; i<N; i++) cin>>A[i];

    dp[0][0]=1, dp[0][1]=-1;
    for(int i=1; i<N; i++){
        dp[i][0]=1;
        dp[i][1]=-1;
        for(int j=i-1; j>=0; j--){
            if(A[j]<A[i] && dp[i][0]<dp[j][0]+1){
                dp[i][0] = dp[j][0]+1;
                dp[i][1] = j;
            }
        }
        if(ans<dp[i][0]){
            ans = dp[i][0];
            idx = i;
        }
    }

    if(!ans) ans=1;
    cout<<ans<<endl;
    while(1){
        if(idx==-1) break;
        s.push(A[idx]);
        idx = dp[idx][1];
    }
    while(!s.empty()){
        cout<<s.top()<<' ';
        s.pop();
    }

    return 0;
}