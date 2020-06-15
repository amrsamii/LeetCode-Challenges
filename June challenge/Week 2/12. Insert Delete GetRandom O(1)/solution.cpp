class RandomizedSet {
public:
    unordered_map<int,int> hashMap;
    vector<int> numbers;
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(hashMap.find(val) != hashMap.end())
            return false;
        
        numbers.push_back(val);
        hashMap[val] = numbers.size() - 1;
        
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(hashMap.find(val) == hashMap.end())
            return false;
        
        int valIdx = hashMap[val];
        
        swap(numbers[valIdx], numbers[numbers.size() - 1]);
        
        numbers.pop_back();
        hashMap[numbers[valIdx]] = valIdx;
        hashMap.erase(val);
        
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int randomNumber = rand() % numbers.size();
        return numbers[randomNumber];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
