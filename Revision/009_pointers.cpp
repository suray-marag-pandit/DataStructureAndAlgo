// #include<iostream>
// using namespace std;


// void function(int *q){
//     **q = 20;
//     cout<<*q<<endl;

// }


// int main(){
//     // int number = 10;
//     // int * pointer = &number;
//     // cout<<sizeof(pointer);

//     // int * q = 0;
//     // q = &number;
//     // cout<<pointer<<" "<<q<<endl;    return 0;
//     // cout<<endl;

//     // int arr[10]= {1,2,3,4,56,7,8};
//     // cout<<*(arr+5)<< " "<<5[arr];



//     //char pointers

//     // char arr[6] = "aaabc";
//     // char * pointer  =&arr[0];

//     // cout<<arr<<" "<<pointer<<endl;

//     // cout<<endl ;

//     // char s = 'a';
//     // cout<<&s<<endl;


//     // int number= 10;
//     // function(&number);
//     // cout<<endl<<number;


//     int number = 10;
//     int * pointer1 = &number;
//     int ** pointer2 = &pointer1;

//     cout<<number<<endl;
//     cout<<&number<<endl;
//     cout<<pointer1<<endl;
//     cout<<&pointer1<<endl;
//     cout<<pointer2<<endl;
//     cout<<&pointer2<<endl;
//     function(pointer2);
//     cout<<*(*pointer2)<<endl;
// }

#include<iostream>
using namespace std;

void fun(int ** p){
    **p =20;
}
int main(){
    int number = 10;
    int * pointer = &number;
    int ** ptr = &pointer;

    fun(ptr);
    cout<<number<<endl;

    return 0;
}