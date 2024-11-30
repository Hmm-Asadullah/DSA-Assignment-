//#include<iostream>
//#include<ctime>
//using namespace std;
//// Structure to represent a customer
//struct Customer
//{
//	int ID;    // Unique ID of the customer
//	int count; // Number of orders made by the customer
//};
//// Template structure for a Node in the singly linked list
//template<typename T>
//struct Node
//{
//	T data;          // Data stored in the node (in this case, a Customer)
//	Node<T>* next;   // Pointer to the next node
//	Node(T d, Node<T>* n = nullptr) // Constructor to initialize a node
//	{
//		data = d;
//		next = n;
//	}
//};
//// Template class for a Singly Linked List (SLList)
//template<typename T>
//class SLList
//{
//	Node<T>* head; // Pointer to the head of the list
//	Node<T>* tail; // Pointer to the tail of the list
//public:
//	// Constructor to initialize an empty list
//	SLList()
//	{
//		head = nullptr;
//		tail = nullptr;
//	}
//	// Destructor to delete all nodes and release memory
//	~SLList()
//	{
//		while (head)
//		{
//			Node<T>* temp = head;
//			head = head->next;
//			delete temp;
//		}
//		head = tail = nullptr;
//	}
//	// Check if the list is empty
//	bool isEmpty()
//	{
//		return (head == nullptr && tail == nullptr);
//	}
//	// Add an element to the head of the list
//	void addToHead(T e)
//	{
//		head = new Node<T>(e, head);
//		if (tail == nullptr) // If the list was empty, update the tail
//		{
//			tail = head;
//		}
//	}
//	// Add an element to the tail of the list
//	void addToTail(T e)
//	{
//		if (tail != nullptr) // If the list is not empty
//		{
//			tail->next = new Node<T>(e);
//			tail = tail->next;
//		}
//		else // If the list is empty
//		{
//			tail = head = new Node<T>(e);
//		}
//	}
//	// Get a reference to the tail node
//	Node<T>*& getTail()
//	{
//		return tail;
//	}
//	// Get a reference to the head node
//	Node<T>*& getHead()
//	{
//		return head;
//	}
//	// Print the list, showing customer IDs and their order counts
//	void printList()
//	{
//		if (!isEmpty())
//		{
//			Node<T>* iter = head;
//			cout << "IDs\tOrders Count\n";
//			while (iter)
//			{
//				cout << iter->data.ID << "\t" << iter->data.count << "\n";
//				iter = iter->next;
//			}
//		}
//		else
//		{
//			throw "\nElement not found"; // If the list is empty, throw an exception
//		}
//	}
//};
//// Function to move customers with more than 10 orders to a VIP list
//void moveToVIP(Node<Customer>*& head, Node<Customer>*& vipHead)
//{
//	if (!head) // Base case: if the list is empty, stop recursion
//	{
//		return;
//	}
//	if (head->data.count > 10) // If the customer's order count is greater than 10
//	{
//		Node<Customer>* temp = head; // Save the current node
//		vipHead = new Node<Customer>(head->data, vipHead); // Add the customer to the VIP list
//		head = head->next; // Move the head pointer to the next node
//		delete temp; // Delete the original node
//		moveToVIP(head, vipHead); // Recursively process the rest of the list
//	}
//	else // If the customer's order count is 10 or less
//	{
//		moveToVIP(head->next, vipHead); // Recursively process the next node
//	}
//}
//// Function to remove customers with fewer than 3 orders from the list
//void removeLowOrders(Node<Customer>*& head)
//{
//	if (!head) // Base case: if the list is empty, stop recursion
//	{
//		return;
//	}
//	if (head->data.count < 3) // If the customer's order count is less than 3
//	{
//		Node<Customer>* temp = head; // Save the current node
//		head = head->next; // Move the head pointer to the next node
//		delete temp; // Delete the original node
//		removeLowOrders(head); // Recursively process the rest of the list
//	}
//	else // If the customer's order count is 3 or more
//	{
//		removeLowOrders(head->next); // Recursively process the next node
//	}
//}
//// Function to calculate the total number of orders in the list
//int calculateTotalOrders(Node<Customer>* head)
//{
//	if (!head) // Base case: if the list is empty, return 0
//	{
//		return 0;
//	}
//	return head->data.count + calculateTotalOrders(head->next); // Add the current node's order count and recurse
//}
////Main function for testing
//int main()
//{
//	try
//	{
//		srand(time(0)); // Seed the random number generator
//		SLList<Customer> list, vipList; // Create the main customer list and the VIP list
//		// Add 15 customers to the main list with random order counts between 1 and 15
//		for (int i = 1; i < 16; i++)
//		{
//			list.addToTail(Customer{ i, (rand() % 15 + 1) });
//		}
//		// Print the original list
//		cout << "Main list:\n";
//		list.printList();
//		// Calculate and print the total number of orders in the original list
//		cout << "Total orders: " << calculateTotalOrders(list.getHead()) << " \n";
//		// Remove customers with fewer than 3 orders
//		removeLowOrders(list.getHead());
//		// Print the list after removing low-order customers
//		cout << "Main list after removing low orders:\n";
//		list.printList();
//		// Calculate and print the total number of orders after removing low-order customers
//		cout << "Total orders after removing low orders: " << calculateTotalOrders(list.getHead()) << " \n";
//		// Move customers with more than 10 orders to the VIP list
//		moveToVIP(list.getHead(), vipList.getHead());
//		// Print the main list after moving customers to the VIP list
//		cout << "Main list after moving orders to vipList:\n";
//		list.printList();
//		// Print the VIP list
//		cout << "Vip list:\n";
//		vipList.printList();
//		// Calculate and print the total number of orders in the main list after moving customers to the VIP list
//		cout << "Total orders after moving orders to vipList: " << calculateTotalOrders(list.getHead()) << " \n";
//	}
//	catch(const char* except)
//	{
//		cout << except;
//	}
//	return 0;
//}
