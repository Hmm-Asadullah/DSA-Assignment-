//#include <iostream>
//#include <chrono>
//#include <string>
//using namespace std;
//using namespace chrono;
//// Template Node structure representing a single node in a singly linked list.
//template<typename T>
//struct Node
//{
//    T data;           // The value stored in the node.
//    Node* next;       // Pointer to the next node in the list.
//    // Constructor: Initializes the Node.
//    Node(T d, Node<T>* n = nullptr)
//    {
//        data = d;
//        next = n;
//    }
//};
//// Template class for a Singly Linked List (SLList).
//template<typename T>
//class SLList
//{
//    Node<T>* head;   // Pointer to the head of the linked list.
//    Node<T>* tail;   // Pointer to the tail of the linked list.
//public:
//    // Constructor: Initializes an empty list.
//    SLList()
//    {
//        head = nullptr;
//        tail = nullptr;
//    }
//    // Destructor: Deallocates all nodes in the list.
//    ~SLList()
//    {
//        while (head)
//        {
//            Node<T>* temp = head;
//            head = head->next;
//            delete temp;
//        }
//        head = tail = nullptr;
//    }
//    // Checks if the list is empty.
//    bool isEmpty()
//    {
//        return (head == nullptr && tail == nullptr) ? true : false;
//    }
//    // Adds a new element to the head of the list.
//    void addToHead(T e)
//    {
//        head = new Node<T>(e, head);
//        if (tail == nullptr)
//        {
//            tail = head;
//        }
//    }
//    // Adds a new element to the tail of the list.
//    void addToTail(T e)
//    {
//        if (tail != nullptr)
//        {
//            tail->next = new Node<T>(e);
//            tail = tail->next;
//        }
//        else
//        {
//            tail = head = new Node<T>(e);
//        }
//    }
//    // Returns the tail node of the list.
//    Node<T>* getTail()
//    {
//        return tail;
//    }
//    // Returns the head node of the list.
//    Node<T>* getHead()
//    {
//        return head;
//    }
//    // Removes and returns the element at the head of the list.
//    T deleteFromHead()
//    {
//        if (!isEmpty())
//        {
//            T element = head->data;
//            if (head == tail)
//            {
//                delete head;
//                head = tail = nullptr;
//                return element;
//            }
//            Node<T>* temp = head;
//            head = head->next;
//            delete temp;
//            return element;
//        }
//        throw "\nList is empty";
//    }
//    // Removes and returns the element at the tail of the list.
//    T deleteFromTail()
//    {
//        if (!isEmpty())
//        {
//            T element = tail->data;
//            if (head == tail)
//            {
//                delete tail;
//                tail = head = nullptr;
//                return element;
//            }
//            Node<T>* temp = head;
//            while (temp->next != tail)
//            {
//                temp = temp->next;
//            }
//            delete tail;
//            tail = temp;
//            tail->next = nullptr;
//            return element;
//        }
//        throw "\nList is Empty";
//    }
//    // Prints all elements in the list.
//    void printList()
//    {
//        if (!isEmpty())
//        {
//            cout << '\n';
//            Node<T>* iter = head;
//            while (iter)
//            {
//                cout << iter->data << ' ';
//                iter = iter->next;
//            }
//        }
//        else
//        {
//            throw "\nElement not found";
//        }
//    }
//};
//// Template class for Binary Search in an array or linked list.
//template<typename T>
//class BinarySearch
//{
//public:
//    // Binary search on a sorted array. Returns true if the key is found, false otherwise.
//    bool searchArray(T array[], int size, T key)
//    {
//        if (size <= 0)
//        {
//            return false;
//        }
//        int start = 0;
//        int end = size - 1;
//        while (start <= end)
//        {
//            int mid = (start + end) / 2;
//            if (array[mid] == key)
//            {
//                return true;
//            }
//            else if (array[mid] > key)
//            {
//                end = mid - 1;
//            }
//            else if (array[mid] < key)
//            {
//                start = mid + 1;
//            }
//        }
//        return false;
//    }
//    // Binary search on a sorted linked list. Returns true if the key is found, false otherwise.
//    bool searchLinkedList(Node<T>* head, T key)
//    {
//        if (head == nullptr)
//        {
//            return false;
//        }
//        Node<T>* end = nullptr;
//        while (head != end)
//        {
//            Node<T>* iter1 = head;
//            Node<T>* iter2 = head;
//            while (iter2 != end && iter2->next != end)
//            {
//                iter1 = iter1->next;        // Find the middle element.
//                iter2 = iter2->next->next; // Fast pointer moves twice as fast.
//            }
//            if (iter1->data == key)
//            {
//                return true;
//            }
//            else if (iter1->data > key)
//            {
//                end = iter1; // Narrow the range to the first half.
//            }
//            else if (iter1->data < key)
//            {
//                head = iter1->next; // Narrow the range to the second half.
//            }
//        }
//        return false;
//    }
//    // Measures the execution time of a binary search on the specified data structure.
//    void analyzeExecutionTime(string structureType, int inputSize, T key)
//    {
//        if (structureType == "array")
//        {
//            int* arr = new T[inputSize];
//            for (int i = 0; i < inputSize; i++)
//            {
//                arr[i] = i + 1; // Create a sorted array.
//            }
//            BinarySearch<int> bs;
//            time_point<high_resolution_clock> start, end;
//            start = high_resolution_clock::now();
//            bs.searchArray(arr, inputSize, key);
//            end = high_resolution_clock::now();
//            cout << endl << fixed << "Time in nanoseconds: " << duration_cast<nanoseconds>(end - start).count() << endl;
//        }
//        else if (structureType == "list")
//        {
//            SLList<T> list{};
//            for (int i = 0; i < inputSize; i++)
//            {
//                list.addToTail(i + 1); // Create a sorted linked list.
//            }
//            BinarySearch<int> bs;
//            time_point<high_resolution_clock> start, end;
//            start = high_resolution_clock::now();
//            bs.searchLinkedList(list.getHead(), key);
//            end = high_resolution_clock::now();
//            cout << endl << fixed << "Time in nanoseconds: " << duration_cast<nanoseconds>(end - start).count() << endl;
//        }
//    }
//};
// //Main function to test the BinarySearch class and measure execution times.
//int main()
//{
//    try
//    {
//        BinarySearch<int> bs;
//        SLList<int> list;
//        int arr[100];
//        for (int i = 0; i < 100; i++)
//        {
//            arr[i] = i + 1; // Create a sorted array of size 100.
//        }
//        for (int i = 0; i < 100; i++)
//        {
//            list.addToTail(i + 1); // Create a sorted linked list of size 100.
//        }
//        // Measure and display the execution time of binary search on array and linked list.
//        cout << "Execution time for Array";
//        cout << "\n";
//        bs.analyzeExecutionTime("array", 100, 50);
//        bs.analyzeExecutionTime("array", 1000, 500);
//        bs.analyzeExecutionTime("array", 10000, 5000);
//        cout << "\nExecution time for List";
//        cout << "\n";
//        bs.analyzeExecutionTime("list", 100, 50);
//        bs.analyzeExecutionTime("list", 1000, 500);
//        bs.analyzeExecutionTime("list", 10000, 5000);
//    }
//	catch(const char* except)
//	  {
//		  cout << except;
//    }
//  return 0;
//}
