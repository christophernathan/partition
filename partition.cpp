#include <iostream>
#include <vector>
using namespace std;

const int N = 5;

int* partition(int C[N]){
    int maxSum=0;
    for (int i=0;i<N;i++){ maxSum+=C[i]; }
    bool T[maxSum];
    for (int i=0;i<maxSum;i++){ T[i]=false; }
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

    for (int i=0;i<maxSum;i++){
        cout << i << ": " << T[i] << endl;
    }
}

int main(){

    int C[N] = {1,2,5,7,9};
    partition(C);

}

