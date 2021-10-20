#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
int N,M;
int original_map[8][8];
int ans=987654321; //사각지대
int route[5][2] = {{0,1},{1,0},{0,-1},{-1,0},{0,1}}; //오 아 왼 위
vector<pair<int,pair<int,int>>> v;

void cctv1(int idx, int x, int y, int map[][8]){
    int dx,dy;

    // 1 -> 한 방향
    dx=x+route[idx][0], dy=y+route[idx][1];
    while(dx>=0&&dx<N&&dy>=0&&dy<M
          &&map[dx][dy]<6){
        if(!map[dx][dy]) map[dx][dy]=-1;
        dx=dx+route[idx][0], dy=dy+route[idx][1];
    }
    return;
}
void cctv2(int idx, int x, int y, int map[][8]){
    int dx,dy;

    //맞은편 방향
    for(int i=idx; i<4; i+=2){
        dx=x+route[i][0], dy=y+route[i][1];
        while(dx>=0&&dx<N&&dy>=0&&dy<M
              &&map[dx][dy]<6){
            if(!map[dx][dy]) map[dx][dy]=-1;
            dx=dx+route[i][0], dy=dy+route[i][1];
        }
    }
    return;
}
void cctv3(int idx, int x, int y, int map[][8]){
    int dx,dy;
    // 직각 방향
    for(int j=idx; j<idx+2; j++){
        dx=x+route[j][0], dy=y+route[j][1];
        while(dx>=0&&dx<N&&dy>=0&&dy<M
              &&map[dx][dy]<6){
            if(!map[dx][dy]) map[dx][dy]=-1;
            dx=dx+route[j][0], dy=dy+route[j][1];
        }
    }
    return;
}
void cctv4(int idx, int x, int y, int map[][8]){
    int dx,dy;
    //세 방향

    for(int i=0; i<4; i++){
        if(i==idx) continue;
        dx=x+route[i][0], dy=y+route[i][1];
        while(dx>=0&&dx<N&&dy>=0&&dy<M
              &&map[dx][dy]<6){
            if(!map[dx][dy]) map[dx][dy]=-1;
            dx=dx+route[i][0], dy=dy+route[i][1];
        }
    }
    return;
}
void cctv5(int idx, int x, int y, int map[][8]){
    int dx,dy;
    // 네 방향 모두
    for(int i=0; i<4; i++){
        dx=x+route[i][0], dy=y+route[i][1];
        while(dx>=0&&dx<N&&dy>=0&&dy<M
              &&map[dx][dy]<6){
            if(!map[dx][dy]) map[dx][dy]=-1;
            dx=dx+route[i][0], dy=dy+route[i][1];
        }
    }
    return;
}
void solve(int cctv_cnt, int map[][8]){
    int x,y,num, cnt=0;
    int tmp_map[8][8];
    if(cctv_cnt==v.size()){
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(!map[i][j]) cnt++;
            }
        }
        ans = min(ans, cnt);

        return;
    }
    num = v[cctv_cnt].first;
    x=v[cctv_cnt].second.first, y=v[cctv_cnt].second.second;

    //DFS
    memcpy(tmp_map, map, sizeof(tmp_map));
    switch (num) {
        case 1:
            for(int i=0; i<4; i++){
                memcpy(map, tmp_map, sizeof(tmp_map));
                cctv1(i,x,y,map);
                solve(cctv_cnt+1,map);
            }
            break;
        case 2:
            for(int i=0; i<2; i++){
                memcpy(map, tmp_map, sizeof(tmp_map));
                cctv2(i,x,y,map);
                solve(cctv_cnt+1,map);
            }
            break;
        case 3:
            for(int i=0; i<4; i++){
                memcpy(map, tmp_map, sizeof(tmp_map));
                cctv3(i,x,y,map);
                solve(cctv_cnt+1,map);
            }
            break;
        case 4:
            for(int i=0; i<4; i++){
                memcpy(map, tmp_map, sizeof(tmp_map));
                cctv4(i,x,y,map);
                solve(cctv_cnt+1,map);
            }
            break;
        case 5:
            memcpy(map, tmp_map, sizeof(tmp_map));
            cctv5(0,x,y,map);
            solve(cctv_cnt+1,map);
            break;
    }

    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(original_map, 0, sizeof(original_map));

    cin>>N>>M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin>>original_map[i][j];
            if(original_map[i][j]>0 && original_map[i][j]<6){
                v.push_back({original_map[i][j],{i,j}});
            }
        }
    }

    solve(0,original_map);
    cout<<ans;

    return 0;
}