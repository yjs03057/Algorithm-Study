//18808
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int N,M,K;
int ans=0;
bool map[40][40];
bool chkMap[10][10];
struct sticker{
    int R;
    int C;
    int area=0;
    int arr[10][10];
    int original[10][10];
};
vector<sticker> stickers;

void rotate(int idx){
    sticker s = stickers[idx];
    int tmp[10][10];
    int sr;
    memset(tmp, 0, sizeof(tmp));
    for(int i=0; i<s.R; i++){
        for(int j=0; j<s.C; j++){
            //i,j -> j,R-1-i;
            tmp[j][s.R-1-i] = s.arr[i][j];
        }
    }
    memcpy(s.arr,tmp, sizeof(tmp));
    sr = s.C;
    s.C = s.R;
    s.R = sr;
    stickers[idx] = s;

    return;
}
int locate(int idx){
    sticker s;
    int pos=1; //붙이기 가능한지
    int cnt=0; //회전 카운트

    while(cnt<=3){
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                // 기준점: i,j
                memcpy(s.arr,s.original, sizeof(s.arr));
                pos=1;
                memset(chkMap,0,sizeof(chkMap));
                s = stickers[idx];

                for(int p=0; p<s.R; p++){
                    for(int q=0; q<s.C; q++){
                        if(!s.arr[p][q]) continue;
                        //붙여야 하는 칸
                        if(map[i+p][j+q]==1 || i+p>=N || j+q>=M){
                            pos=0;
                            break;
                        }
                        else chkMap[p][q]=1; //붙이기 가능 표기
                    }
                    if(!pos) break;
                }

                if(pos){
                    for(int p=0; p<s.R; p++){
                        for(int q=0; q<s.C; q++){
                            if(chkMap[p][q]) map[i+p][j+q] = 1;
                        }
                    }
                    return s.area;
                }
            }
        }

        rotate(idx);
        cnt++;
    }

    return 0;
}

int main(){
    //왼, 위부터 붙이기
    //스티커 못 붙이면 시계방향 90도 회전 (90->180->270)
    //회전해도 실패하면 해당 스티커 버리기
    int R,C; //행, 열
    int tmp;
    memset(map,false,sizeof(map));

    cin>>N>>M>>K;
    for(int i=0; i<K; i++){
        cin>>R>>C;
        sticker s;
        s.R = R, s.C = C;

        for(int p=0; p<R; p++){
            for(int q=0; q<C; q++){
                cin>>s.arr[p][q];
                if(s.arr[p][q]) s.area++;
            }
        }
        memcpy(s.original, s.arr, sizeof(s.original));
        stickers.push_back(s);
    }

    for(int i=0; i<stickers.size(); i++){
        ans += locate(i);
    }

    cout<<ans<<endl;

    return 0;
}