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

class WordDictionary {
private:
        TrieNode* root;
public:
	void insertIntoTrie(string& word, TrieNode* root){
        int len = word.size();
        TrieNode* current = root;
        
        for(int i=0; i<len ; i++){
            int id = word[i] - 'a';
            if(current->next[id] == NULL){
                current->next[id] = new TrieNode();
            }
            current = current->next[id];
        }
        current->endMark = true;
        return;
    }

    bool searchFromTrie(string& word, int idx, TrieNode* current){
        if(current == NULL) return false;
        if(word[idx] == '\0') return current && current->endMark;
        
        if(word[idx] == '.'){
            for(int i=0; i<26; i++){
                if(searchFromTrie(word, idx+1, current->next[i])) {
                    return true;
                }
            }
            return false;
        } else {
            int id = word[idx] -'a';
            return searchFromTrie(word, idx+1, current->next[id]);
        }
        return false;
    }

    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(string word) {
        insertIntoTrie(word, root);
    }
    
    bool search(string word) {
        return searchFromTrie(word, 0, root);
    }
};
