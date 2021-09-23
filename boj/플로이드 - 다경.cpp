#include <iostream>
#include <cstring>
using namespace std;
int n,m;
int a,b,c;
long long arr[101][101];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m;
    //초기화
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            arr[i][j]=987654321;
            if(i==j) arr[i][j]=0;
        }
    }

    for(int i=0; i<m; i++){
        cin>>a>>b>>c;
        if(arr[a][b] > c) arr[a][b] = c;
    }

    for(int k=1; k<=n; k++){ //거쳐가는 지점
        for(int i=1; i<=n; i++){ //시작
            for(int j=1; j<=n; j++){ //도착
                if(arr[i][k]==-1 && arr[k][j]==-1) continue; //갈 수 없음
                if(arr[i][k]==-1){
                    if(arr[k][j] < arr[i][j]){
                        arr[i][j] = arr[k][j];
                        continue;
                    }
                }
                if(arr[k][j]==-1){
                    if(arr[i][k] < arr[i][j]){
                        arr[i][j] = arr[i][k];
                        continue;
                    }
                }
                if(arr[i][k]+arr[k][j] < arr[i][j]){
                    arr[i][j] = arr[i][k]+arr[k][j];
                }
            }
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(arr[i][j]==987654321){
                cout<<0<<' ';
                continue;
            }
            cout<<arr[i][j]<<' ';
        }
        cout<<endl;
    }

    return 0;
}