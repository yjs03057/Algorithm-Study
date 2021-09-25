#include <iostream>
#include <cstring>
using namespace std;
int main(){

    int N;
    int S[1000];
    int ans=0;
    int dp[1000]; // 오른쪽으로 증가하는 부분수열
    int dp2[1000]; // 왼쪽으로 증가하는 부분수열

    memset(dp, 0, sizeof(dp));
    memset(dp2, 0, sizeof(dp2));
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>S[i];
    }

    dp[0]=1;
    for(int i=1; i<N; i++){
        dp[i]=1;
        for(int j=i-1; j>=0; j--){
            if(S[j]<S[i] && dp[i]<dp[j]+1){
                dp[i] = dp[j]+1;
            }
        }
    }

    dp2[N-1]=1;
    for(int i=N-2; i>=0; i--){
        dp2[i]=1;
        for(int j=i+1; j<N; j++){
            if(S[j]<S[i] && dp2[i]<dp2[j]+1){
                dp2[i] = dp2[j]+1;
            }
        }
    }

    for(int i=0; i<N; i++){
        ans = max(ans, dp[i]+dp2[i]-1);
    }
    cout<<ans;

    return 0;
}