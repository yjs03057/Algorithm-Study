#include <iostream>
#include <cstring>
using namespace std;
int map[102][102];
int N,L; //L->경사로 길이
int ans=0;
int main(){
    cin>>N>>L;
    memset(map, 0, sizeof(map));
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin>>map[i][j];
        }
    }

    int flat=0, cur, desc_flag=0;
    //가로
    for(int i=1; i<=N; i++){
        cur = map[i][1];
        flat=1;
        desc_flag=0;
        for(int j=2; j<=N; j++){
            if(cur==map[i][j]) flat++;
            else if(map[i][j] - cur == 1 && flat >= L){
                //높이가 1 높아질 경우인데, 경사로 설치 가능
                cur = map[i][j];
                flat=1;
            }
            else if(cur - map[i][j] == 1){
                //높이가 1 낮아질 경우 -> 미래에 flat>=L 이어야 함
                if(desc_flag) break;
                desc_flag=1;
                cur = map[i][j];
                flat=1;
            }
            else{
                //불가
                break;
            }

            if(flat>=L && desc_flag){
                desc_flag=0;
                flat=0;
            }
            //끝에 다다름
            if(j==N && desc_flag==0) ans++;
        }
    }

    //세로
    for(int i=1; i<=N; i++){
        cur = map[1][i];
        flat=1;
        desc_flag=0;
        for(int j=2; j<=N; j++){
            if(cur==map[j][i]) flat++;
            else if(map[j][i] - cur == 1 && flat >= L){
                //높이가 1 높아질 경우인데, 경사로 설치 가능
                cur = map[j][i];
                flat=1;
            }
            else if(cur - map[j][i] == 1){
                //높이가 1 낮아질 경우 -> 미래에 flat>=L 이어야 함
                if(desc_flag) break;
                desc_flag=1;
                cur = map[j][i];
                flat=1;
            }
            else{
                //불가
                break;
            }

            if(flat>=L && desc_flag){
                desc_flag=0;
                flat=0;
            }
            //끝에 다다름
            if(j==N && desc_flag==0) ans++;
        }
    }

    cout<<ans<<endl;

    return 0;
}