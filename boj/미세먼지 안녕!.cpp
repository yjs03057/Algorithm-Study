#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int R,C,T;
int map[50][50];
int route[4][2] = {{0,1},{0,-1},{1,0},{-1,0}}; //오,왼,아,위
vector<int> ac_loc; //공기청정기 위치

//print
//void print(){
//    cout<<endl;
//    for(int i=0; i<R; i++){
//        for(int j=0; j<C; j++){
//            cout<<map[i][j]<<'\t';
//        }
//        cout<<endl;
//    }
//}

void spread_dust(){
    int dx,dy, cur,cnt=0, spreaded=0;
    int cp_map[50][50];
    memcpy(cp_map,map,sizeof(map));

    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            if(map[i][j]>0){
                //먼지 있는 칸
                cnt=0;
                cur = map[i][j];
                spreaded = cur/5;
                for(int r=0; r<4; r++){
                    dx=i+route[r][0], dy=j+route[r][1];
                    if(dx<0||dy<0||dx>=R||dy>=C) continue;
                    if(map[dx][dy]==-1) continue;
                    cnt++;
                    cp_map[dx][dy] += spreaded;
                }
                cp_map[i][j] -= cur;
                cp_map[i][j] += cur - spreaded*cnt;
            }
        }
    }
    memcpy(map, cp_map, sizeof(map));

    return;
}

void aircleaner(){
    int x,y,dx=-1,dy=-1,dir;
    //dir: 오,왼,아,위

    //공기청정기는 [ac_loc][0]
    //위쪽은 반시계방향
    //공기청정기로 들어오는 것부터
    dir=3,x=ac_loc[0],y=0;
    while(1){
        dx=x+route[dir][0], dy=y+route[dir][1];
        if(dx<0&&dir==3) dir=0, dx=x+route[0][0], dy=y+route[0][1];
        else if(dy>=C&&dir==0) dir=2, dx=x+route[2][0], dy=y+route[2][1];
        else if(dx>ac_loc[0]&&dir==2) dir=1, dx=x+route[1][0], dy=y+route[1][1];

        map[x][y] = map[dx][dy];
        if(dx==ac_loc[0] && dy==0){
            map[x][y]=0;
            break;
        }
        x=dx, y=dy;
    }
    map[ac_loc[0]][0]=-1;

    //아래쪽은 시계방향
    //공기청정기로 들어오는 것부터
    dir=2,x=ac_loc[1],y=0;
    while(1){
        dx=x+route[dir][0], dy=y+route[dir][1];
        if(dx>=R&&dir==2) dir=0, dx=x+route[0][0],dy=y+route[0][1];
        else if(dy>=C&&dir==0) dir=3, dx=x+route[3][0], dy=y+route[3][1];
        else if(dx<ac_loc[1]&&dir==3) dir=1, dx=x+route[1][0], dy=y+route[1][1];

        map[x][y] = map[dx][dy];
        if(dx==ac_loc[1] && dy==0){
            map[x][y]=0;
            break;
        }
        x=dx, y=dy;
    }
    map[ac_loc[1]][0]=-1;

    return;
}

void solve(){

    while(T--){

        //1.미세먼지 확산
        spread_dust();
        //2.공기청정기 작동
        aircleaner();
    }

    return;
}
int main(){
    int ans=0;
    memset(map, 0, sizeof(map));

    cin>>R>>C>>T;
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            cin>>map[i][j];
            if(map[i][j]==-1) ac_loc.push_back(i);
        }
    }

    solve();
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            ans += map[i][j];
        }
    }
    ans+=2;
    cout<<ans;

    return 0;
}