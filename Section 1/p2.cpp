#include <iostream>
using namespace std;

int main(){

    // Loop through numbers 1 to 100
    for(int i=1; i<=100; i++){

        int fizz = i%3;
        int buzz = i%5;

        // If divisible by both 3 and 5, print "FizzBuzz"
        if(fizz==0 && buzz==0){

            cout<<"FizzBuzz";
        }
        //For every number divisible by 5, print 'Buzz'
        else if(buzz==0){

            cout<<"Buzz";
        }
        //For every number divisible by 3, print 'Fizz'
        else if(fizz==0){

            cout<<"Fizz";
        }
        else{
            cout<<i;
        }
        cout<<", ";
    }

    return 0;
}