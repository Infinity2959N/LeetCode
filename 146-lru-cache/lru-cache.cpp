class LRUCache {
    struct Node{
        int key, value;
        Node *prev, *next;
        Node(int k, int v): key(k), value(v), prev(nullptr), next(nullptr) {}
    };
    int cap;
    unordered_map<int, Node*> map;
    Node *head= new Node(-1, -1), *tail= new Node(-1, -1);  // dummy head and dummy tail
public:
    LRUCache(int capacity) {
        cap= capacity;
        head->next= tail;
        tail->prev= head;
    }

    void addNode(Node* newNode){
        Node* temp= head->next;
        newNode->next= temp;
        newNode->prev= head;
        head->next= newNode;
        temp->prev= newNode;
    }

    void deleteNode(Node* delNode){
        Node* prevNode= delNode->prev;
        Node* nextNode= delNode->next;
        prevNode->next= nextNode;
        nextNode->prev= prevNode;
    }
    
    int get(int key) {
        if(map.count(key)){
            Node* resNode= map[key];
            int res= resNode-> value;
            map.erase(key);
            deleteNode(resNode);
            addNode(resNode);
            map[key]= head->next;
            return res;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(map.count(key)){
            Node* existingNode= map[key];
            map.erase(key);
            deleteNode(existingNode);
        }if(map.size()==cap){
            map.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(new Node(key, value));
        map[key]= head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */