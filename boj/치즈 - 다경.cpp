#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
int r,c;
int map[100][100];
int cp_map[100][100];
int t_ans=0, cheese; //모두 녹아 없어지는데 걸리는 시간, 모두 녹기 한 시간 전 치즈 조각
int all_cheese=0;
int route[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
bool visited[100][100];
void BFS(int a, int b){
    queue<pair<int,int>> q;
    int x,y,dx,dy;
    memcpy(cp_map, map, sizeof(map));

    q.push({a,b});
    while(!q.empty()){
        x=q.front().first, y=q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            dx=x+route[i][0], dy=y+route[i][1];
            if(dx<0||dy<0||dx>=r||dy>=c) continue;
            if(visited[dx][dy]) continue;
            if(map[dx][dy]){
                //테두리
                visited[dx][dy]=1;
                cp_map[dx][dy]=0;
                all_cheese--;
            }
            else{
                visited[dx][dy]=1;
                q.push({dx,dy});
            }
        }
    }

    memcpy(map, cp_map, sizeof(map));

    return;
}
int main(){
    memset(visited, false, sizeof(visited));

    cin>>r>>c;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin>>map[i][j];
            if(map[i][j]) all_cheese++;
        }
    }

    while(all_cheese>0){
        memset(visited, false, sizeof(visited));
        cheese = all_cheese;
        BFS(0,0);
        t_ans++;
    }

    cout<<t_ans<<'\n'<<cheese;

    return 0;
}