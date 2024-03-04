#include<iostream>
#include<vector>
using namespace std;

class node{
    public:
    char data;
    node * children[26];
    int child;
    bool isterminal;

    node(char ch){
        this->data = ch;
        for(int i = 0;i<26 ;i++){
            children[i]=NULL;
        }
        int child = 0;
        isterminal = false;
    }
};

class trie{
    node * root;
    public:
    trie(){
        root = new node('\0');
    }

    void insertUtil(node * root,string word){
        //base case
        if(word.length()==0){
            root->isterminal = true;
            return;
        }

        int index = word[0]-'a';
        node * child;

        if(root->children[index]!=NULL){
            child = root->children[index];
        }
        else{
            child = new node(word[0]);
            root->child++;
            root->children[index] = child;
        }

        insertUtil(child,word.substr(1));

    }

    void insert(string word){
        insertUtil(root,word);
    }
};

//by loop
string same(vector<string> &arr, int n)
{
    string ans;
    for (int i = 0; i < arr[0].length(); i++)
    {
        char ch = arr[0][i];
    

        bool match = false;

        for(int j = 1; j < arr.size(); j++) {
            if(arr[j][i]==ch && i < arr[j].size() )
                match = true;
            else{
                break;
            }
        }
        if(match==false)    
            break;
        else
            ans.push_back(ch);
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    vector<string> strs1 = {"apple", "app", "apricot"};
    vector<string> strs2 = {"flower", "flow", "flight"};
    vector<string> strs3 = {"dog", "racecar", "car"};
    vector<string> strs4 = {"prefix", "pre", "prelude"};

    string ans = same(strs4,3);
    cout<<ans;

    trie T;
    for (int i = 0; i < strs1.size(); i++)
    {
        T.insert(strs1[i]);
    }


    


    return 0;
}
