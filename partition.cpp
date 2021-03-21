#include <iostream>
using namespace std;

const int N = 5; // number of integers in array

bool partition(int C[N]){ // original partition problem solution
    int maxSum=0;
    for (int i=0;i<N;i++){ maxSum+=C[i]; }
    bool T[maxSum+1];
    for (int i=0;i<=maxSum;i++){ T[i]=false; }
    T[0]=true;
    int R=0;
    for (int i=0;i<N;i++){
        for (int j=R;j>=0;j--) if (T[j]){
                T[j+C[i]]=true;
                if (j+C[i]>R){ R=j+C[i]; }
            }
    }

    for (int i=0;i<=maxSum;i++){
        cout << i << ": " << T[i] << endl;
    }
    return (maxSum%2==0 && T[maxSum/2]);
}

bool partition_duplicates(int* C, int* D){ // partition solution if there are duplicate integers in the given array
    int maxSum=0;
    for (int i=0;i<N;i++){ maxSum+=D[i]*C[i]; }
    bool T[maxSum+1];
    for (int i=0;i<=maxSum;i++){ T[i]=false; }
    T[0]=true;
    int R=0;
    for (int i=0;i<N;i++){
        for (int j=R;j>=0;j--) if (T[j]){
                for (int k=1;k<=D[i];k++){
                    T[j+k*C[i]]=true;
                    if (j+k*C[i]>R){ R=j+k*C[i]; }
                }
            }
    }

    for (int i=0;i<=maxSum;i++){
        cout << i << ": " << T[i] << endl;
    }
    return (maxSum%2==0 && T[maxSum/2]);
}

int coin_combination(int* C, int query){ // finds number of ways to make change for the query total, given integer (coin) values
    int T[query+1];
    for (int i=0;i<=query;i++){ T[i]=0; }
    T[0]=true;
    for (int i=0;i<N;i++){
        for (int j=0;j+C[i]<=query;j++){
            T[j+C[i]] += T[j];
        }
    }

    for (int i=0;i<=query;i++){
        cout << i << ": " << T[i] << endl;
    }
    return T[query];
}


int main(){

    int C[N] = {1,2,5,7,9};
    int D[N] = {1,1,1,1,7};
    partition_duplicates(C,D);
    //coin_combination(C,7);

}

