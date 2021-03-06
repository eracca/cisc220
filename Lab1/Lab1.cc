/*
Lab 1
Liz Racca 
Allan Chandy
*/

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int helloWorld();
int collatz(int i);
void testCollatz(); 
void swap(int *n1, int *n2);
bool order(int *n1, int *n2, int *n3);
bool perfectNumber(int n, int d, int sum);
void refSwap(int &n1, int &n2); 
void randomizeArray(int *arr, int size);
void printArray(int *arr, int size);   
void reverseArray(int *arr, int size);  
int findMin(int* arr, int size); 
int sumArray(int* arr, int size);
int lizSort(int* arr, int size);
int* lowPass( int* arr, int size, int win);
void createMatrix(int*** & arr, int& x, int& y, int& z);
void printMatrix(int*** arr, int& x, int& y, int& z);


int main(){
    srand(time(NULL)); //seeds random function with time

    //problem 1
    cout<< "problem 1" << endl; 
    helloWorld();

    //problem 2
    cout<< "problem 2" << endl; 
    string input;
    cout << "Please enter a positive natural number"<< endl;
    cin >> input;
    int n= atoi(input.c_str());
    cout << collatz(n)<< endl; 

    //problem 2b
    cout<< "problem 2b" << endl;
    testCollatz();  

    //problem 3
    cout << "problem 3" << endl; 
    int x1 = rand()% 20;
    int x2 = rand()% 20;
    int x3 = rand()% 20;
    cout << x1 << " " << x2 << " " << x3 << endl;
    bool ordered =order(&x1,&x2,&x3);
    if (!ordered){
         cout << x1 << " " << x2 << " " << x3 << endl;
    }

    //problem 4
    cout << "problem 4" << endl;
    for (int i=3; i<30; i++){
        cout << i << endl; 
        cout << perfectNumber(i, 1, 0) << endl;
    }

    //problem 5
    cout << "problem 5" << endl;  
    x1 = rand()% 20;
    x2 = rand()% 20;
    x3 = rand()% 20;
    cout << x1 << " " << x2 << " " << x3 << endl;
    ordered =order(&x1,&x2,&x3);
    if (!ordered){
         cout << x1 << " " << x2 << " " << x3 << endl;
    }

    //problem 6
    cout << "problem 6" << endl; 
    int size = rand()% 30 +20; 
    int arr[size]; 
    randomizeArray(&arr[0], size);
    
    //problem 6b
    cout << "problem 6b" << endl;
    printArray(&arr[0], size); 

    //problem 7
    cout << "problem 7" << endl;
    reverseArray(&arr[0], size);
    printArray(&arr[0], size); 

    //problem 8
    cout << "problem 8" << endl;
    cout << findMin(&arr[0], size) << endl; 

    //problem 9
    cout << "problem 9" << endl;
    int sumSize=5;
    int arr9[sumSize]; 
    randomizeArray(&arr9[0], sumSize);
    printArray(&arr9[0], sumSize);
    int sum=sumArray(&arr9[0], sumSize);
    cout << "sum: " << sum << endl; 

    //problem 10
    cout << "problem 10" << endl; 
    int sortSize = 5; 
    int sortArr[sortSize];
    randomizeArray(&sortArr[0], sortSize); 
    printArray(&sortArr[0], sortSize); 
    cout<< "comparisons: " <<  lizSort(&sortArr[0],sortSize) << endl; 
    printArray(&sortArr[0], sortSize); 

    //problem 11
    cout << "problem 11" << endl; 
    size=20; 
    int noiseArr[size];
    randomizeArray(&noiseArr[0], size); 
    printArray(&noiseArr[0], size); 
    int win= rand()% 4 +3;
    if (win%2==0){
        win++;
    }
    cout << "window: " << win << endl; 
    int* filterArr=lowPass(&noiseArr[0], size, win);
    printArray(&filterArr[0], size); 
    delete [] filterArr; 

    //problem 12
    cout << "problem 12" << endl;
    int ***arr3=NULL; 
    int x = -1; 
    int y = -1;
    int z = -1; 
    createMatrix(arr3, x, y, z); 
    printMatrix(arr3, x, y, z); 
    for (int i=0; i<x; i++){
        for (int j=0; j<y; j++){
            delete[] arr3[i][j];
        }
        delete[] arr3[i];
    }
    delete[] arr3;
}


//Problem 1
int helloWorld() {
    //prints Hello World to the console
     cout << "Hello World" << endl;
     return 0;  
} 

//Problem 2
int collatz(int n){
    //carries out collatz process until number is 1
    //returns the number of operations required
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
    //asks user to input two number,  tests Collatz Conjecture for all numbers
    //in this range
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
        count=collatz(i); //test Collatz for numbers in range given by user
        cout << i << " , "<< count << endl;
        cout <<"Collatz Conjecture is still working" << endl;
    }
}

