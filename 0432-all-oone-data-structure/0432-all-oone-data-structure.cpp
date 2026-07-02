class AllOne {
private:
    struct Node {
        int freq;
        unordered_set<string> keys;
        Node *prev, *next;

        Node(int f) {
            freq = f;
            prev = next = nullptr;
        }
    };

    Node *head;
    Node *tail;

    unordered_map<string, Node*> mp;

    void removeNode(Node *node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        delete node;
    }

    Node* insertAfter(Node *prevNode, int freq) {
        Node *newNode = new Node(freq);

        newNode->next = prevNode->next;
        newNode->prev = prevNode;

        prevNode->next->prev = newNode;
        prevNode->next = newNode;

        return newNode;
    }

public:
    AllOne() {
        head = new Node(-1);
        tail = new Node(-1);

        head->next = tail;
        tail->prev = head;
    }

    void inc(string key) {

        if(mp.count(key)) {

            Node *curr = mp[key];
            curr->keys.erase(key);

            Node *nextNode;

            if(curr->next != tail && curr->next->freq == curr->freq + 1)
                nextNode = curr->next;
            else
                nextNode = insertAfter(curr, curr->freq + 1);

            nextNode->keys.insert(key);
            mp[key] = nextNode;

            if(curr->keys.empty())
                removeNode(curr);

        } else {

            Node *first;

            if(head->next != tail && head->next->freq == 1)
                first = head->next;
            else
                first = insertAfter(head,1);

            first->keys.insert(key);
            mp[key] = first;
        }
    }

    void dec(string key) {

        Node *curr = mp[key];

        curr->keys.erase(key);

        if(curr->freq == 1) {

            mp.erase(key);

        } else {

            Node *prevNode;

            if(curr->prev != head && curr->prev->freq == curr->freq - 1)
                prevNode = curr->prev;
            else
                prevNode = insertAfter(curr->prev,curr->freq-1);

            prevNode->keys.insert(key);
            mp[key] = prevNode;
        }

        if(curr->keys.empty())
            removeNode(curr);
    }

    string getMaxKey() {

        if(tail->prev == head)
            return "";

        return *(tail->prev->keys.begin());
    }

    string getMinKey() {

        if(head->next == tail)
            return "";

        return *(head->next->keys.begin());
    }
};