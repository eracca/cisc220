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


bool order(int *n1, int *n2, int *n3){
    bool ordered = true; 
    int *temp; 
    if (n1>n2){
        ordered=false;
        *temp=*n1;
        *n1=*n2; 
        *n2=*temp;
    }
    if (n2>n3){
        ordered=false;
        *temp=*n2;
        *n2=*n3;
        *n3=*temp;
    }
    if (n1>n3){
        ordered=false;
        *temp=*n1;
        *n1=*n3;
        *n3=*temp;
    }
    return ordered;  
        

}

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
    
    */ 

    //problem 3
    srand(time(NULL)); //seeds random based  on time
    int x1 = rand()% 20;
    int x2 = rand()% 20;
    int x3 = rand()% 20;
    cout << x1 << " " << x2 << " " << x3 << endl;
    bool ordered =order(&x1,&x2,&x3);
    cout <<ordered << endl;
    if (!ordered){
         cout << x1 << " " << x2 << " " << x3 << endl;
    }
}
