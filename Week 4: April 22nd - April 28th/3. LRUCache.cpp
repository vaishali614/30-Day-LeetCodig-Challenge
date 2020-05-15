// Method 1: Using HashMap - Time Complexity : O(capacity), Space Complexity : O(events) - Poor
class LRUCache {
    unordered_map<int, int> m1;
    unordered_map<int, int> m2;
    queue<int> q;
    int capacity;
    void addToQueue(int key){
        q.push(key);
        m2[key]++;
    }
public:
    LRUCache(int givenCapacity) {
        capacity = givenCapacity;
    }
    
    int get(int key) {
        auto it = m1.find(key);
        if(it == m1.end())
            return -1;
        addToQueue(key);
        return it->second;
    }
    
    void put(int key, int value) {
        if((int) m1.size() < capacity){
            m1[key] = value;
            addToQueue(key);
            return;
        }
        auto it = m1.find(key);
        if(it != m1.end()){
            it->second = value;
            addToQueue(key);
            return;
        }
        while(true){
            int curr = q.front();
            q.pop();
            if(--m2[curr] == 0){
                m1.erase(curr);
                m2.erase(curr);
                break;
            }
        }
        m1[key] = value;
        addToQueue(key);
    }
};



// Method 2: Using List
/* class LRUCache {
public:
    list<pair<int,int>> l;
    unordered_map<int,list<pair<int,int>>::iterator> m;
    int capacity;
    LRUCache(int capacity):capacity(capacity) {
        
    }
    
    int get(int key) {
        auto it=m.find(key);
        if (it==m.end()) return -1;
        l.splice(l.begin(),l,it->second);
        return it->second->second;
    }
    
    void put(int key, int value) {
        auto it=m.find(key);
        if (it==m.end()){
            if (m.size()==capacity){
                m.erase(l.back().first);
                l.pop_back();
            }
            l.push_front({key,value});
            m[key]=l.begin();
        }else{
            l.splice(l.begin(),l,it->second);
            it->second->second=value;
        }
    }
}*/


/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
