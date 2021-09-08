#include <iostream>
#include <cstring>
using namespace std;

int n; //사탕 종류 수
float m; //돈의 양
int candies[5001][2]; //칼로리,가격
int dp[10001]; // dp[i]: 최대 i가격일 때, 최대 칼로리

int main(){
    int c,money;
    float p;

    while(1){
        memset(dp, 0, sizeof(dp));
        memset(candies, 0, sizeof(candies));

        cin>>n>>m;
        if(n==0 && m==0.00) return 0;
        money = (int)(m*100);

        for(int i=1; i<=n; i++){
            cin>>c>>p;
            candies[i][0] = c; //칼로리
            candies[i][1] = (int)p*100; //가격
        }

        for(int j=1; j<=n; j++){ //사탕 종류 차근차근 고려
            for(int i=0; i<=money; i++) {
                if (candies[j][1] > i) continue;
                dp[i] = max(dp[i], dp[i - candies[j][1]] + candies[j][0]);
            }
        }

        cout<<dp[money]<<endl;
    }

    return 0;
}