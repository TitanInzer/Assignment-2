#include <iostream>

template<typename Item_Type>
class Single_Linked_List {
private:
    struct Node {           /* Makes the Node Structure used in the Linked List ADT */
        Item_Type data;
        Node* next;  /* Pointer to Next Node */
        Node(const Item_Type& data_item, Node* next_ptr = nullptr) :
            data(data_item), next(next_ptr) {}
    };
    Node* head;   /* Pointer to the Head */
    Node* tail;   /* Pointer to the Tail */
    size_t num_items;  /* Size of List */

public:
    Single_Linked_List() : head(nullptr), tail(nullptr), num_items(0) {}  /* Makes a List of Size 0 */

    ~Single_Linked_List() {
        while (!empty()) {
            pop_front();
        }
    }

    void push_front(const Item_Type& item) {    /* Push Front Member Function */
        Node* new_node = new Node(item, head); 
        if (empty()) {
            tail = new_node;     /* Checks if the List is empty and if it is make the new Node the Tail */
        }
        head = new_node;  /* Makes the New Node the Head */
        ++num_items;  /* Increases the size of the List by One */
    }

    void push_back(const Item_Type& item) {      /* Push Back Member Function */
        Node* new_node = new Node(item);
        if (empty()) {    
            head = new_node;       /* Checks if the List is empty and if it is make the new Node the Head */
        }
        else {
            tail->next = new_node;   /* Otherwise Tail.Nest is the New Node*/
        }
        tail = new_node;    /* Makes the New Node the Tail */
        ++num_items;   /* Increases the size of the List by One */
    }

    void pop_front() {      /* Ppo Front Member Function */
        if (!empty()) {          /* Checks if the List is not Empty */
            Node* old_head = head;  
            head = head->next;   /* Makes the head equal to head.next */
            delete old_head;    /* Deletes the Original head*/
            --num_items;     /* Decreases the List size by One */
            if (empty()) {
                tail = nullptr;   /* If the list is Empty then tail points to nothing */
            } 
        }
    }

    void pop_back() {       /* Pop Back Member Function */
        if (!empty()) {      /* Checks if the List is not Empty */
            if (head == tail) {
                delete tail;    /* If the Head and the Tail are the same delete the tail, and have head and tail point to nothing */
                head = nullptr;
                tail = nullptr;
                --num_items;  /* Decreases the size of the List by One */
            }
            else {
                Node* temp = head;   /* Make a Temp Node equal to Head */
                while (temp->next != tail) {   /* Loop the makes temp equal to temp.next */
                    temp = temp->next;
                }
                delete tail;   /* Delete the Tail */
                tail = temp;  /* New Tail is the temp node */
                tail->next = nullptr; /* Tail.next points to nothing */
                --num_items; /* Decreases the size of the List by One */
            }
        }
    }

    Item_Type front() const {  /* Member Function that Returns the Front of the List */
        if (!empty()) {   /* If not Empty Return the data of the head of the List */
            return head->data;
        }
        return Item_Type{};
    }

    Item_Type back() const {    /* Member Function that Returns the Back of the List */
        if (!empty()) {     /* If not Empty Return the data of the tail of the List */
            return tail->data;
        }
        return Item_Type{};
    }

    bool empty() const {    /* Member Function that Checks if the list is Empty */
        return num_items == 0;
    }

    void insert(size_t index, const Item_Type& item) {  /* Member Function that Allows for Insertion into the middle of the List */
        if (index <= 0) {   /* If the Index is at the Front them do push front */
            push_front(item);
        }
        else if (index >= num_items) {  /* If the Index is at the Back of the List do push back */
            push_back(item);
        }
        else {
            Node* temp = head;
            for (size_t i = 0; i < index - 1; ++i) {   /* Iterates Through the List Changing where the temp node is pointing */
                temp = temp->next;
            }
            Node* new_node = new Node(item, temp->next); /* Makes a New Node that is temp.next */
            temp->next = new_node;
            ++num_items;  /* Increase the Size of the List by One */
        }
    }

    Item_Type operator[](size_t index) const { /* Allows Use to Look At Data in a Given Index */
        if (index >= num_items) {
            return Item_Type{};
        }
        Node* temp = head;
        for (size_t i = 0; i < index; ++i) {
            temp = temp->next;
        }
        return temp->data;
    }



    bool remove(size_t index) {  /* Member Function for Removing an Item From the List */
        if (index >= num_items) {   /* Checks if Item is within Bounds of the List */
            return false;
        }
        if (index == 0) {   /* If at the Front the Pop Front */
            pop_front();
        }
        else {
            Node* temp = head;
            for (size_t i = 0; i < index - 1; ++i) {  /* Iterates Through the List */
                temp = temp->next;
            }
            Node* old_node = temp->next;   /* Rereferences the Pointers to account for the removed Node*/
            temp->next = old_node->next;
            if (old_node == tail) {
                tail = temp;
            }
            delete old_node;   /* Deletes the Old Node */
            --num_items;  /* Decreases the Size of the List by One */
        }
        return true;
    }
    size_t find(const Item_Type& item) const {   /* Member Function to Find the First Occurence of an Item in the List */
        Node* temp = head;
        size_t index = 0; /* Start at the Index 0 */
        while (temp != nullptr) {   /* Iterate until the .next pointer is null*/
            if (temp->data == item) { /* If found Return the Index */
                return index;
            }
            temp = temp->next; /* If Not Found at Current Point Move Forward One */
            ++index;
        }
        return num_items;
    }
};
