class Trie {
public:
   class Node {
   public:
   unordered_map<char,Node*>mp;
   bool isEnd = false;
   };

   Node * root = new Node();

    Trie() {
       // Node * root;
    }
    
    void insert(string word) {
        Node * curr  = root;
        for(int i=0; i<word.size(); i++){
            if(curr->mp[word[i]]==NULL){
                curr->mp[word[i]] = new Node();
            }
            curr = curr->mp[word[i]];
        }
        curr->isEnd=true;
    }
    
    bool search(string word) {
        Node * curr = root;
         for(int i=0; i<word.size(); i++){
            if(curr->mp[word[i]]==NULL){
                return false;
            }
            curr = curr->mp[word[i]];
        }
        return curr->isEnd; 
    }
    
    bool startsWith(string prefix) {
        Node * curr = root;
         for(int i=0; i<prefix.size(); i++){
            if(curr->mp[prefix[i]]==NULL){
                return false;
            }
            curr = curr->mp[prefix[i]];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */