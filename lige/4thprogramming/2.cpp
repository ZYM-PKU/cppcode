#include<iostream>
#include<cmath>
#include<iomanip>
#include<algorithm>
using namespace std;
int main(){
    int G;
    int n,m,k;
    int matrixa[100][100]={0};
    int matrixb[100][100]={0};
    int ans[100][100]={0};
    cin>>G;
    for(int x=0;x<G;x++){
        cin>>n>>m>>k;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>*(*(matrixa+i)+j);
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<k;j++){
                cin>>*(*(matrixb+i)+j);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<k;j++){
                for(int t=0;t<m;t++){
                    *(*(ans+i)+j)+=(*(*(matrixa+i)+t))*(*(*(matrixb+t)+j));
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<k;j++){
                if(j==k-1){
                    cout<<*(*(ans+i)+j)<<endl;
                }
                else{
                    cout<<*(*(ans+i)+j)<<' ';
                }

            }
        }
        memset(matrixa,0,sizeof(matrixa));
        memset(matrixb,0,sizeof(matrixb));
        memset(ans,0,sizeof(ans));
    }
    return 0;
}