#include <iostream>
#include <cstring>
using namespace std;
int N,M, ans=0;
int map[502][502];
int route[4][2] = {{0,1},{0,-1},{1,0},{-1,0}}; //오,왼,아,위
bool visited[502][502];

void solve(int cnt, int x, int y, int sum){
    if(cnt==4){
        ans = max(ans, sum);
        return;
    }
    int dx,dy;

    for(int r=0; r<4; r++){
        dx=x+route[r][0], dy=y+route[r][1];
        if(dx<1||dy<1||dx>N||dy>M) continue;
        if(visited[dx][dy]) continue;
        visited[dx][dy]=1;
        solve(cnt+1,dx,dy,sum+map[dx][dy]);
        visited[dx][dy]=0;
    }

    return;
}
int main(){
    int dx,dy;
    memset(map, 0, sizeof(map));

    cin>>N>>M;
    for(int i=1; i<N+1; i++){
        for(int j=1; j<M+1; j++){
            cin>>map[i][j];
        }
    }

    memset(visited,0,sizeof(visited));
    for(int i=1; i<N+1; i++){
        for(int j=1; j<M+1; j++) {
            visited[i][j]=1;
            solve(1,i,j,map[i][j]);
            visited[i][j]=0;

            //'ㅗ' 모양 확인
            // 1,2,3 / 1,2,4 / 2,3,4 / 1,3,4
            int sum=map[i][j];
            sum += map[i+route[0][0]][j+route[0][1]];
            sum += map[i+route[1][0]][j+route[1][1]];
            sum += map[i+route[2][0]][j+route[2][1]];
            ans = max(ans, sum);
            sum -= map[i+route[2][0]][j+route[2][1]];
            sum += map[i+route[3][0]][j+route[3][1]];
            ans = max(ans, sum);
            sum -= map[i+route[0][0]][j+route[0][1]];
            sum += map[i+route[2][0]][j+route[2][1]];
            ans = max(ans, sum);
            sum -= map[i+route[1][0]][j+route[1][1]];
            sum += map[i+route[0][0]][j+route[0][1]];
            ans = max(ans,sum);
        }
    }

    cout<<ans;

    return 0;
}