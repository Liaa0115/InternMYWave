#include <iostream>
using namespace std;

string SquareRoot(int x){
    
    string result;
    for(int i=2; i<=12;i++){
        if(x==(i*i)){
            result = to_string(i);
            break;
        }
        else{
            result="Not a perfect square root number.";
        }
    }

    return result;
}

int main(){

    int x;
    cout<<"Enter a number: ";
    cin>>x;

    cout<<"Square root of "<<x<<" is: "<<SquareRoot(x);

    return 0;
}