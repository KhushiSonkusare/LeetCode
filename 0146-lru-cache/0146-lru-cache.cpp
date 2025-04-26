#include <unordered_map>
#include <list>
using namespace std;

class LRUCache {
private:
    int capacity;
    list<int> lruList; 
    unordered_map<int, pair<int, list<int>::iterator>> cache; 

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (cache.find(key) == cache.end()) {
            return -1; 
        }
        lruList.erase(cache[key].second);
        lruList.push_back(key);
        cache[key].second = --lruList.end(); 
        return cache[key].first;
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            lruList.erase(cache[key].second);
            lruList.push_back(key);
            cache[key] = {value, --lruList.end()};
        } else {
            if (cache.size() == capacity) {
                int lruKey = lruList.front();
                lruList.pop_front();
                cache.erase(lruKey);
            }
            lruList.push_back(key);
            cache[key] = {value, --lruList.end()};
        }
    }
};
