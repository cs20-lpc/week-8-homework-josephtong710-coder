template <typename T>
LinkedListStack<T>::LinkedListStack()
{ }

template <typename T>
LinkedListStack<T>::LinkedListStack(const LinkedListStack<T>& copyObj) {
    copy(copyObj);
}

template <typename T>
LinkedListStack<T>& LinkedListStack<T>::operator=(const LinkedListStack<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
LinkedListStack<T>::~LinkedListStack() {
    clear();
}

template <typename T>
void LinkedListStack<T>::clear() {
    // TO DO: Delete all the elements in the stack
    while(!isEmpty()) {
        pop();
    }
}

template <typename T>
void LinkedListStack<T>::copy(const LinkedListStack<T>& copyObj) {
    // TO DO: Implement copy 
    if(copyObj.isEmpty()) {
        top = nullptr;
    }
    else {
        // Copy the first node
        top = new Node<T>(copyObj.top->data);
        Node<T> *currCopy = copyObj.top->next;
        Node<T> *currThis = top;

        // Copy the rest of the nodes
        while (currCopy != nullptr) {
            currThis->next = new Node<T>(currCopy->data);
            currThis = currThis->next;
            currCopy = currCopy->next;
        }
    }
    
}

template <typename T>
int LinkedListStack<T>::getLength() const {
    return this->length;
}


template <typename T>
bool LinkedListStack<T>::isEmpty() const {
    return this->length == 0;
}

template <typename T>
T LinkedListStack<T>::peek() const {
    // TO DO: implement peek
    if (isEmpty()) {
        throw std::runtime_error("Stack is empty. Cannot peek.");
    }
    return top->data;
}

template <typename T>
void LinkedListStack<T>::pop() {
    // TO DO: Implement pop
    if (isEmpty()) {
        throw std::runtime_error("Stack is empty. Cannot pop.");
    }
    Node<T> *temp = top;
    top = top->next;
    delete temp;
    this->length--;
}

template <typename T>
void LinkedListStack<T>::push(const T& elem) {
    // TO DO: Implement push
    Node<T> *newNode = new Node<T>(elem);
    newNode->next = top;
    top = newNode;
    this->length++;
}

template <typename T>
void LinkedListStack<T>::rotate(typename Stack<T>::Direction dir) {
    // TO DO: Implement rotate
    if (isEmpty()) {
        throw std::runtime_error("Stack is empty. Cannot rotate.");
    }
    if (dir == Stack<T>::RIGHT) {
        // Rotate right: Move the top element to the bottom
        Node<T> *oldTop = top;
        top = top->next; // Move top down
        oldTop->next = nullptr; // Old top will be new bottom

        if (top == nullptr) {
            // If stack had only one element, it becomes the new top
            top = oldTop;
        } else {
            // Find the current bottom and attach old top there
            Node<T> *curr = top;
            while (curr->next != nullptr) {
                curr = curr->next;
            }
            curr->next = oldTop; // Attach old top to the bottom
        }
    } else if (dir == Stack<T>::LEFT) {
        // Rotate left: Move the bottom element to the top
        if (top->next == nullptr) {
            // If stack has only one element, no rotation needed
            return;
        }
        
        Node<T> *prev = nullptr;
        Node<T> *curr = top;

        // Traverse to the last node
        while (curr->next != nullptr) {
            prev = curr;
            curr = curr->next;
        }
        prev->next = nullptr; // Detach last node
        curr->next = top; // Move last node to the front
        top = curr; // Update top to new node
    }
}

template <typename T>
void LinkedListStack<T>::print() {
    cout << "LinkedListStack contents: ";
    if (isEmpty()) {
        cout << "Stack is empty, no elements to display.\n";
    }
    else {
        Node<T> *curr = top;
        while (curr != nullptr){
            cout <<  curr->data  << "\t";
            curr = curr->next;
        }
    }

    cout << endl;
}
