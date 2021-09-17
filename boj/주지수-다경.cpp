#include <iostream>
#include <cstring>
using namespace std;
int N,M,K;
int map[1025][1025];
int sum[1025][1025]; // dp[i][j] = [1][1]에서 [i][j]까지 누적 합
int main(){
    int x1,y1,x2,y2;

    memset(map, 0, sizeof(map));
    memset(sum, 0, sizeof(sum));

    cin>>N>>M;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            cin>>map[i][j];
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + map[i][j];
        }
    }

    cin>>K;
    for(int i=0; i<K; i++){
        cin>>x1>>y1>>x2>>y2;

        //직사각형 범위 내에 살고 있는 사람 수의 합
        cout<<sum[x2][y2]-sum[x1-1][y2]-sum[x2][y1-1]+sum[x1-1][y1-1]<<'\n';
    }



    return 0;
}