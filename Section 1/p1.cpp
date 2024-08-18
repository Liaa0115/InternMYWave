//Sorting Code
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

void sort(int arr[], int n){
    for(int i=0; i<n-1;i++){
        for(int j=0; j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                //Swapping number in ascending order
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main(){
    // Estimate the maximum possible number of elements
    const int MAX_SIZE = 100;
    int numbers[MAX_SIZE];
    int count = 0;

    string input;
    cout << "Enter a set of random numbers: ";
    getline(cin, input);

    stringstream ss(input);
    string token;

    // Parse the numbers and populate the array
    while (getline(ss, token, ',') && count < MAX_SIZE) {
        numbers[count++] = stoi(token); // Convert string to integer and add to the array
    }

    // Sort numbers using Bubble Sort
    sort(numbers, count);

    // Display sorted numbers
    cout << "Sorted numbers: ";
    for (int i = 0; i < count; ++i) {
        cout << numbers[i] << ", ";
    }
    cout << endl;

    return 0;
}