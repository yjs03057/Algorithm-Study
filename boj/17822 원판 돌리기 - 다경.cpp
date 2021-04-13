#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;
int n,m,t,cnt=0;
double avg;
struct spin{
    int x;  //x의 배수인 원판을
    int d;  //d방향으로 (0:시계, 1:반시계)
    int k;  //k칸 회전
};
vector<int> rullet[51]; //rullet[i][j]: i번째 원판에 j번째 수
queue<spin> spins;
void spining(){
    int x,d,k,tmp;
    spin s = spins.front();
    spins.pop();
    x = s.x, d = s.d;

    for(int p=1; p<=n; p++){
        if(p%x == 0){
            //p번째 원판 회전 대상
            k = s.k;
            while(k>0){
                if(d==0){
                    //시계 방향 회전
                    tmp = rullet[p][m];
                    for(int q=m; q>1; q--){
                        rullet[p][q] = rullet[p][q-1];
                    }
                    rullet[p][1] = tmp;
                }
                else{
                    //반시계 방향 회전
                    tmp = rullet[p][1];
                    for(int q=1; q<m; q++){
                        rullet[p][q] = rullet[p][q+1];
                    }
                    rullet[p][m] = tmp;
                }
                k--;
            }
        }
    }

    return;
}
int calc(){
    int ret=0;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(rullet[i][j] != -1){
                ret += rullet[i][j];
                cnt++;
            }
        }
    }

    return ret;
}

int findnum(){
    //인접한 수 찾기
        //인접한 수 모두 지우기
        //인접한 수 없으면 평균구하고, 평균보다 큰 수 +1 & 평균보다 작은 수 -1

    int dx,dy,flag=0,sum=0, ret=0;
    set<pair<int,int>> todelete; //지워야 할 수 위치 저장
    int route[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};

    //인접한 수일 경우 = -1
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(rullet[i][j]==-1) continue;

            flag=0;
            for(int q=0; q<4; q++){
                dx = i+route[q][0], dy = j+route[q][1];
                if(dx==0 || dx==n+1) continue;
                if(dy==0) dy=m;
                else if(dy==m+1) dy=1;

                if(rullet[i][j] == rullet[dx][dy]){
                    todelete.insert({dx,dy});
                    flag=1;
                }
            }
            if(flag) todelete.insert({i,j});
        }
    }

    if(todelete.empty()){
        //인접한 수 없음
        cnt=0;
        sum = calc();
        avg = (double)sum/cnt; //평균구하고
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(rullet[i][j]!=-1){
                    //평균보다 큰 수 -1 & 평균보다 작은 수 +1
                    if(rullet[i][j]>avg) rullet[i][j]--;
                    else if(rullet[i][j]<avg) rullet[i][j]++;
                }
            }
        }

        ret = calc();
    }
    else{
        //인접한 수 지우기
        for(auto i: todelete){
            rullet[i.first][i.second] = -1;
        }
        todelete.clear();
        ret = calc();
    }

    return ret;
}
int solution(){
    int ret=0;

    while(t>0){
        spining(); //회전 시키기
        ret = findnum(); //인접한 수 찾기

        t--;
    }

    return ret;
}
int main(){
    int tmp;
    spin s;
    cin>>n>>m>>t;

    for(int i=1; i<=n; i++){
        rullet[i].push_back(0);
        for(int j=1; j<=m; j++){
            cin>>tmp;
            rullet[i].push_back(tmp);
        }
    }

    for(int i=0; i<t; i++){
        cin>>s.x>>s.d>>s.k;
        spins.push(s);
    }

    cout<< solution();

    return 0;
}