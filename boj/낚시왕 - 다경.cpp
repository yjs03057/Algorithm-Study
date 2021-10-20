#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int R,C,M;
int ans=0;
int map[101][101]; //상어 index저장
int hy;
int route[5][2]={{0,0},{-1,0},{1,0},{0,1},{0,-1}}; // 위,아래,오른쪽,왼쪽
struct shark{
    int r,c,s,d,z;
    bool alive=true;
};
vector<shark> vs;

//void print(){
//    cout<<endl<<endl;
//    for(int i=1; i<=R; i++){
//        for(int j=1; j<=C; j++){
//            cout<<map[i][j]<<'\t';
//        }
//        cout<<endl;
//    }
//}
void moveShark(){
    int move_cnt=0, dir,dx,dy;
    vector<int> shark_map[101][101];

    for(int i=0; i<vs.size(); i++){
        if(!vs[i].alive) continue;
        dx=vs[i].r, dy=vs[i].c;
        if(map[dx][dy]==i) map[dx][dy]= -1; // 다른 상어가 이 위치로 움직여왔을 수 있으므로
        move_cnt=vs[i].s, dir=vs[i].d;
        while(move_cnt--){
            dx+=route[dir][0], dy+=route[dir][1];
            if(dx==0&&dir==1) dir++, dx=2;
            else if(dy==0&&dir==4) dir--, dy=2;
            else if(dx==R+1&&dir==2) dir--, dx=R-1;
            else if(dy==C+1&&dir==3) dir++, dy=C-1;
        }
        map[dx][dy] = i;
        vs[i].r=dx, vs[i].c=dy, vs[i].d=dir;
        shark_map[dx][dy].push_back(i);
    }

    //상어들 다 움직인 다음 한 칸에 여러 마리 있는지 확인
    for(int i=1; i<=R; i++){
        for(int j=1; j<=C; j++){
            if(shark_map[i][j].size()>1){
                //상어가 여러 마리 있음
                // 크기 제일 큰 상어만 살 수 있음
                int maxsize=0, idx=0, tmpz;
                for(int k=0; k<shark_map[i][j].size(); k++){
                    tmpz = vs[shark_map[i][j][k]].z;
                    if(maxsize<tmpz){
                        maxsize = tmpz, idx=shark_map[i][j][k];
                    }
                }
                //idx: 제일 큰 상어
                for(int k=0; k<shark_map[i][j].size(); k++){
                    if(idx == shark_map[i][j][k]) continue;
                    vs[shark_map[i][j][k]].alive=false;
                }
                map[i][j]=idx;
            }
        }
    }

    return;
}
void solve(){
    int caught_idx;

    while(hy<C){
        //1. 낚시왕이 오른쪽으로 한 칸 이동한다.
        hy++;
        //2. 상어를 잡는다.
        for(int i=1; i<=R; i++){
            if(map[i][hy]==-1) continue;
            //상어 잡음
            caught_idx = map[i][hy];
            map[i][hy]=-1;
            ans += vs[caught_idx].z;
            vs[caught_idx].alive=false;
            break;
        }
        //3. 상어가 이동한다.
        moveShark();
    }

    return;
}
int main(){
    memset(map, -1, sizeof(map));
    shark sh;

    cin>>R>>C>>M;
    for(int i=0; i<M; i++){
        cin>>sh.r>>sh.c>>sh.s>>sh.d>>sh.z;
        map[sh.r][sh.c]=i;
        if(sh.d<=2){
            //위아래
            sh.s = sh.s%(2*R-2); //이동 칸 수 줄이기
        }
        else{
            //좌우
            sh.s = sh.s%(2*C-2); //이동 칸 수 줄이기
        }
        vs.push_back(sh);
    }

    hy=0;
    solve();

    cout<<ans;

    return 0;
}