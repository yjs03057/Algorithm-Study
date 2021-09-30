#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int ans=0;
string arr[5];
int route[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
bool visited[5][5];
bool chk[25];
void DFS(int idx, int Scnt, int cnt){
    int x,y,dx,dy,bfs_cnt=0;
    queue<pair<int,int>> q;

    if(cnt==7){
        if(Scnt>=4){
            //인접한지 확인해야 함
            memset(visited, false, sizeof(visited));
            q.push({idx/5,idx%5}); // 시작점
            visited[idx/5][idx%5]=1;
            bfs_cnt=1;
            while(!q.empty()){
                x=q.front().first, y=q.front().second;
                q.pop();
                //조합이 모두 인접하므로 정답 추가
                if(bfs_cnt==7){
                    ans++;
                    break;
                }

                for(int r=0; r<4; r++){
                    dx=x+route[r][0], dy=y+route[r][1];
                    if(dx<0||dy<0||dx>=5||dy>=5) continue;
                    if(visited[dx][dy]) continue;
                    if(!chk[dx*5+dy]) continue; //조합이 아닌 곳

                    visited[dx][dy]=1;
                    q.push({dx,dy});
                    bfs_cnt++;
                }
            }
        }
        return;
    }

    for(int i=idx; i<25; i++){
        if(chk[i]) continue;
        chk[i]=1;
        if(arr[i/5][i%5]=='S') DFS(i,Scnt+1,cnt+1);
        else DFS(i,Scnt,cnt+1);
        chk[i]=0;
    }

    return;
}
int main(){

    for(int i=0; i<5; i++){
        cin>>arr[i];
    }

    DFS(0,0,0);

    cout<<ans;

    return 0;
}