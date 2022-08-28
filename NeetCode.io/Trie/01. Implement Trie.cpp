class TrieNode{
public:
    TrieNode* next[26];
    bool endMark;    
    TrieNode(){
        for(int i=0; i<26; i++){
            next[i] = NULL;
        }
        endMark = false;
    }
};

class Trie {
public:
    TrieNode *root;
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        int len = word.size();
        TrieNode* current = root;

        for(int i=0; i<len ; i++){
            int id = word[i]-'a';
            if(current->next[id] == NULL){
                current->next[id] = new TrieNode();
            }
            current = current->next[id];
        }
        current->endMark = true;
    }
    
    bool search(string word) {
        int len = word.size();
        TrieNode* current = root;

        for(int i=0; i<len ; i++){
            int id = word[i]-'a';
            if(current->next[id] == NULL){
                return false;
            }
            current = current->next[id];
        }
        return current->endMark;
    }
    
    bool startsWith(string prefix) {
        int len = prefix.size();
        TrieNode* current = root;
        
        for(int i=0; i<len ; i++){
            int id = prefix[i]-'a';
            if(current->next[id] == NULL){
                return false;
            }
            current = current->next[id];
        }
        return true;
    }
};
