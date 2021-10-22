#include <iostream>
#include <cstring>
using namespace std;

int N, ans=987654321;
int city[21][21];
int group[21][21]; //선거구
int sum[6]; //선거구 별 인구수
int main(){

    cin>>N;
    for(int i=1; i<=N; i++) {
        for (int j = 1; j <= N; j++) cin >> city[i][j];
    }

    //1. 기준점, 경계의 길이 정한다
    for(int x=1; x<N; x++){
        for(int y=1; y<N; y++){
            //기준점: (x,y)
            for(int d1=1; d1<N; d1++){
                for(int d2=1; d2<N; d2++){
                    //경계의 길이: d1, d2
                    //가능한 조합인지 확인
                    if(x+d1+d2>N || y-d1<1 || y-d1>=y || y+d2>N) continue;

                    //2. 경계선 생성
                    memset(group, 0, sizeof(group));
                    for(int i=0; i<d1+1; i++){
                        group[x+i][y-i]=5;
                        group[x+d2+i][y+d2-i]=5;
                    }
                    for(int j=0; j<d2+1; j++) {
                        group[x + j][y + j] = 5;
                        group[x+d1+j][y-d1+j] = 5;
                    }

                    //3. 5번 선거구
                    for(int i=x+1; i<x+d1+d2; i++){
                        for(int j=1; j<N; j++){
                            if(group[i][j]==5){
                                if(group[i][j+1]==5) break;
                                else group[i][j+1]=5;
                            }
                        }
                    }

                    //4. 5번외 선거구
                    //1번
                    for(int i=1; i<x+d1; i++){
                        for(int j=1; j<=y; j++) if(group[i][j]!=5) group[i][j]=1;
                    }
                    //2번
                    for(int i=1; i<=x+d2; i++){
                        for(int j=y+1; j<=N; j++) if(group[i][j]!=5) group[i][j]=2;
                    }
                    //3번
                    for(int i=x+d1; i<=N; i++){
                        for(int j=1; j<y-d1+d2; j++) if(group[i][j]!=5) group[i][j]=3;
                    }
                    //4번
                    for(int i=x+d2+1; i<=N; i++){
                        for(int j=y-d1+d2; j<=N; j++) if(group[i][j]!=5) group[i][j]=4;
                    }


                    //5. 선거구별 인구 수 합
                    memset(sum, 0, sizeof(sum));
                    int cur, maxingu=0, miningu=987654321;
                    for(int i=1; i<=N; i++){
                        for(int j=1; j<=N; j++){
                            cur = group[i][j];
                            sum[cur] += city[i][j];
                        }
                    }

                    //가장 많은 선거구와 가장 적은 선거구의 인구 차이
                    for(int i=1; i<6; i++){
                        maxingu = max(maxingu, sum[i]);
                        miningu = min(miningu, sum[i]);
                    }
                    ans = min(ans, maxingu-miningu);
                }
            }
        }
    }

    cout<<ans;

    return 0;
}