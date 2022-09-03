#include<iostream>
using namespace std;


//2. Tính tổng S=1+1/2+...+1/n
    double calculator(int n){
    if(n == 0){
        return -1;
    }
    else{
    double sum = 0.0;
    for(int i = 1; i <= n; i++){
        sum += (double)1/i;
    }
    return sum;
    }
}

int main(int argc, char const *argv[])
{
    cout << calculator(54);
    return 0;
}
