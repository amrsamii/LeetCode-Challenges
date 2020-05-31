class Trie {
    Trie *children[26];
    bool isLeaf;
public:
    /** Initialize your data structure here. */
    Trie() {
        for(int i=0;i<26;i++)
            children[i] = nullptr;
        
        isLeaf = false;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {  
	// since user will only instantiate one object from this class and insert and search in it, we can consider
	// this object as our root node of the Trie  
        Trie *current = this;
        
        for(int i = 0,sz = word.length(); i<sz; i++) {
            int idx = word[i] - 'a';
            if(current -> children[idx] == nullptr){
                current -> children[idx] = new Trie();
            }
            
            current = current -> children[idx];
        }
        current -> isLeaf = true;     
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {        
        Trie *current = this;
        
        for(int i = 0; i < word.length() ; i++) {
            int idx = word[i] - 'a';
            if(current -> children[idx] == nullptr)
                return false;
            
            current = current -> children[idx];
        }
        
        return current -> isLeaf;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {        
        Trie *current = this;
        
        for(int i = 0; i < prefix.length() ; i++) {
            int idx = prefix[i] - 'a';
            if(current -> children[idx] == nullptr)
                return false;
            
            current = current -> children[idx];
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