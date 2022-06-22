#include<bits/stdc++.h>

using namespace std;

// Problem Link : https://www.codingninjas.com/codestudio/problems/word-break-1_758963?leftPanelTab=0
// Learning Resource : https://www.techiedelight.com/word-break-problem/

// TC : O(2^N) , where N is the of word in our dictionary
// SC : O(N*N)

void getAllWordBreakSentances(string& s, string resultSantance, vector<string> &dictionary, vector<string>& result){
    if(0 == s.size()) {
        result.push_back(resultSantance);
        return;
    }
    
    for(int i=0; i<s.size(); i++){
        string prefix = s.substr(0, i+1);
        string sufix = s.substr(i+1);
        if(find(dictionary.begin(), dictionary.end(), prefix) != dictionary.end()) {
            getAllWordBreakSentances(sufix, resultSantance + prefix + " ", dictionary, result);
        }
    }
    return;
}

vector<string> getAllValidSentences(string &sentence, vector<string> &dictionary)
{
    vector<string> result;
    getAllWordBreakSentances(sentence, "", dictionary, result);
    return result;
}