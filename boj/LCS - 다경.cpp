#include <iostream>
#include <cstring>
using namespace std;

int main(){
    string A,B;
    int dp[1001][1001]; //A의 i번째 글자, B의 j번째 글자 비교했을 때 LCS의 길이
    memset(dp,0,sizeof(dp));

    cin>>A>>B;

    for(int i=1; i<=A.size(); i++){
        for(int j=1; j<=B.size(); j++){
            if(A[i-1]==B[j-1]){
                dp[i][j] = dp[i-1][j-1]+1;
            }
            else{
                dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }

    for(int i=1; i<=A.size(); i++){
        for(int j=1; j<=B.size(); j++){
            cout<<dp[i][j]<<'\t';
        }
    cout<<endl;
    }

    cout<<dp[A.size()][B.size()];

    return 0;
}