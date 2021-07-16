#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

int N,M;
vector<pair<int,int>> map[101][101];
bool light[101][101]; //불 켜진지 확인
bool visited[101][101];
int route[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};

int main(){
    int x,y,a,b,dx,dy;
    int ans=1;
    bool flag=true;
    queue<pair<int,int>> q; //불 켜진 방
    memset(light, false, sizeof(light));

    cin>>N>>M;
    for(int i=0; i<M; i++){
        cin>>x>>y>>a>>b;
        map[x][y].push_back({a,b});
    }
    light[1][1]=1;


    while(1){
        memset(visited, false, sizeof(visited));
        q.push({1,1});
        visited[1][1]=1;
        flag=0;

        //BFS
        while(!q.empty()){
            x=q.front().first, y=q.front().second;
            q.pop();

            //갈 수 있는 방
            for(int i=0; i<4; i++){
                dx=x+route[i][0], dy=y+route[i][1];
                if(dx<=0||dy<=0||dx>N||dy>N) continue;
                if(!light[dx][dy] || visited[dx][dy]) continue;
                q.push({dx,dy});
                visited[dx][dy]=1;
            }

            //불켜기
            for(int i=0; i<map[x][y].size(); i++){
                dx=map[x][y][i].first, dy=map[x][y][i].second;
                if(light[dx][dy]) continue;
                light[dx][dy] = 1;
                ans++;
                flag=1;
            }
        }

        if(!flag) break; //BFS 돌 동안, 불이 하나도 켜지지 않았으면 while문 종료
    }

    cout<<ans;

    return 0;
}