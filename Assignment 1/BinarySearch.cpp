#include<iostream>
using namespace std;
template<typename T>
struct Node
{
	T data;
	Node* next;
	Node(T d, Node<T>* n = nullptr)
	{
		data = d;
		next = n;
	}
};
template<typename T>
class SLList
{
	Node<T>* head;
	Node<T>* tail;
public:
	SLList()
	{
		head = nullptr;
		tail = nullptr;
	}
	~SLList()
	{
		while (head)
		{
			Node<T>* temp = head;
			head = head->next;
			delete temp;
		}
		head = tail = nullptr;
	}
	bool isEmpty()
	{
		return (head == nullptr && tail == nullptr) ? true : false;
	}
	void addToHead(T e)
	{
		head = new Node<T>(e, head);
		if (tail == nullptr)
		{
			tail = head;
		}
	}
	void addToTail(T e)
	{
		if (tail != nullptr)
		{
			tail->next = new Node<T>(e);
			tail = tail->next;
		}
		else
		{
			tail = head = new Node<T>(e);
		}
	}
	Node<T>* getTail()
	{
		return tail;
	}
	Node<T>* getHead()
	{
		return head;
	}
	T deleteFromHead()
	{
		if (!isEmpty())
		{
			T element = head->data;
			if (head == tail)
			{
				delete head;
				head = tail = nullptr;
				return element;
			}
			Node<T>* temp = head;
			head = head->next;
			delete temp;
			return element;
		}
		throw "\nList is empty";
	}
	T deleteFromTail()
	{
		if (!isEmpty())
		{
			T element = tail->data;
			if (head == tail)
			{
				delete tail;
				tail = head = nullptr;
				return element;
			}
			Node<T>* temp = head, * iter = head;
			for (; temp->next != tail; temp = temp->next)
			{
			}
			delete tail;
			tail = temp;
			tail->next = nullptr;
			return element;
		}
		throw "\nList is Empty";
	}
	bool searchNode(T element)
	{
		Node<T>* iter = head;
		while (iter && iter->data != element)
		{
			iter = iter->next;
		}
		return (iter == nullptr) ? false : true;
	}
	void printList()
	{
		if (!isEmpty())
		{
			cout << '\n';
			Node<T>* iter = head;
			while (iter)
			{
				cout << iter->data << ' ';
				iter = iter->next;
			}
		}
		else
		{
			throw "\nElement not found";
		}
	}
	T removeNode(T e)
	{
		Node<T>* iter = head, * prev = head;
		while (iter && iter->data != e)
		{
			prev = iter;
			iter = iter->next;
		}
		if (iter)
		{
			T elem = iter->data;
			prev->next = iter->next;
			delete iter;
			return elem;
		}
		throw "\nElement not found";
	}
};
template<typename T>
class BinarySearch
{
public:
	bool searchArray(T array[], int size, T key)
	{
		if(size <= 0)
		{
			return false;
		}
		int start = 0;
		int end = size - 1;
		while (start <= end)
		{
			int mid = (start + end) / 2;
			if (array[mid] == key)
			{
				return true;
			}
			else if (array[mid] > key)
			{
				end = mid - 1;
			}
			else if (array[mid] < key)
			{
				start = mid + 1;
			}
		}
		return false;
	}
	bool searchLinkedList(Node<T>* head, T key)
	{
		if (head == nullptr)
		{
			return false;
		}
		Node<T>* end = nullptr;
		while (head != end)
		{
			Node<T>* iter1 = head;
			Node<T>* iter2 = head;
			while (iter2 != end && iter2->next != end)
			{
				iter1 = iter1->next;
				iter2 = iter2->next->next;
			}
			if (iter1->data == key)
			{
				return true;
			}
			else if (iter1->data > key)
			{
				end = iter1;
			}
			else if (iter1->data < key)
			{
				head = iter1->next;
			}
		}
		return false;
	}
};
int main()
{
	BinarySearch<int> bs;
	SLList<int> list;
	int arr[100];
	for (int i = 0; i < 100; i++)
	{
		arr[i] = i + 1;
	}
	for (int i = 0; i < 100; i++)
	{
		list.addToTail(i + 1);
	}
	cout << bs.searchArray(arr, 100, 10);
	cout << "\n";
	cout << bs.searchLinkedList(list.getHead(), 0);
}