#include <iostream>
#include <cstring>

using namespace std;

int N,M,K;
int orders[101][2];
int dp[101][301][301];
//dp[a][b][c]: a번째 주문을 처리, b는 최대 치즈버거, c는 최대 감자튀김 => 최대 해결 주문 수

int main(){
    memset(dp,0,sizeof(dp));

    cin>>N>>M>>K;
    for(int i=1; i<=N; i++){
        cin>>orders[i][0]>>orders[i][1]; //치즈버거, 감자튀김
    }

    for(int i=1; i<=N; i++){
        for(int x=0; x<=M; x++){
            for(int y=0; y<=K; y++){
                if(orders[i][0]>x || orders[i][1]>y){
                    dp[i][x][y] = dp[i-1][x][y];
                    continue;
                }
                dp[i][x][y] = max(dp[i-1][x][y], dp[i-1][x-orders[i][0]][y-orders[i][1]]+1);
            }
        }
    }

    cout<<dp[N][M][K];

    return 0;
}