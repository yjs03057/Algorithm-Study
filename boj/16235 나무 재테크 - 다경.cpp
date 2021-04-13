#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;
int n,m,k,ans=0;
int s2d2[12][12];
int map[12][12];
deque<int> trees[12][12]; //나이만 저장
int route[8][2] = {{-1,-1},{-1,0},{-1,+1},{0,-1},
                   {0,+1},{+1,-1},{+1,0},{+1,+1}};

void spring_summer(){
    //나무가 자신의 나이만큼 양분을 먹고 나이 1 증가

    deque<int> alive_trees; //살아남은 나무들만 저장
    int nutrition=0; //죽은 나무들 영양분 저장

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(trees[i][j].empty()) continue;

            sort(trees[i][j].begin(), trees[i][j].end());
            for(int q=0; q<trees[i][j].size(); q++){
                if(map[i][j] >= trees[i][j][q]){
                    //나이만큼 양분이 있으면 먹는다
                    map[i][j] -= trees[i][j][q];
                    alive_trees.push_back(trees[i][j][q]+1); //양분 먹고 나이 증가
                }
                else{ //죽음
                    nutrition += (trees[i][j][q]/2);
                    ans--;
                }
            }

            trees[i][j].clear();
            map[i][j] += nutrition;
            for(auto s : alive_trees){
                trees[i][j].push_back(s);
            }
            alive_trees.clear();
            nutrition=0;
        }
    }

    return;
}
void fall(){
    int dx,dy;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++) {
            if (trees[i][j].empty()) continue;

            for(int q=0; q<trees[i][j].size(); q++){
                if(trees[i][j][q]%5==0){
                    //나무 번식
                    for(int p=0; p<8; p++){
                        dx = i+route[p][0], dy = j+route[p][1];
                        if(dx>0 && dx<=n && dy>0 && dy<=n){
                            trees[dx][dy].push_back(1);
                            ans++;
                        }
                    }
                }
            }
        }
    }

    return;
}
void winter(){

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            map[i][j] += s2d2[i][j]; //양분 추가
        }
    }

    return;
}
int main(){
    int x,y,z;

    cin>>n>>m>>k;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>s2d2[i][j];
            map[i][j] = 5;
        }
    }

    for(int i=0; i<m; i++){
        cin>>x>>y>>z;
        trees[x][y].push_back(z);
    }

    ans=m;

    while(k>0){

        spring_summer();
        fall();
        winter();

        k--;
    }

    cout<<ans;

    return 0;
}