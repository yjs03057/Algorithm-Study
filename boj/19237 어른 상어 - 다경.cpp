#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int n,m,k, ans=0, shark_cnt=0;
int map[20][20];
int time_map[20][20];
vector<int> dir; //-1이면 죽은 상어
vector<pair<int,int>> shark_loc;
vector<int> priority_dir[401][5];
int route[5][2] = {{0,0},{-1,0},{1,0},{0,-1},{0,1}}; //위,아,왼,오

void solve(){
    int x,y,dx,dy, flag=0, movedir=0; //flag: 상어가 움직였는지 확인

    while(shark_cnt > 1){
        //상어 이동
        //cout<<ans<<endl;
        for(int i=1; i<=m; i++){
            if(dir[i] == -1) continue; //죽은 상어이면 패스
            x = shark_loc[i].first, y = shark_loc[i].second;
            flag=0;

            //1. 빈칸을 찾아서
            for(int j=1; j<=4; j++){
                movedir = priority_dir[i][dir[i]][j];
                dx = x+route[movedir][0];
                dy = y+route[movedir][1];

                //범위 밖
                if(dx<0 || dx>=n || dy<0 || dy>=n) continue;

                //빈 칸일 경우
                if(map[dx][dy]==0) {
                    //이동
                    shark_loc[i] = make_pair(dx,dy);
                    dir[i] = movedir;
                    flag=1;
                    break;
                }
            }

            //2. 빈칸이 없어서 안 움직였을 경우
            if(flag==0){
                for(int j=1; j<=4; j++){
                    movedir = priority_dir[i][dir[i]][j];
                    dx = x+route[movedir][0];
                    dy = y+route[movedir][1];

                    //범위 밖
                    if(dx<0 || dx>=n || dy<0 || dy>=n) continue;

                    //내 냄새 찾을 경우
                    if(map[dx][dy]==i) {
                        //이동
                        shark_loc[i] = make_pair(dx,dy);
                        dir[i] = movedir;
                        flag=1;
                        break;
                    }
                }
            }

            //cout<<"상어"<<i<<" 이동: x,y = "<<x<<','<<y<<" -> dx,dy = " << dx<<','<<dy<< " 방향: "<< dir[i]<<endl;
        }
        //cout<<"======================================"<<endl;

        //시간 줄이기
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(time_map[i][j]>0){
                    time_map[i][j]--;
                    if(time_map[i][j]==0) map[i][j]=0; //상어 냄새 지우기
                }
            }
        }

        //3. 다른 상어를 만날 경우
        for(int j=1; j<=m; j++){
            x = shark_loc[j].first;
            y = shark_loc[j].second;
            if(dir[j]==-1) continue;

            //다른 상어도 와있을 경우
            if(time_map[x][y]==k){
                //내가 번호가 더 크니까 죽음
                dir[j] = -1;
                shark_cnt--;
                continue;
            }
            //cout<<j<<": "<<x<<" , "<<y<<endl;

            map[x][y] = j;
            time_map[x][y] = k;
        }

        ans++;
        if(ans>1000) break;
    }

    return;
}
int main(){
    int tmp;
    memset(time_map,0,sizeof(time_map));

    cin>>n>>m>>k;
    shark_cnt = m;
    for(int i=0; i<=m; i++){
        shark_loc.push_back(make_pair(0,0));
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>map[i][j];
            if(map[i][j]!=0){
                shark_loc[map[i][j]] = make_pair(i,j);
                time_map[i][j] = k;
            }
        }
    }

    dir.push_back(0);
    for(int i=1; i<=m; i++){
        cin>>tmp;
        dir.push_back(tmp);
    }

    for(int i=1; i<=m; i++){
        for(int j=1; j<=4; j++){
            priority_dir[i][j].push_back(0);
            for(int k=1; k<=4; k++){
                cin>>tmp;
                priority_dir[i][j].push_back(tmp);
            }
        }
    }

    solve();

    if(ans>1000) cout<<-1;
    else cout<<ans;


    return 0;
}