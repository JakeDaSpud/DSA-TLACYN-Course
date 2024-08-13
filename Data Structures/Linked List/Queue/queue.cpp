// Node-Based Data Structure
// An implementation of a Linked-List
// Lesson: "Implementing a Queue"
// If you have a constant reference to the head and tail, enqueue() and deque() are O(1)

#include <stdexcept>

template <typename T> class Node {
public:
    T value;
    Node<T> *next;

public:
    Node(T value) : value(value), next(nullptr) {}
};

template <typename T> class Queue {
private:
    Node<T> *head;
    Node<T> *tail;

public:
    int length;

public:
    Queue() {
        this->head = this->tail = nullptr;
        this->length = 0;
    }

    void enqueue(T item) {
        Node<T> *new_node = new Node<T>(item);

        this->length++;

        // Didn't have any Nodes
        if (this->tail == nullptr) {
            this->tail = this->head = new_node;
            return;
        }

        this->tail->next = new_node;
        this->tail = new_node;
    }

    T deque() {
        // Doesn't have Nodes
        if (this->head == nullptr) {
            throw std::out_of_range("Queue is empty");
        }

        this->length--;

        // Setting new links of Nodes
        // Save old head
        Node<T> *old_head = this->head;
        // Set new head
        this->head = this->head->next;

        T old_head_value = old_head->value;

        // Free up the memory of that dequeued Node
        delete old_head;

        return old_head_value;
    }

    T peek() {
        if (this->head != nullptr) {
            return this->head->value;
        }

        throw std::out_of_range("Queue is empty");
    }
};

int main(int argc, char const *argv[])
{
    return 0;
}
