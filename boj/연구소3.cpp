#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
int N,M, ans=987654321;
int map[50][50];
int route[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
int visited[50][50];
int cnt_notwall=0, cp_cnt;
vector<pair<int,int>> virus_loc; //바이러스 놓을 수 있는 위치
vector<pair<int,int>> vr; //바이러스 놓은 위치

void BFS(){
    int x,y,dx,dy,t=0;
    queue<pair<int,int>> q;

    for(int i=0; i<M; i++){
        q.push(vr[i]);
        visited[vr[i].first][vr[i].second]=0;
        cp_cnt--;
    }

    while(!q.empty()){
        x=q.front().first, y=q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            dx=x+route[i][0], dy=y+route[i][1];
            if(dx<0||dy<0||dx>=N||dy>=N) continue;
            if(map[dx][dy]==1) continue; //벽
            if(visited[dx][dy]>visited[x][y]+1){
                cp_cnt--;
                visited[dx][dy]=visited[x][y]+1;
                q.push({dx,dy});
                if(map[dx][dy]==0) t = max(t, visited[dx][dy]);
            }
        }
    }

    if(cp_cnt!=0){
        //바이러스를 다 퍼트리지 못함
        t=987654321;
    }
    ans = min(ans, t);
    //print
//    cout<<endl;
//    for(int i=0; i<N; i++){
//        for(int j=0; j<N; j++){
//            cout<<visited[i][j]<<' ';
//        }
//        cout<<endl;
//    }
//    cout<<endl;


    return;
}

void solve(int idx, int cnt){
    if(cnt==M){
        for(int i=0; i<N; i++) {
            for (int j = 0; j < N; j++) visited[i][j] = 987654321;
        }
        // print
//        for(int i=0; i<vr.size(); i++){
//            cout<<vr[i].first<<' '<<vr[i].second<<endl;
//        }

        cp_cnt = cnt_notwall;
        BFS();
        return;
    }

    //바이러스 놓기
    for(int i=idx; i<virus_loc.size()-M+cnt+1; i++){
        vr.push_back(virus_loc[i]);
        solve(i+1, cnt+1);
        vr.pop_back();
    }

    return;
}
int main(){
    memset(map, 0, sizeof(map));

    cin>>N>>M;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin>>map[i][j];
            if(map[i][j]==2){
                virus_loc.push_back({i,j});
            }
            if(map[i][j]!=1) cnt_notwall++;
        }
    }

    solve(0,0);
    if(ans==987654321){
        cout<<-1;
    }
    else cout<<ans;

    return 0;
}