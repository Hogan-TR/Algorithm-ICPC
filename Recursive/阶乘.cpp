#include <iostream>
using namespace std;
int func(int n){
    if(n == 0)
        return 0;
    if(n == 1)
        return 1;
    else
        return func(n-1) * n;
}
int main(){
    cout << "num = " << func(10) << endl;
    return 0;
}