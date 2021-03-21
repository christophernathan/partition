#include <iostream>
#include <vector>
using namespace std;

const int N = 5;

bool partition(int C[N]){
    int maxSum=0;
    for (int i=0;i<N;i++){ maxSum+=C[i]; }
    bool T[maxSum+1];
    for (int i=0;i<=maxSum;i++){ T[i]=false; }
    T[0]=true;
    int R=0;
    for (int i=0;i<N;i++){
        for (int j=R;j>=0;j--){
            if (T[j]){
                T[j+C[i]]=true;
                if (j+C[i]>R){ R=j+C[i]; }
            }
        }
    }

    for (int i=0;i<=maxSum;i++){
        cout << i << ": " << T[i] << endl;
    }
    return (maxSum%2==0 && T[maxSum/2]);
}

bool partition_duplicates(int* C, int* D){
    int maxSum=0;
    for (int i=0;i<N;i++){ maxSum+=D[i]*C[i]; }
    bool T[maxSum+1];
    for (int i=0;i<=maxSum;i++){ T[i]=false; }
    T[0]=true;
    int R=0;

    for (int i=0;i<N;i++){
        for (int j=R;j>=0;j--){
            if (T[j]){
                for (int k=1;k<=D[i];k++){
                    T[j+k*C[i]]=true;
                    if (j+k*C[i]>R){ R=j+k*C[i]; }
                }
            }
        }
    }

    for (int i=0;i<=maxSum;i++){
        cout << i << ": " << T[i] << endl;
    }
    return (maxSum%2==0 && T[maxSum/2]);
}


int main(){

    int C[N] = {1,2,5,7,9};
    int D[N] = {1,1,1,1,7};
    partition_duplicates(C,D);

}

