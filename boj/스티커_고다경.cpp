//9465
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int main(){

    int t, n, ans=0;
    int arr[4][100000];
    int dp[4][100000][2]; // 0: 포함X, 1: 포함O

    cin>>t;
    for(int tc=0; tc<t; tc++){
        cin>>n;
        memset(arr, 0, sizeof(arr));
        memset(dp, 0, sizeof(dp));
        ans=0;

        for(int i=1; i<=2; i++){
            for(int j=1; j<=n; j++){
                cin>>arr[i][j];
            }
        }

        //DP
        for(int j=1; j<=n; j++){
            for(int i=1; i<=2; i++){
                if(i==1){
                    dp[i][j][1] = max(dp[i][j][1], dp[i][j-1][0]+arr[i][j]);
                    dp[i][j][1] = max(dp[i][j][1], dp[i+1][j-1][1]+arr[i][j]);

                    dp[i][j][0] = max(dp[i][j][0], dp[i][j-1][1]);
                    dp[i][j][0] = max(dp[i][j][0], dp[i][j-1][0]);
                    dp[i][j][0] = max(dp[i][j][0], dp[i+1][j-1][1]);
                    dp[i][j][0] = max(dp[i][j][0], dp[i+1][j-1][0]);
                }
                else{
                    dp[i][j][1] = max(dp[i][j][1], dp[i-1][j-1][0]+arr[i][j]);
                    dp[i][j][1] = max(dp[i][j][1], dp[i][j-1][0]+arr[i][j]);

                    dp[i][j][0] = max(dp[i][j][0], dp[i][j-1][1]);
                    dp[i][j][0] = max(dp[i][j][0], dp[i][j-1][0]);
                    dp[i][j][0] = max(dp[i][j][0], dp[i-1][j][1]);
                    dp[i][j][0] = max(dp[i][j][0], dp[i-1][j][0]);
                }


            }
        }
        //출력
//        cout<<endl<<"-------"<<endl;
//        for(int x=1; x<=2; x++){
//            for(int y=1; y<=n; y++){
//                cout<<dp[x][y][1]<<","<<dp[x][y][0]<<" | ";
//            }
//            cout<<endl<<"-------"<<endl;
//        }

        ans = max(dp[2][n][0], dp[2][n][1]);
        cout<<ans<<endl;

    }

    return 0;
}

