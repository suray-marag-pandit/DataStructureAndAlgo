#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

class heap
{
    int arr[100];
    int size = 0;

public:
    heap()
    {
        arr[0] = -1;
        size = 0;
    }

    void insert(int val)
    {
        size = size + 1;
        int index = size;
        arr[index] = val;

        while (index > 1)
        {
            int parent = index / 2;

            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
            {
                break;
            }
        }
    }

    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left < n && arr[largest] < arr[left])
        largest = left;
    if (right < n && arr[largest] < arr[right])
        largest = right;

    if(largest!=i){
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }
}

int main(int argc, char const *argv[])
{
    heap *h = new heap();

    // h->insert(10);
    // h->insert(14);
    // h->insert(19);
    // h->insert(35);
    // h->insert(26);
    // h->insert(31);
    // h->insert(44);
    // h->insert(27);
    // h->insert(42);
    // h->insert(33);
    // h->insert(1);
    // h->print();

    // delete h;

    // 10 14 19 26 31 42 27 44 35 33
    int arr[6] = {-1,54,53,55,52,50};
    int n = sizeof(arr)/sizeof(arr[0]);
    for (int  i = n/2; i >0; i--)
    {
        heapify(arr,n,i);
    } 
    
    for (int i = 1; i <n; i++)
    {
        cout<<arr[i]<<endl;
    }cout<<endl;
    
    return 0;
}