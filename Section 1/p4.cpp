#include <iostream>
using namespace std;

int main(){
    int list1[6] ={4,5,2,3,1,6};
    int list2[6] ={8,7,6,9,4,5};

    cout<<"Output: ";

    // Loop through each element in list1
    for(int i=0; i<6;i++){
        // For each element in list1, loop through each element in list2
        for(int j=0; j<6; j++){
            // If an element in list1 matches an element in list2, print it
            if(list1[i]==list2[j]){
                cout<<list1[i]<<", ";
            }
        }                
    }

   return 0;
}