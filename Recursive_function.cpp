#include<iostream>
using namespace std;
#include<algorithm>

// 1
int fact(int n){ // recursive factorial function
    if(n == 0 || n == 1){
        return 1; //base case
    }else{
    
        return n * fact(n-1); // recursive relation
    }
}

// 2
double pow2(int n){  // recursive function for two power

    if(n == 0){
        return 1; // base case
    }else{
        n--;
        return 2 * pow2(n); // recursive relation
    }


}

// 3
void counting(int n){ // recursive function for printing valur 1 - n

    if(n == 0){ // base case
        return ;
    }
    counting(n-1); // recursive relation
    cout << n <<" ";   // procession Head recursion

}

// 4
int fib(int n){ // Recursive function for Nth term of Fibonacci series

    if(n  == 1){ // Base case
        
        return 0;

    }
    if(n == 2){ // Base case

        return 1; 
        
    }
    return (fib(n-1) + fib(n-2));  // Recursion relation

}

// 5
string sayDigit(int n){ // recursive fumction for printing the digits of a number in words

    string arr[10] = {"zero ","one ","two ","three ","four ","five ","six ","seven ","eight ","nine "};


    if(n % 10 ==  n){ // Base case

        return arr[n];
    }

   return  sayDigit(n/10) + arr[(n%10)] ; // Recursion relation + processing

}

// 6
bool sorted(int arr[],int n){ // Recursive function for check an array if sorted or not


    if(n == 0 || n == 1){ // Base case
        return true;
    }

    if(arr[0] > arr[1]){ // Base case
        return false;
    }

    return sorted(arr+1,n-1);  // Recursion relation

}

// 7
int sum(int arr[],int n){ // recursive function for calculating sum of all element in an array

    if(n == 1){ // Base case
        return arr[0];
    }

    return sum(arr+1,n-1) + arr[0]; // Recursion relation + processing
}

// 8
bool binarySearch(int arr[],int start,int end ,int tar){ // recursive function for Binary Search

    int mid = start + (end - start)/2;

    if(start > end){ // Base case
        return false;
    }
    if(arr[mid] == tar){ // Base case
        return true;
    }
    
    if(arr[mid] > tar){
        return binarySearch(arr,start,mid-1,tar); // Recursion relation
    }else{
        return binarySearch(arr,mid+1,end,tar); // Recursion relation
    }

}


// 9
bool linearSearch(int arr[],int tar,int n){ // recursive function foor Linear Search

    if(arr[0] == tar){  // Base case

        return true;
    }
    if(n == 0){ // Base case
        return false;
    }

    return linearSearch(arr+1,tar,n-1); // Recursion relation

}

// 10
void reverseString(string& s,int start){ // recursion function to reverse a string

    if(start > s.length()- start -1){ // Base case
        return ;
    }

    swap(s[start],s[s.length()- start -1]);//Processing
    start++;
    reverseString(s,start); // recursion relation

}

// 11
bool checkPalindrome(string &s,int i){  // recursive function for checking a number is palindrome or not

    if(s[i] != s[s.length()-i-1]){ // Base case
        return false;
    }
    if( i == s.length()-i-1){ // Base case
        return true;
    }
    i++;
    return checkPalindrome(s,i); // recursive call
}

// 12
int power(int a,int b){  //Recursive function for Calculating power b raise to the power of a

    if(b == 0){  // Base case
        return 1;
    }if(b == 1){ // Base case
        return a;
    }

    if(b %2 == 0){
        return (power(a,b/2) * power(a,b/2));  // recursive call 
    }else{
        return (power(a,b/2) * power(a,b/2) * a); // recursive call 
    }
}

// 13
void sortArrayBubble(int arr[],int n){ // Bubble sort using recursion

    if(n == 0 || n == 1){ // base case
        return ;
    }

    for(int i = 0;i < n-1;i++){

        if(arr[i] > arr[(i+1)]){ // processing
            swap(arr[i] , arr[(i+1)]);
        }
    }

    sortArrayBubble(arr,n-1); // Recursive call
}

// 14
void sortArraySelection(int arr[],int n ,int s){ // Selection sort using recursion

    if(n == 0 || n == 1){  // Base case
        return ;
    }
    if(s == n){ // Base case
        return ;
    }

    for(int i = s+1;i < n;i++){ // Processing

        if(arr[i] < arr[s]){
            swap(arr[i],arr[s]);
        }
    }

    sortArraySelection(arr,n,s+1); // Recursive call
}

// 15
void sortArrayInsertion(int arr[],int n , int i ){ // Insertion sort using recursion

    if( n == 1|| n == 0){ // Base case
        return ; 
    }
    int temp = arr[i]; // Processing
    int j = i-1;
    for(j;j >= 0;j--){
        if(arr[j] > temp){
            arr[j+1] = arr[j];
        }else{
            break;
        }
    }
    arr[j+1] = temp;

    sortArrayInsertion(arr,n-1,i+1); // recursive call
}

// 16
void printArray(int *arr,int n){  // Function for printing an Array

    for(int i = 0;i < n;i++){
        cout << arr[i] <<" ";
    }cout << endl;

}

// 17
void merge(int arr[],int s,int e){ // function for merge two sorted part of an array

    int mid = s + (e-s)/2;

    int len1 = (mid - s + 1); // length of left part
    int len2 = (e - mid); // lenght of right part

    // creating two array for left and right part respectively
    int *first = new int[len1];
    int *second = new int[len2];

    int main_idx = s;

    // copying first len1 no of element in  first array
    for(int i = 0;i < len1;i++){
        first[i] = arr[main_idx++];
    }

    main_idx = mid+1;
    // copying first len2 no of element in second array
    for(int i = 0;i < len2;i++){
        second[i] = arr[main_idx++];
    }

    int first_idx = 0;
    int second_idx = 0;
    int k = s;

    while(first_idx < len1 && second_idx < len2){ // copying elements in sorted way 

        if(first[first_idx] < second[second_idx]){
            arr[k++] = first[first_idx++];
        }else{
            arr[k++] = second[second_idx++];
        }

    }
    
    while(first_idx < len1){ // copying remaining elements from first array (if any)
        arr[k++] = first[first_idx++]; 
    }

    while(second_idx < len2){// copying remaining elements from second array (if any)
        arr[k++] = second[second_idx++];
    }

    delete []first;
    delete []second;

}

// 18
void mergeSort(int arr[],int s,int e){ // Merge sort function

    if(s >= e){
        return ; // Base case
    }

    int mid = s + (e-s)/2; // calculating miid value

    mergeSort(arr,s,mid); // recursive call
    mergeSort(arr,mid+1,e); // recursive call

    merge(arr,s,e); // merge function to merge to array

}

int main(){

    int arr[10] = {9,8,11,6,25,-4,3,21,1,0};
    
    
    mergeSort(arr,0,9);
    printArray(arr,10);
    cout << endl;
}