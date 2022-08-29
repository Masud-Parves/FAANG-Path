class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string result = "";
        for(auto& word : strs){
            result += to_string(word.size()) + "#" + word;
        }
        return result;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> words;
        int i=0;
        while(i<s.size()){
            int j=i;
            string nums = "";
            while(s[j]!='#'){
                nums += s[j];
                j++;
            }
            
            int word_len = stoi(nums);
            string word = s.substr(j+1, word_len);
            words.push_back(word);
            i = j+1+word_len;
        }
        return words;
    }
};