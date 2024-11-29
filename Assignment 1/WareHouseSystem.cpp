//#include<iostream>
//#include<ctime>
//#include<vector>
//using namespace std;
//template<typename T>
//class Stack
//{
//	T* stack;
//	int top;
//	int size;
//public:
//	Stack()
//	{
//		size = 1;
//		stack = new T[size];
//		top = -1;
//	}
//	Stack(int cap)
//	{
//		if (cap < 0)
//		{
//			exit(0);
//		}
//		else
//		{
//			stack = new T[cap];
//			top = -1;
//			size = cap;
//		}
//	}
//	bool isEmpty()
//	{
//		return top == -1 ? true : false;
//	}
//
//	bool isFull()
//	{
//		return top == size - 1 ? true : false;
//	}
//	void push(T item)
//	{
//		if (!isFull())
//		{
//			stack[++top] = item;
//		}
//		else
//		{
//			resize(size * 2);
//			stack[++top] = item;
//		}
//	}
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
//	int getSize()
//	{
//		return size;
//	}
//	~Stack()
//	{
//		if (!stack)
//		{
//			return;
//		}
//		delete[]stack;
//		stack = nullptr;
//		size = 0;
//		top = -1;
//	}
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
//		int newT = top;
//		delete[] stack;
//		stack = newStack;
//		top = newT;
//		size = newCap;
//	}
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
//template<typename T>
//class Queue
//{
//	T* data;
//	int size;
//	int front;
//	int rear;
//	int noOfElements;
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
//			delete[]data;
//		data = temp;
//		size = newSize;
//	}
//public:
//	Queue()
//	{}
//	int getNoOfElements()const
//	{
//		return noOfElements;
//	}
//	int getSize()const
//	{
//		return size;
//	}
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
//	bool isEmpty()const
//	{
//		return (front == -1) ? true : false;
//	}
//	bool isFull()const
//	{
//		return (noOfElements == size) ? true : false;
//	}
//	T showFront()const
//	{
//		if (!isEmpty())
//		{
//			T element = data[front % size];
//			return element;
//		}
//		else
//		{
//			throw "\nQueue is empty:";
//		}
//	}
//	T showRear()const
//	{
//		if (!isEmpty())
//		{
//			T element = data[rear];
//			return element;
//		}
//		else
//		{
//			throw "\nQueue is empty:";
//		}
//	}
//	void enqueue(T element)
//	{
//		if (isFull())
//		{
//			reSize(size + 1);
//		}
//		rear = (rear + 1) % size;;
//		data[rear] = element;
//		if (front == -1)
//		{
//			front = 0;
//		}
//		noOfElements++;
//	}
//	T dequeue()
//	{
//		if (!isEmpty())
//		{
//			front = front % size;
//			T element = data[front];
//			if (front == rear)
//			{
//				front = rear = -1;
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
//	T shiftedDequeue()
//	{
//		if (!isEmpty())
//		{
//			T element = data[front];
//			for (int i = 0; i < rear; i++)
//			{
//				data[i] = data[i + 1];
//			}
//			rear--;
//			if (front == rear)
//			{
//				front = rear = -1;
//			}
//			return element;
//		}
//		else
//		{
//			throw "\nQueue is Empty:";
//		}
//
//	}
//	void printQueue()
//	{
//		for (int i = 0; i < size; i++)
//		{
//			cout << data[i] << ' ';
//		}
//	}
//	~Queue()
//	{
//		if (!data)
//		{
//			return;
//		}
//		delete[]data;
//		size = 0;
//		rear = -1;
//		front = -1;
//	}
//};
//class PriorityQueue 
//{
//	vector<pair<int, int>> queue;
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
//	void insert(int element, int priority)
//	{
//		if (priority <= 0)
//		{
//			cout << "Priority should be greater than 0.\n";
//			return;
//		}
//		queue.push_back({ element, priority });
//	}
//	int getHighestPriorityElement() const 
//	{
//		if (isEmpty())
//		{
//			throw "Priority Queue is empty.";
//		}
//		int index = findHighestPriorityIndex();
//		return queue[index].first;
//	}
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
//	bool isEmpty() const
//	{
//		return queue.empty();
//	}
//	void print()
//	{
//		for (int i = 0; i < queue.size(); i++)
//		{
//			cout << "Element: " << queue[i].first << "\tPriority: " << queue[i].second << "\n";
//		}
//	}
//};
//class MTPSystem
//{
//	Stack<int> st;
//	Queue<int> qu;
//	PriorityQueue pq;
//public:
//	void unloadShipment(int shipmentID)
//	{
//		if (shipmentID <= 0)
//		{
//			cout << "Shipment ID should be greater than 0.\n";
//			return;
//		}
//		st.push(shipmentID);
//	}
//	void addDispatchRequest(int shipmentID, int priority)
//	{
//		Stack<int> s;
//		while (!st.isEmpty() && shipmentID != st.peek())
//		{
//			s.push(st.pop());
//		}
//		if (st.isEmpty())
//		{
//			cout << "Shipment ID " << shipmentID << " does not exist or already dispatched.\n";
//		}
//		else
//		{
//			qu.enqueue(shipmentID);
//			pq.insert(shipmentID, priority);
//			st.pop();
//		}
//		while(!s.isEmpty())
//		{
//			st.push(s.pop());
//		}
//	}
//	int processDispatch()
//	{
//		int ele = pq.getHighestPriorityElement();
//		pq.removeHighestPriorityElement();
//		return ele;
//	}
//	void displaySystemState()
//	{
//		cout << "Shipments available:\n";
//		st.print();
//		cout << "\nShipments requested for dispatching:\n";
//		pq.print();
//	}
//};
//int main()
//{
//	try
//	{
//		srand(time(0));
//		MTPSystem s;
//		s.unloadShipment(-1);
//		for (int i = 1; i <= 10; i++)
//		{
//			s.unloadShipment(i + 10);
//		}
//		cout << s.processDispatch();
//		s.addDispatchRequest(12, (rand() % 10 + 1));
//		s.addDispatchRequest(19, (rand() % 10 + 1));
//		s.addDispatchRequest(9, (rand() % 10 + 1));
//		s.addDispatchRequest(15, (rand() % 10 + 1));
//		s.addDispatchRequest(17, (rand() % 10 + 1));
//		cout << "Before dispatching:\n";
//		s.displaySystemState();
//		s.processDispatch();
//		cout << "After dispatching:\n";
//		s.displaySystemState();
//		return 0;
//	}
//	catch(const char* p)
//	{
//		cout << p;
//	}
//}