//Problem 3
void swap(int *n1, int *n2){
    //swaps n1 and n2
    int temp=*n1;
    *n1=*n2; 
    *n2=temp;
}

bool order(int *n1, int *n2, int *n3){
    //check if three numbers are ordered, return true if they are
    //order and  return false if they are not
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


//Problem 4
bool perfectNumber(int n, int d, int sum){
    //check if n is a perfect number   
    if(sum==n && d==n ){//end condition for perfect number
        return true;
    }
    else if(sum!=n && d==n){//end condition for not perfect 
        return false;
    }
    else{
        if (n%d==0){
             return perfectNumber(n, d+1, sum+d);//d is a divisor, run again
        }
        else{
            return perfectNumber(n,d+1, sum);//d is not a divisor, run again
        }
    }
}

//Problem 5
void refSwap(int &n1, int &n2) {
    //swap using call by reference
    int temp = n1;
    n1 = n2;
    n2 = temp;
}

//problem 6
void randomizeArray(int *arr, int size){    
    //randomize an array given array and size
    for (int i=0; i<size; i++){
        arr[i] = rand()% 100 - 50; //values between -50 and 50;
    }
}

//problem 6b
void printArray(int *arr, int size){
    //print array given array and size
    for (int i=0; i<size; i++){
        cout << arr[i] << " ";
    }
    cout << endl; 
}

//problem 7
void reverseArray(int *arr, int size){
    //revese array given array and size   
    int temp; 
    int side;
    if (size%2==0){
        side=size/2;
    }
    else{
        side=(size-1)/2;
    }
    for (int i=0; i<side;  i++){
        temp=arr[i];
        arr[i]=arr[size-i-1];
        arr[size-i-1]=temp;
    }
}


//problem 8
int findMin(int *arr, int size){
    //finds minimum value in an array
    int min = arr[0];
    for (int i=1; i<size; i++){
        if (arr[i]<min){
            min=arr[i];
        }
    }
    return min;
}

//problem 9
int sumArray(int* arr, int size){
    //use recursion to sum the values in an array
    if (size<0){
        return arr[size]; 
    }
    else{
        return arr[size-1]+sumArray(arr, size-1); 
    } 
}


//problem 10
int lizSort(int *arr, int size){
    //sort an array, return the number of comparisons necessary
    //note: finding an average number of comparisons for a sort doesn't make sense since this sorting
    //algorithm takes a constant number of comparisons for each array length.
    //This particular sort is of order n^2 and is considered very low performance.
    int temp;
    int m; 
    int mindex; 
    int comp=0; 
    for (int i=0; i<size; i++, comp++){
        m=arr[i];
        mindex=i;  
        for (int j=i; j<size; j++, comp++){
            comp++; 
            if (arr[j]< m){
                m=arr[j];
                mindex=j;
            }
        }
        temp=arr[i];
        arr[i]=m;
        arr[mindex]=temp; 
    }
    return comp; 
}

//problem 11
int* lowPass(int *arr, int size, int win){
    //filter an array with a window so that each value is the average of its window
    int *arr2= new int[size]; 
    int sum;
    int side= (win-1)/2;
    for (int i=0; i<side; i++){
        arr2[i]=0;
        arr2[size-i]=0;  
    }
    for (int i=side; i<(size-side); i++){
        sum=0;
        for (int j= -side; j<= side;j++){
            sum+=arr[i+j];
        }
        arr2[i]=sum/win;
    }
    return arr2;
}


//problem 12
void createMatrix(int*** & arr, int& x, int& y, int& z){
    //create 3d matrix with the sum of the index values in each position
    x=rand()%4 +2; 
    y=rand()%4 +2; 
    z=rand()%4 +2;
    //allocate memory for the array
    arr = new int **[x];
    for (int i=0; i<x; i++){
        arr[i]=new int *[y];
        for (int j=0; j<y; j++){
            arr[i][j]=new int[z]; 
        }
    }
    //fill array with sum of indicies
    for (int w=0; w<x; w++){
        for (int h=0; h<y; h++){
            for (int d=0; d<z; d++){
                arr[w][h][d]=w+h+d;
            }
        }
    }
}

void printMatrix(int*** arr,  int& x, int& y, int& z){
    //print a 3d matrix
    for (int i=0; i<x; i++){
        for (int j=0; j<y; j++){
            for (int k=0; k<z; k++){
                cout << arr[i][j][k] << ", i:" << i << " j:" << j <<
                 " k:" << k << endl; 
            }
        }
    }
}
