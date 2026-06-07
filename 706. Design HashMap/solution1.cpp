class MyHashMap {
public:
    int M;
    vector<int> maps;
    MyHashMap() {
        M = 1e6+1;
        maps.resize(M);
        fill(begin(maps), end(maps), -1);
    }
    
    void put(int key, int value) {
        maps[key] = value;
    }
    
    int get(int key) {
        return maps[key];   
    }
    
    void remove(int key) {
        maps[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */