#include <iostream>
#include <vector>
using namespace std;

const int N = 10;

int C[N] = {1,2,3,4,5,6,7,8,9,10};

int* partition(int C[N]){
    int maxSum=0;
    for (int i=0;i<N;i++){ maxSum+=C[i]; }
    bool T[maxSum];
    for (int i=0;i<maxSum;i++){ T[i]=false; }
    int R=0;
    
}

int main(){

}

