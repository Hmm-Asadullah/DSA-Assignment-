//#include<iostream>
//#include<ctime>
//#include<vector>
//using namespace std;
//// Template class for a stack implementation
//template<typename T>
//class Stack
//{
//	T* stack; // Dynamic array for stack elements
//	int top;  // Index of the top element
//	int size; // Current capacity of the stack
//public:
//	// Default constructor initializing a stack with capacity 1
//	Stack()
//	{
//		size = 1;
//		stack = new T[size];
//		top = -1;
//	}
//	// Constructor with specified capacity
//	Stack(int cap)
//	{
//		if (cap < 0)
//		{
//			exit(0); // Exit if capacity is invalid
//		}
//		else
//		{
//			stack = new T[cap];
//			top = -1;
//			size = cap;
//		}
//	}
//	// Check if the stack is empty
//	bool isEmpty()
//	{
//		return top == -1;
//	}
//	// Check if the stack is full
//	bool isFull()
//	{
//		return top == size - 1;
//	}
//	// Push an element onto the stack
//	void push(T item)
//	{
//		if (!isFull())
//		{
//			stack[++top] = item;
//		}
//		else
//		{
//			resize(size * 2); // Double the capacity if full
//			stack[++top] = item;
//		}
//	}
//	// Pop an element from the stack
//	T pop()
//	{
//		if (!isEmpty())
//		{
//			return stack[top--];
//		}
//		else
//		{
//			cout << "Error stack is empty.";
//		}
//	}
//	// Get the top element without removing it
//	T peek()
//	{
//		if (!isEmpty())
//		{
//			return stack[top];
//		}
//		else
//		{
//			cout << "Error stack is empty.";
//		}
//	}
//	// Get the current size (capacity) of the stack
//	int getSize()
//	{
//		return size;
//	}
//	// Destructor to free the allocated memory
//	~Stack()
//	{
//		if (!stack)
//		{
//			return;
//		}
//		delete[] stack;
//		stack = nullptr;
//		size = 0;
//		top = -1;
//	}
//	// Resize the stack to a new capacity
//	void resize(int newCap)
//	{
//		if (newCap <= 0)
//		{
//			return;
//		}
//		T* newStack = new T[newCap];
//		for (int i = 0; i <= top; i++)
//		{
//			newStack[i] = stack[i];
//		}
//		delete[] stack;
//		stack = newStack;
//		size = newCap;
//	}
//	// Print all elements in the stack (from top to bottom)
//	void print()
//	{
//		if (!isEmpty())
//		{
//			for (int i = top; i >= 0; i--)
//			{
//				cout << stack[i] << " ";
//			}
//		}
//	}
//};
//// Template class for queue implementation
//template<typename T>
//class Queue
//{
//	T* data;          // Dynamic array for queue elements
//	int size;         // Capacity of the queue
//	int front;        // Index of the front element
//	int rear;         // Index of the rear element
//	int noOfElements; // Number of elements in the queue
//	// Resize the queue to a new size
//	void reSize(int newSize)
//	{
//		if (newSize <= 0)
//		{
//			return;
//		}
//		T* temp = new T[newSize];
//		int i = 0;
//		while (i < newSize && i < size)
//		{
//			temp[i] = data[i];
//			i++;
//		}
//		if (data)
//			delete[] data;
//		data = temp;
//		size = newSize;
//	}
//public:
//	// Default constructor
//	Queue() {}
//	// Constructor with specified size
//	Queue(int s)
//	{
//		if (s <= 0)
//		{
//			data = nullptr;
//			size = 0;
//			rear = front = -1;
//			noOfElements = 0;
//			return;
//		}
//		size = s;
//		data = new T[size];
//		rear = front = -1;
//		noOfElements = 0;
//	}
//	// Check if the queue is empty
//	bool isEmpty() const
//	{
//		return (front == -1);
//	}
//	// Check if the queue is full
//	bool isFull() const
//	{
//		return (noOfElements == size);
//	}
//	// Get the element at the front
//	T showFront() const
//	{
//		if (!isEmpty())
//		{
//			return data[front % size];
//		}
//		else
//		{
//			throw "\nQueue is empty:";
//		}
//	}
//	// Get the element at the rear
//	T showRear() const
//	{
//		if (!isEmpty())
//		{
//			return data[rear];
//		}
//		else
//		{
//			throw "\nQueue is empty:";
//		}
//	}
//	// Add an element to the rear of the queue
//	void enqueue(T element)
//	{
//		if (isFull())
//		{
//			reSize(size + 1); // Resize if full
//		}
//		rear = (rear + 1) % size;
//		data[rear] = element;
//		if (front == -1)
//		{
//			front = 0;
//		}
//		noOfElements++;
//	}
//	// Remove an element from the front of the queue
//	T dequeue()
//	{
//		if (!isEmpty())
//		{
//			front = front % size;
//			T element = data[front];
//			if (front == rear)
//			{
//				front = rear = -1; // Reset if queue becomes empty
//			}
//			else
//			{
//				front++;
//			}
//			noOfElements--;
//			return element;
//		}
//		else
//		{
//			throw "\nQueue is Empty:";
//		}
//	}
//	// Destructor to release memory
//	~Queue()
//	{
//		if (!data)
//		{
//			return;
//		}
//		delete[] data;
//		size = 0;
//		rear = -1;
//		front = -1;
//	}
//};
//// Priority Queue class implemented using a vector
//class PriorityQueue
//{
//	vector<pair<int, int>> queue; // Vector storing (element, priority) pairs
//	// Helper function to find the index of the highest-priority element
//	int findHighestPriorityIndex() const
//	{
//		if (queue.empty())
//			return -1;
//		int highestPriorityIndex = 0;
//		for (int i = 1; i < queue.size(); i++)
//		{
//			if (queue[i].second < queue[highestPriorityIndex].second ||
//				(queue[i].second == queue[highestPriorityIndex].second && i < highestPriorityIndex))
//			{
//				highestPriorityIndex = i;
//			}
//		}
//		return highestPriorityIndex;
//	}
//public:
//	// Insert an element with a specific priority
//	void insert(int element, int priority)
//	{
//		if (priority <= 0)
//		{
//			cout << "Priority should be greater than 0.\n";
//			return;
//		}
//		queue.push_back({ element, priority });
//	}
//	// Get the element with the highest priority
//	int getHighestPriorityElement() const
//	{
//		if (isEmpty())
//		{
//			throw "Priority Queue is empty.";
//		}
//		int index = findHighestPriorityIndex();
//		return queue[index].first;
//	}
//	// Remove the element with the highest priority
//	void removeHighestPriorityElement()
//	{
//		if (isEmpty())
//		{
//			cout << "Priority Queue is empty.";
//			return;
//		}
//		int index = findHighestPriorityIndex();
//		queue.erase(queue.begin() + index);
//	}
//	// Check if the priority queue is empty
//	bool isEmpty() const
//	{
//		return queue.empty();
//	}
//	// Print all elements in the priority queue
//	void print()
//	{
//		for (int i = 0; i < queue.size(); i++)
//		{
//			cout << "Element: " << queue[i].first << "\tPriority: " << queue[i].second << "\n";
//		}
//	}
//};
//// Multi-Tier Processing System Class
//class MTPSystem
//{
//	Stack<int> st;          // Stack for storing shipment IDs
//	Queue<int> qu;          // Queue for dispatch requests
//	PriorityQueue pq;       // Priority queue for handling priorities
//public:
//	// Unload a shipment into the system
//	void unloadShipment(int shipmentID)
//	{
//		if (shipmentID <= 0)
//		{
//			cout << "Shipment ID should be greater than 0.\n";
//			return;
//		}
//		st.push(shipmentID);
//	}
//	// Add a dispatch request for a specific shipment ID with a priority
//	void addDispatchRequest(int shipmentID, int priority)
//	{
//		Stack<int> s; // Temporary stack for reordering
//		while (!st.isEmpty() && shipmentID != st.peek())
//		{
//			s.push(st.pop());
//		}
//		if (st.isEmpty())
//		{
//			cout << "Shipment ID " << shipmentID << " does not exist or already dispatched or requested.\n";
//		}
//		else
//		{
//			qu.enqueue(shipmentID);
//			pq.insert(shipmentID, priority);
//			st.pop();
//		}
//		while (!s.isEmpty())
//		{
//			st.push(s.pop());
//		}
//	}
//	// Dispatch the highest-priority shipment
//	int processDispatch()
//	{
//		int shipmentID = pq.getHighestPriorityElement();
//		cout << "Dispatching shipment with ID: " << shipmentID << endl;
//		pq.removeHighestPriorityElement();
//		qu.dequeue();
//		return shipmentID;
//	}
//	//Displaying the system state
//	void displaySystemState()
//	{
//		cout << "Shipments available:\n";
//		if (st.isEmpty())
//		{
//			cout << 0 << "\n";
//		}
//		else
//		{
//			st.print();
//		}
//		cout << "\nShipments requested for dispatching:\n";
//		if (pq.isEmpty())
//		{
//			cout << 0 << "\n";
//		}
//		else
//		{
//			pq.print();
//		}
//	}
//};
//// Main function for testing
//int main()
//{
//	try
//	{
//		MTPSystem MTP;
//		MTP.unloadShipment(20);
//		MTP.unloadShipment(99);
//		MTP.unloadShipment(24);
//		MTP.unloadShipment(49);
//		MTP.unloadShipment(8);
//		MTP.unloadShipment(10);
//		MTP.unloadShipment(71);
//		MTP.unloadShipment(82);
//		MTP.unloadShipment(89);
//		MTP.unloadShipment(23);
//		MTP.displaySystemState();
//		MTP.addDispatchRequest(20, 7);
//		MTP.displaySystemState();
//		MTP.addDispatchRequest(10, 2);
//		MTP.displaySystemState();
//		MTP.addDispatchRequest(24, 3);
//		MTP.displaySystemState();
//		MTP.addDispatchRequest(82, 1);
//		MTP.displaySystemState();
//		MTP.addDispatchRequest(8, 1);
//		MTP.displaySystemState();
//		MTP.addDispatchRequest(99, 5);
//		MTP.displaySystemState();
//		MTP.addDispatchRequest(89, 4);
//		MTP.displaySystemState();
//		MTP.addDispatchRequest(23, 6);
//		MTP.displaySystemState();
//		MTP.addDispatchRequest(71, 7);
//		MTP.displaySystemState();
//		MTP.addDispatchRequest(49, 2);
//		MTP.displaySystemState();
//		MTP.processDispatch();
//		MTP.displaySystemState();
//		MTP.processDispatch();
//		MTP.displaySystemState();
//		MTP.processDispatch();
//		MTP.displaySystemState();
//		MTP.processDispatch();
//		MTP.displaySystemState();
//		MTP.processDispatch();
//		MTP.displaySystemState();
//		MTP.processDispatch();
//		MTP.displaySystemState();
//		MTP.processDispatch();
//		MTP.displaySystemState();
//		MTP.processDispatch();
//		MTP.displaySystemState();
//		MTP.processDispatch();
//		MTP.displaySystemState();
//		MTP.processDispatch();
//		MTP.displaySystemState();
//	}
//	catch(const char* except)
//	{
//		cout << except;
//	}
//  return 0;
//}