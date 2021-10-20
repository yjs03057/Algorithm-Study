#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;

string map[12];
int route[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
bool visited[12][6];
bool BFS(int i, int j){
    queue<pair<int,int>> q;
    vector<pair<int,int>> blow; //터질애들
    int x,y,dx,dy;
    char color=map[i][j];

    q.push({i,j});
    visited[i][j] = 1;
    blow.push_back({i,j});
    while(!q.empty()){
        x=q.front().first, y=q.front().second;
        q.pop();

        for(int r=0; r<4; r++){
            dx=x+route[r][0], dy=y+route[r][1];
            if(dx<0||dy<0||dx>=12||dy>=6) continue;
            if(visited[dx][dy]) continue;
            if(map[dx][dy]==color){
                visited[dx][dy]=1;
                blow.push_back({dx,dy});
                q.push({dx,dy});
            }
            else continue;
        }
    }

    if(blow.size()>=4){
        for(int b=0; b<blow.size(); b++){
            x=blow[b].first, y=blow[b].second;
            map[x][y] = '.';
        }
        return true;
    }
    else return false;

}
void moveDown(){
    //바닥 x=11

    for(int j=0; j<6; j++){
        for(int i=11; i>=0; i--){
            if(map[i][j]=='.'){
                for(int k=i-1; k>=0; k--){
                    if(map[k][j]=='.') continue;
                    map[i][j] = map[k][j];
                    map[k][j] = '.';
                    break;
                }
            }
        }
    }

    return;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ans=0;
    bool flag= false, ret;

    for(int i=0; i<12; i++) cin>>map[i];

    while(1){
        flag= false;
        for(int i=0; i<12; i++){
            for(int j=0; j<6; j++){
                if(visited[i][j]) continue;
                if(map[i][j]=='.') continue;
                memset(visited, false, sizeof(visited));
                ret = BFS(i,j); //터짐
                if(ret) flag=true;
            }
        }
        if(!flag) break; //종료
        else ans += 1;

        //뿌요 아래로 이동
        moveDown();

    }

    cout<<ans;

    return 0;
}