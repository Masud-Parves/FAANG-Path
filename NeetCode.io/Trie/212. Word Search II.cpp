class Solution {
private:
    int fx[4]= {1,-1,0,0};
    int fy[4]= {0,0,1,-1};
public:
    class TrieNode{
    public:
        TrieNode* next[26];
        string word;
        
        TrieNode(){
            for(int i=0; i<26 ; i++){
                next[i] = NULL;
            }
            word = "";
        }
    };
    
    TrieNode* generateTrie(vector<string>& words){
        TrieNode* root = new TrieNode();
        for(auto& word : words){
            TrieNode* curr = root;
            
            for(auto& c : word){
                if(curr->next[c-'a'] == NULL){
                    curr->next[c-'a'] = new TrieNode();
                }
                curr = curr->next[c-'a'];
            }
            
            curr->word = word;
        }
        return root;
    }

    void dfs(int r, int c, TrieNode* currNode, vector<vector<char>>& board, vector<string>& aceWords){
        char ch = board[r][c];
        
        if(ch == '#' || (currNode && currNode->next[ch-'a'] == NULL)) return;
        
        currNode = currNode->next[ch-'a'];
        
        if(currNode && currNode->word.size() > 0){
            aceWords.push_back(currNode->word);
            currNode->word.clear();
        }
        board[r][c] = '#';
        for(int i= 0 ; i<4 ; i++){
            int nr = r+fx[i];
            int nc = c+fy[i];
            if(nr<0 || nc<0 || nr>=board.size() || nc>=board[0].size() || board[nr][nc] == '#') continue;
            
            dfs(nr, nc, currNode, board, aceWords);
        }
        board[r][c] = ch;
        
    }
    void display(TrieNode* currNode){
        if(currNode->word.size() > 0){
            cout << currNode->word << endl;
        }
        
        for(int i=0; i<26; i++){
            if(currNode->next[i] == NULL) continue;
            display(currNode->next[i]);
        }
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = generateTrie(words);
        
        //display(root); call for debug
        
        int n = board.size();
        int m = board[0].size();
        
        vector<string> aceWords;
        
        for(int r = 0; r<n ; r++){
            for(int c = 0; c<m ; c++){
                dfs(r, c, root, board, aceWords);
            }
        }
        return aceWords;
    }
};