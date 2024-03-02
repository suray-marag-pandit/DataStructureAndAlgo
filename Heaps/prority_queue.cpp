#include<iostream>
#include<queue>
using namespace std;


int main(int argc, char const *argv[])
{
    //max heap;
    priority_queue<int> pq;

    pq.push(5);
    pq.push(4);
    pq.push(11);
    pq.push(2);
    pq.push(8);
    pq.push(10);

    cout<<pq.size()<<endl;

    //min heap

    priority_queue<int,vector<int>,greater<int>> mpq;

    mpq.push(5);
    mpq.push(4);
    mpq.push(1);
    mpq.push(2);
    mpq.push(3);

    cout<<mpq.top()<<endl;

    return 0;
}
