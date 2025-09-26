#include<iostream>
using namespace std;

class student{
    private:    //accessible inside the clas
    int id = 123456789;

    protected: //accessible in class and inhereited class 
    string class_teacher = "mam";


    public:  //accessible anywhere
    int rollNo = 1;
    string name;
    
    //to change private properties we make public method
    void setName(int id){
        this->id = id;
    }
};
int main(){
    //static allocation
    student me;

    //dynamic allocation 
    student * s = new student;
    cout<<sizeof(me)<<endl; //empty class have 1 byte size ..here is 4 due to int;

    getline(cin,me.name);
    cout<<me.rollNo<<endl;
    cout<<me.name<<endl;

    return 0;
}