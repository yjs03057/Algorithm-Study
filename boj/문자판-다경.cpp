#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int N,M,K;
string map[101];
string word;
int dp[101][101][101];
int route[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};

int DFS(int x, int y, int idx){
    int dx,dy;

    if(dp[x][y][idx] != -1) return dp[x][y][idx];
    if(idx==word.size()) return 1;

    dp[x][y][idx]=0;
    for(int i=0; i<4; i++){
        for(int j=1; j<=K; j++){
            dx=x+route[i][0]*j, dy=y+route[i][1]*j;
            if(dx<0||dy<0||dx>=N||dy>=M) continue;
            if(map[dx][dy]==word[idx]){
                dp[x][y][idx] += DFS(dx,dy,idx+1);
            }
        }
    }

    return dp[x][y][idx];
}

int main(){
    int ans=0;
    memset(dp,-1,sizeof(dp));

    cin>>N>>M>>K;
    for(int i=0; i<N; i++){
        cin>>map[i];
    }
    cin>>word;

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(map[i][j]==word[0]){
                ans += DFS(i,j,1);
            }
        }
    }

    cout<<ans;

    return 0;
}