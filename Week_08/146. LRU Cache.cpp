class LRUCache {
private:
    int cap;
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>>::iterator> um;
public:
    LRUCache(int capacity) : cap(capacity) {}

    int get(int key) {
        if (um.find(key) == um.end()) return -1;
        auto key_value = *um[key];      // 获取节点指针
        cache.erase(um[key]);           // 挂链删除某个节点
        cache.emplace_front(key_value); // 将节点放到链表的头部
        um[key] = cache.begin();        // 哈希表更新节点地址信息
        return key_value.second;
    }

    void put(int key, int value) {
        // 如果有新元素加入，且内存已经满了，则删除链表的最后一个元素
        if (um.find(key) == um.end()) {
            if (cache.size() == cap) {
                um.erase(cache.back().first);
                cache.pop_back();
            }
        } else {
            cache.erase(um[key]);   // 删除链表中具有相同key的节点
        }
        cache.emplace_front(make_pair(key, value));
        um[key] = cache.begin();
    }
};
