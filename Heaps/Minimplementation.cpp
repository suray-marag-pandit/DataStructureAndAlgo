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

            if (arr[parent] > arr[index])
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

int main(int argc, char const *argv[])
{
    heap *h = new heap();

    h->insert(10);
    h->insert(14);
    h->insert(19);
    h->insert(35);
    h->insert(26);
    h->insert(31);
    h->insert(44);
    h->insert(27);
    h->insert(42);
    h->insert(33);
    h->insert(1);
    h->print();

    delete h;
    return 0;

}