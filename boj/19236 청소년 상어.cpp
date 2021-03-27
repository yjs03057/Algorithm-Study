#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int fishMap[4][4]; //물고기 번호 (-1: 상어, 0: 빈 칸)
int ans=0;
vector<pair<pair<int,int>,int>> fishes[17]; //물고기 번호 별 위치 저장, 물고기 방향 (위, 왼위, 왼, 왼아래, 아래, 오른아래, 오른, 오른위)
int route[9][2] = {{0,0},
                   {-1,0},{-1,-1},{0,-1},{1,-1},
                   {1,0},{1,1},{0,1},{-1,1}};

void moveFish(int x,int y , int dir){
    int dx=x,dy=y, flag=1, first_dir=dir; //first_dir: 상어가 이동할 수 있는지 없는지 확인
    while(flag){
        dx=x,dy=y;
        dx = x+route[dir][0];
        dy = y+route[dir][1];

        if(dx>=0 && dy>=0 && dx<=3 && dy<=3 && fishMap[dx][dy]>=0){
            //물고기가 움직일 수 있음
            if(fishMap[dx][dy]==0){
                //빈 칸
                fishMap[dx][dy] = fishMap[x][y];
                fishes[fishMap[x][y]].pop_back();
                fishes[fishMap[x][y]].push_back(make_pair(make_pair(dx,dy),dir));
                fishMap[x][y] = 0;
            }
            else{
                //다른 물고기가 있음
                int tmp= fishMap[dx][dy], tmpdir = fishes[fishMap[dx][dy]].front().second;
                fishMap[dx][dy] = fishMap[x][y];
                fishMap[x][y] = tmp;

                fishes[fishMap[dx][dy]].pop_back();
                fishes[fishMap[dx][dy]].push_back(make_pair(make_pair(dx,dy),dir));
                fishes[fishMap[x][y]].pop_back();
                fishes[fishMap[x][y]].push_back(make_pair(make_pair(x,y),tmpdir));
            }

            flag=0;
        }
        else{
            dir++;
            if(dir==9) dir = 1;
            if(first_dir==dir) flag=0;
        }
    }
    return;
}
int sharkMove(int x, int y, int dir, int sum){

    int tmpMap[4][4], dx=x, dy=y, cur=0, shark_dir;
    vector<pair<pair<int,int>,int>> copy_fishes[17];

    //복사
    memcpy(tmpMap,fishMap,sizeof(tmpMap));
    for(int i=0; i<17; i++){
        copy_fishes[i] = fishes[i];
    }

    //물고기 이동
    int fx, fy, fd;
    for(int i=1; i<=16; i++){
        //1번 물고기부터 이동
        if(fishes[i].front().second == -1) continue; //dir이 -1이면 죽은 물고기
        fx = fishes[i].front().first.first;
        fy = fishes[i].front().first.second;
        fd = fishes[i].front().second;
        moveFish(fx, fy, fd);
    }

    //상어 이동
    while(1){
        dx += route[dir][0];
        dy += route[dir][1];

        if(dx>=0 && dy>=0 && dx<=3 && dy<=3){
            cur = fishMap[dx][dy];

            if(cur > 0){
                //상어가 이동할 수 있는 곳
                shark_dir = fishes[cur].front().second;
                fishes[cur].front().second = -1; //죽었다고 표시
                fishMap[dx][dy] = -1; //상어 표시
                fishMap[x][y] = 0; //원래 상어가 있던 곳은 빈 칸

                sharkMove(dx,dy,shark_dir,sum+cur);

                //복구
                fishMap[dx][dy] = cur;
                fishMap[x][y] = -1;
                fishes[cur].front().second = shark_dir;
            }
            else if(cur == 0) continue; //빈 칸
        }
        else break; //범위 밖
    }
    ans = max(sum, ans);

    //복사
    memcpy(fishMap,tmpMap,sizeof(fishMap));
    for(int i=0; i<17; i++){
        fishes[i] = copy_fishes[i];
    }

    return 0;
}
int main(){
    int tmp, shark_dir;

    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            cin>>fishMap[i][j]>>tmp;
            fishes[fishMap[i][j]].push_back(make_pair(make_pair(i,j),tmp));
        }
    }

    //상어가 0,0 물고기 먹음
    ans = fishMap[0][0];
    shark_dir = fishes[fishMap[0][0]].front().second;
    fishes[fishMap[0][0]].front().second = -1; //dir = -1 이면 먹힌 것
    fishMap[0][0] = -1; //상어는 -1로 표시

    //상어, 물고기 이동
    sharkMove(0,0,shark_dir,ans);

    cout<<ans<<endl;

    return 0;
}