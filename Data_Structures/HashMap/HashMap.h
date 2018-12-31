#ifndef HASH_MAP_H
#define HASH_MAP_H
#include <iostream>

// Default Hash function
template <class K, int table_size>
struct KeyHash {
    unsigned int operator()(const K& key) {
        return static_cast<unsigned int>(key) % table_size;
    }
};

// Partial Specialization for string keys
template <int table_size>
struct KeyHash<std::string, table_size> {
    unsigned int operator()(const std::string& key) {
        long sum = 0;
        for(int i = 0; i < key.length(); i++) {
            sum += key[i];
        }
        return sum % table_size;
    }
};

template <class K, class V>
struct HashNode {
    HashNode(K key, V value, HashNode<K, V> *next) 
    : key(key), value(value), next(next) {}
    K key;
    V value;
    HashNode<K, V> *next;
};

template <class K, class V, int table_size = 20, class F = KeyHash<K, table_size>>
class HashMap {
    private:
        HashNode<K, V> *bucket[table_size]; // Array of HashNode pointers
        F hashFunc;

    public:
        HashMap();
        V get(K);
        void put(K, V);
        bool find(const K&);
        bool remove(const K&);
};

template <class K, class V, int table_size, class F>
HashMap<K, V, table_size, F>::HashMap() {
    for(int i = 0; i < table_size; ++i) {
        bucket[i] = NULL;
    }
}

template <class K, class V, int table_size, class F>
V HashMap<K, V, table_size, F>::get(K key) {
    unsigned int hashIndex = hashFunc(key);
    HashNode<K, V> *entry = bucket[hashIndex];
    
    while(entry != NULL && entry->key != key) {
        entry = entry->next;
    }
    if (entry == NULL)
        return V();
    else {
        return entry->value;
    }
}

template <class K, class V, int table_size, class F>
void HashMap<K, V, table_size, F>::put(K key, V value) {
    unsigned int hashIndex = hashFunc(key);
    HashNode<K, V> *entry = bucket[hashIndex];
    
    HashNode<K, V> *prev = NULL;
    while(entry != NULL && entry->key != key) {
        prev = entry;
        entry = entry->next;
    }
    if(entry == NULL) {
        entry = new HashNode<K, V>(key, value, NULL);
        if(prev == NULL) {
            // Bucket at this index is empty
            bucket[hashIndex] = entry;    
        } else {
            // Chain to previous HashNode
            entry->next = entry;
        }
    } else {
        // Key already exists, update value
        entry->value = value;
        bucket[hashIndex] = entry;
    }
}

template <class K, class V, int table_size, class F>
bool HashMap<K, V, table_size, F>::find(const K& key) {
    unsigned int hashIndex = hashFunc(key);
    HashNode<K, V> *entry = bucket[hashIndex];
    
    while(entry != NULL && entry->key != key) {
        entry = entry->next;
    }
    if (entry == NULL)
        return false;
    else {
        return true;
    }
}

template <class K, class V, int table_size, class F>
bool HashMap<K, V, table_size, F>::remove(const K& key) {
    unsigned int hashIndex = hashFunc(key);
    HashNode<K, V> *entry = bucket[hashIndex];
    
    HashNode<K, V> *prev = NULL;
    while(entry != NULL && entry->key != key) {
        prev = entry;
        entry = entry->next;
    }
    if (entry == NULL)
        return false;
    else {
        if(prev == NULL) {
            delete entry;
            bucket[hashIndex] = NULL; 
        } else {
            prev->next = entry->next;
            delete entry;
            entry = NULL;
        }
        return true;
    }
}

#endif //HASH_MAP_H