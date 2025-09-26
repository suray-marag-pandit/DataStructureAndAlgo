#include<iostream>
using namespace std;


class complex{
    private:
    int real =10;
    int imaginary= 10;

    public:
    void operator+ (complex &c){
        this->real +=c.real;
        this->imaginary+=c.imaginary;
    }

    void print(){
        cout<<this->real<<" "<<this->imaginary<<endl;
    }

};

int main(){
    complex * c1 = new complex;
    complex * c2 = new complex;

    *c1 + *c2;

    c1->print();

    delete c1;
    delete c2;
    return 0;
}