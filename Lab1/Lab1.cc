/*
Lab 1
Liz Racca 
Allan Chandy
*/

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

//Problem 1
int helloWorld() {
     cout << "Hello World" << endl;
     return 0;  
} 

//Problem 2
int collatz(int n){
    int count =0;
    do {
        if (n%2==0){
            n=n/2;
        }
        else{
            n=n*3+1;
        }
        count++;
    }while(n!=1); 
    return count;
}

//Problem 2b
void testCollatz(){
    string input;
    cout << "Enter a positive natural number" << endl;
    cin >> input;
    int n1=atoi(input.c_str());
    cout << "Enter a positive natural number" << endl;
    cin >> input;
    int n2=atoi(input.c_str());
    if (n1>n2){ //swap n1 and n2 if needed
        int temp=n1;
        n1=n2;
        n2=temp;
    }
    for (int i=n1; i<n2; i++){
        int count;
        count=collatz(i);
        cout << i << " , "<< count << endl;
        cout <<"Collatz Conjecture is still working" << endl;
    }
    return; 
}

//Problem 3
void swap(int *n1, int *n2){
    int temp=*n1;
    *n1=*n2; 
    *n2=temp;
}

bool order(int *n1, int *n2, int *n3){
    bool ordered = true; 
    int temp;
    if (*n1>*n2){
        ordered=false;
        swap(n1, n2);   
    }
    if (*n2>*n3){
        ordered=false;
        swap(n2,n3);
    }
    if (*n1>*n3){
        ordered=false;
        swap(n1,n3);
    }
    if (*n1>*n2){
        ordered=false;
        swap(n1, n2);   
    }
    return ordered;  
        

}

/*
//Problem 4
bool perfectNumber(int n){

}
*/

//problem 6
void randomizeArray(int *arr, int size){    
    for (int i=0; i<size; i++){
        arr[i] = rand()% 100 - 50;
    }
}

//problem 6b
void printArray(int *arr, int size){
    for (int i=0; i<size; i++){
        cout << arr[i] << " ";
    }
    cout << endl; 
}

//problem 8
int findMin(int *arr, int size){
    int min = arr[0];
    for (int i=1; i<size; i++){
        if (arr[i]<min){
            min=arr[i];
        }
    }
    return min;
}

//problem 10 waiting on class

//problem 12
void indexSum(





int main(){
    /*
    //problem 1
    helloWorld();

    //problem 2
    string input;
    cout << "Please enter a positive natural number"<< endl;
    cin >> input;
    int n= atoi(input.c_str());
    cout << collatz(n)<< endl; 

    //problem 2b
    testCollatz(); 
    return 0; 

    //problem 3
    srand(time(NULL)); //seeds random based  on time
    int x1 = rand()% 20;
    int x2 = rand()% 20;
    int x3 = rand()% 20;
    cout << x1 << " " << x2 << " " << x3 << endl;
    bool ordered =order(&x1,&x2,&x3);
    if (!ordered){
         cout << x1 << " " << x2 << " " << x3 << endl;
    }

    //problem 6
    int size = rand()% 30 +20; 
    int arr[size]; 
    randomizeArray(&arr[0], size);

    //problem 6b
    printArray(&arr[0], size); 

    //problem 8
    cout << findMin(&arr[0], size) << endl;
    */ 

    //problem 12
    int ***arr3 = NULL; 
    int x = -1; 
    int y = -1;
    int z = -1; 





}
