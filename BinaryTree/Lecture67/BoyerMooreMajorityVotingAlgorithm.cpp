#include<iostream>
#include<vector>
using namespace std;

int majorityElement(vector<int> v){
    int candidate=v[0];
    int occurence= 0;

    for(int i=0;i<v.size();i++){
        
        if(occurence==0){
            candidate==v[i];
        }
        else{
            if(candidate==v[i]){
                occurence++;
            }
            else{
                occurence--;
            }
        }
    }

    int count=0;
    for(int i=0;i<v.size();i++){
        if(v[i]==candidate)
            count++;
    }

    if(count>=v.size()/2){
        return candidate;
    }
    return -1;
}

int main()
{
	vector<int> v = { 1, 1, 1, 1,3,3,3,3,3,3, 2, 5, 4 };
	int majority = majorityElement(v);
	cout << " The majority element is : " << majority;
	return 0;
}
