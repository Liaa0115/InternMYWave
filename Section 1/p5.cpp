#include <iostream>
using namespace std;

int main(){
    int FinalList[12];
    int FinalSize = 0;
    int list1[6] ={4,5,2,3,1,6};
    int list2[6] ={8,7,6,9,4,5};

    bool equal=false;    

    //List 1
    for(int i=0; i<6;i++){
        for(int j=0; j<6; j++){
            if(list1[i]==list2[j]){
                equal=true;
                break;                
            }else{
                equal=false;
            }
        }
        if(!equal){
            FinalList[FinalSize++] = list1[i];
        }                
    }

    //List 2
    for(int i=0; i<6;i++){
        for(int j=0; j<6; j++){
            if(list2[i]==list1[j]){
                equal=true;
                break;                
            }else{
                equal=false;
            }
        }
        if(!equal){
            FinalList[FinalSize++] = list2[i];
        }                
    }

    //Ascending sorting 
    for (int i = 0; i < FinalSize - 1; i++) {
        for (int j = i + 1; j < FinalSize; j++) {
            if (FinalList[i] > FinalList[j]) {
                // Swap elements if they are in the wrong order
                int temp = FinalList[i];
                FinalList[i] = FinalList[j];
                FinalList[j] = temp;
            }
        }
    }

    //Output
    cout<<"Output: ";
    for (int i = 0; i < FinalSize; i++) {
        cout << FinalList[i];
        if (i < FinalSize - 1) {
            cout << ", ";
        }
    }
    cout << endl;

   return 0;
}