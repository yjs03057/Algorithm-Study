#include <iostream>
#include <deque>
#include <set>
using namespace std;
int N,M,K, ans=0;
int route[8][2]={{-1,0},{-1,1},{0,1},{1,1},
                 {1,0},{1,-1},{0,-1},{-1,-1}};
struct fireball{
    int m; //질량
    int d; //방향 (0~7)
    int s; //속력 : 이동하는 칸 수
    int r; //위치 행
    int c; //위치 열
};
deque<fireball> map[51][51];
set<pair<int,int>> locations;
set<pair<int,int>> locations_second;
void solve(){

    // 1.모든 파이어볼이 자신의 뱡향 d로 속력 s칸 만큼 이동
    int dx,dy,x,y,size;
    fireball f;
    deque<fireball> tmp[51][51];
    for(auto i:locations){
        x = i.first, y = i.second;
        size = map[x][y].size();
        while(size>0){
            f = map[x][y].front();
            map[x][y].pop_front();

            dx = f.r+(route[f.d][0])*f.s, dy = f.c+(route[f.d][1])*f.s;
            while(dx<=0||dx>N||dy<=0||dy>N){
                if(dx<=0) dx=dx+N;
                else if(dx>N) dx=dx-N;
                if(dy<=0) dy=dy+N;
                else if(dy>N) dy=dy-N;
            }
            f.r = dx, f.c = dy;
            locations_second.insert({dx,dy});
            tmp[dx][dy].push_back(f);

            size--;
        }
    }
    locations.clear();

    for(auto i:locations_second){
        x = i.first, y = i.second;
        //이동한 fireballs 추가
        for(int j=0; j<tmp[x][y].size(); j++){
            map[x][y].push_back(tmp[x][y][j]);
        }
    }

    // 2.한 칸에 2개 이상의 파이어볼이 있는 칸에서 동작
    int m_sum=0, s_sum=0, cnt=0, dm,ds, direction_flag=0, dir_flag_cnt=0;
    for(auto i:locations_second){
        x = i.first, y = i.second;
        m_sum=0, s_sum=0, cnt=0, dir_flag_cnt=0;

        if(map[x][y].size()>=2){
            direction_flag = map[x][y][0].d%2; //홀수인지 짝수인지 설정해줌
            for(int j=0; j<map[x][y].size(); j++){
                m_sum += map[x][y][j].m; //질량 합
                s_sum += map[x][y][j].s; //속력 합
                cnt++; //합쳐진 파이어볼 개수
                if(direction_flag == map[x][y][j].d%2) dir_flag_cnt++;
            }
            map[x][y].clear();

            dm = m_sum/5;
            ds = s_sum/cnt;
            f.r=x, f.c=y, f.m=dm, f.s=ds;

            //질량이 0인 파이어볼은 소멸되어 없어진다.
            if(dm==0) continue;

            if(dir_flag_cnt==cnt){
                //방향이 모두 홀수이거나 짝수
                //방향은 0,2,4,6
                f.d=0;
                map[x][y].push_back(f);
                f.d=2;
                map[x][y].push_back(f);
                f.d=4;
                map[x][y].push_back(f);
                f.d=6;
                map[x][y].push_back(f);
            }
            else{
                //방향은 1,3,5,7

                f.d=1;
                map[x][y].push_back(f);
                f.d=3;
                map[x][y].push_back(f);
                f.d=5;
                map[x][y].push_back(f);
                f.d=7;
                map[x][y].push_back(f);
            }
        }
        locations.insert({x,y});
    }

    locations_second.clear();

    return;
}
int main(){

    int x,y,size;
    fireball f;
    cin>>N>>M>>K;
    for(int i=0; i<M; i++){
        cin>>f.r>>f.c>>f.m>>f.s>>f.d;
        locations.insert({f.r,f.c});
        map[f.r][f.c].push_back(f);
    }

    while(K>0){
        solve();
        K--;
    }

    for(auto i:locations){
        x = i.first, y = i.second;
        size = map[x][y].size();
        for(int j=0; j<size; j++){
            ans += map[x][y][j].m;
        }
    }

    cout<<ans<<endl;

    return 0;
}