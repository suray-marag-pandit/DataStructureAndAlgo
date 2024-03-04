#include<iostream>
using namespace std;

class node{
    public:
    char data;
    node * children[26];
    bool isterminal;

    node(char data){
        this->data= data;
        for (int i = 0; i < 26; i++)
        {
            children[i]= NULL;
        }
        isterminal=false;
    }
};

class trie{
        node * root;

    public:
    trie(){
        root = new node('\0');
    }

    void insertTool(node * root,string word){
        if(word.length()==0){
            root->isterminal= true;
            return;
        }

        int index = word[0] - 'a';
        node * child;


        if (root->children[index] != NULL){
            child = root->children[index];
        }
        else{
            child = new node(word[0]);
            root->children[index] = child;
        }

        insertTool(child,word.substr(1));
    }

    void insert(string word){
        insertTool(root,word);
    }
};

int main(int argc, char const *argv[])
{
    trie T;
    T.insert("Hello");
    return 0;
}
