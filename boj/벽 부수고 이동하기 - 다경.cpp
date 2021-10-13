#include <iostream>
#include <queue>
using namespace std;
int N,M, ans=987654321;
string map[1000];
int route[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
int visited[1000][1000][2]; // [x][y][여기 오기까지 벽을 부순적 있는가]
void BFS(){
    // (0,0) -> (N-1,M-1)
    int x,y,dx,dy;
    int wall_break;
    queue<pair<pair<int,int>,int>> q; //<<x,y>,벽부수기>
    q.push({{0,0},0});
    visited[0][0][0] = visited[0][0][1] =1;
    while(!q.empty()){
        x=q.front().first.first, y=q.front().first.second;
        wall_break = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            dx=x+route[i][0], dy=y+route[i][1];
            if(dx<0||dy<0||dx>=N||dy>=M) continue;
            if(map[dx][dy]=='1'){
                if(wall_break) continue;
                else { // 벽 부수기
                    if(visited[dx][dy][1] > visited[x][y][0]+1){
                        visited[dx][dy][1] = visited[x][y][0]+1;
                        q.push({{dx,dy},1});
                    }
                }
            }
            else{
                if(visited[dx][dy][wall_break] > visited[x][y][wall_break]+1){
                    visited[dx][dy][wall_break] = visited[x][y][wall_break]+1;
                    q.push({{dx,dy},wall_break});
                }
            }
        }
    }
    return;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N>>M;
    for(int i=0; i<N; i++){
        cin>>map[i];
    }

    //벽을 한 개까지 부수고 이동할 수 있음
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            visited[i][j][0] = visited[i][j][1] = 987654321;
        }
    }
    BFS();
    ans = min(ans,visited[N-1][M-1][0]);
    ans = min(ans, visited[N-1][M-1][1]);
    if(ans==987654321) cout<<-1;
    else cout<<ans;

    return 0;
}