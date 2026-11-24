#include <iostream>
#include<vector>

using namespace std;

struct TrieNode {
    TrieNode* BOX[26];  // 26 slots for each letter of the alphabet
    bool isEndOfWord;  // Marks the end of a word
};

TrieNode* createNode() {
    TrieNode* node = new TrieNode;
    node->isEndOfWord = false;
    for (int i = 0; i < 26; ++i) {
        node->BOX[i] = NULL;    // Initialize all letters to null
    }
    return node;
}

void insert(TrieNode* root, string word) {
    TrieNode* current = root;

    // BOX[] only has slots for the letters a to z
    for (int i=0;i<word.size();i++) {
        if (word[i] < 'a' || word[i] > 'z') {
            cout<<"Skipped "<<word<<": only the letters a-z are supported"<<endl;
            return;
        }
    }

    for (int i=0;i<word.size();i++) {
        int index = word[i] - 'a';    // Convert letter to a number (0 to 25)
        if (current->BOX[index] == NULL) {
            current->BOX[index] = createNode();  //if not exist, create
        }
        current = current->BOX[index]; //traverse
    }
    current->isEndOfWord = true;   //word end true
}

bool isfound(string words,TrieNode *root){
    TrieNode *current = root;
    for(int i=0;i<words.size();i++){
        int index = words[i] - 'a';
        if(index < 0 || index >= 26){
            return false;   // not a letter a-z, so it cannot be in the trie
        }
        if(current->BOX[index] == NULL){
            return false;
        }
        current = current->BOX[index];
    }
    if(current->isEndOfWord == true){
        return true;  
    }
    else {
        return false;
    }
}
bool found(TrieNode *root){
    TrieNode *current = root;
    while(current->isEndOfWord!=true){
    
    int index = -1;
    
    for(int i=0;i<26;i++){
        if(current->BOX[i]!=NULL && index!=-1){
              return false;
        }
        if(current->BOX[i]!=NULL){
            index = i;
        }
      }
     if(index == -1){
         return false;   // this node has no children: there is nothing to follow
     }
     cout<<char(index+97);
     current = current->BOX[index];
    }
    return 0;

}
int main() {
    TrieNode* root = createNode();
    
    int x;
    string words;

    cout<<"how many words are there?"<<endl;
    cin>>x;
    
    cout<<"Enter the words"<<endl;
    while(x-- > 0){
        cin>>words;
        insert(root, words);
    }

    found(root);
    
    return 0;
}
