#include<iostream>
using namespace std;

// tries
class trieNode{
    public:
        char data;
        trieNode* children[26];
        bool isTerminal;

        // constructor
        trieNode(char data){
            this->data = data;
            for( int i = 0; i < 26; i++ ){
                children[i] = NULL;
            }
            this->isTerminal = false;
        }
};

// insert into the trie
void insertTrie( trieNode* &root, string str ){
    // base case if the length of string is 0 mark it as terminal and return
    if( str.length() == 0 ){
        root->isTerminal = true;
        return;
    }

    int childInd = str[0] - 'a';
    char ch = str[0];
    string newStr = str.substr(1);

    // check if the child of root contain the the character or not
    // if contain then move to chld
    if( root->children[childInd] != NULL ){
        //RR
        insertTrie(root->children[childInd], newStr);
    }
    // if the child of root doest not contain the character then create the child and move to new child
    else{
        trieNode *child = new trieNode(ch);
        root->children[childInd] = child;
        // RR
        insertTrie(root->children[childInd], newStr);
    }
}

// search in Trie
bool searchTrie( trieNode *root, string word){
    // base case 
    if( word.length() == 0 ){
        // check if it is the terminal node or not
        return root->isTerminal;
    }

    int childInd = word[0] - 'a';
    char ch = word[0];
    string newWord = word.substr(1);

    // check if the child of root contains the character or not
    // if yes, move to it child and search
    if( root->children[childInd] != NULL ){
        return searchTrie(root->children[childInd], newWord);
    }
    // if not, then the trie does not contain the word
    else{
        return false;
    }
}


// search in Trie
void deleteTrie( trieNode *&root, string word){
    // base case 
    if( word.length() == 0 ){
        // mark the terminal as false
        root->isTerminal = false;
        return;
    }

    int childInd = word[0] - 'a';
    char ch = word[0];
    string newWord = word.substr(1);

    // check if the child of root contains the character or not
    // if yes, move to it child 
    if( root->children[childInd] != NULL ){
        deleteTrie( root->children[childInd], newWord );
    }
    // if not, then the trie does have the word just return 
    else{
        return;
    }
}



int main(){

    trieNode* root = new trieNode('$');

    insertTrie(root,"amit");
    insertTrie(root,"jiksss");
    insertTrie(root,"jitendriya");

    cout<<endl;

    if( searchTrie(root,"amit")){
        cout<<" amit is present in the trie"<<endl;
    }else{
        cout<<" amit is not present in the trie"<<endl;
    }

    if( searchTrie(root,"jiksss")){
        cout<<" jiksss is present in the trie"<<endl;
    }else{
        cout<<" jiksss is not present in the trie"<<endl;
    }

    if( searchTrie(root,"jiten")){
        cout<<" jiten is present in the trie"<<endl;
    }else{
        cout<<" jiten is not present in the trie"<<endl;
    }

    cout<<endl<<" deleting amit"<<endl;

    deleteTrie( root,"amit");
    if( searchTrie(root,"amit")){
        cout<<" amit is present in the trie"<<endl;
    }else{
        cout<<" amit is not present in the trie"<<endl;
    }

    
    return 0;
}