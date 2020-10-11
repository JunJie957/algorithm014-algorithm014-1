class LRUCache {
private:
    int cap;
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>>::iterator> um;
public:
    LRUCache(int capacity) : cap(capacity) {}

    int get(int key) {
        if (um.find(key) == um.end()) return -1;
        auto key_value = *um[key];      // ��ȡ�ڵ�ָ��
        cache.erase(um[key]);           // ����ɾ��ĳ���ڵ�
        cache.emplace_front(key_value); // ���ڵ�ŵ������ͷ��
        um[key] = cache.begin();        // ��ϣ����½ڵ��ַ��Ϣ
        return key_value.second;
    }

    void put(int key, int value) {
        // �������Ԫ�ؼ��룬���ڴ��Ѿ����ˣ���ɾ����������һ��Ԫ��
        if (um.find(key) == um.end()) {
            if (cache.size() == cap) {
                um.erase(cache.back().first);
                cache.pop_back();
            }
        } else {
            cache.erase(um[key]);   // ɾ�������о�����ͬkey�Ľڵ�
        }
        cache.emplace_front(make_pair(key, value));
        um[key] = cache.begin();
    }
};
