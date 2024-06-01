#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template<typename T>
class LinkedList {
private:
    struct Node {
        T data;
        Node* next;
        Node(T data) : data(data), next(nullptr) {}
    };
    Node* head;
    Node* tail;

public:
    LinkedList() : head(nullptr), tail(nullptr) {}

    ~LinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void add(T data) {
        Node* newNode = new Node(data);
        if (!tail) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    bool remove(T data) {
        Node* current = head;
        Node* previous = nullptr;
        while (current) {
            if (current->data == data) {
                if (!previous) {
                    head = current->next;
                } else {
                    previous->next = current->next;
                }
                if (current == tail) {
                    tail = previous;
                }
                delete current;
                return true;
            }
            previous = current;
            current = current->next;
        }
        return false;
    }

    bool find(T data) const {
        Node* current = head;
        while (current) {
            if (current->data == data) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    Node* getHead() const {
        return head;
    }
};

#endif // LINKEDLIST_H
