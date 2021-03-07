#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector<int> chu;

int main(){
    int tmp;

    cin>>n;
    for(int i=0; i<n; i++){
        cin>>tmp;
        chu.push_back(tmp);
    }
    sort(chu.begin(), chu.end());

    //1,1,2,3,6,7,30
    //추의 개수만큼 돌기
    //1~sum의 무게까지
    //sum+1, 추의 무게를 비교
    // => 추가 sum+1보다 크지 않으면 sum에 추 더하기
    // => 추로 1~sum까지 만들 수 있다는 것

    // ex) 1,1,4
    // sum+1==추 => 추 자신으로 만들 수 있음
    // sum+1<추 => 앞의 추들로 만들 수 있음.

    int sum=0;
    for(int i=0; i<n; i++){
        if(sum+1 >= chu[i]){
            sum += chu[i];
        }
        else{
            break;
        }
    }

    cout<<sum+1<<endl;

    return 0;
}