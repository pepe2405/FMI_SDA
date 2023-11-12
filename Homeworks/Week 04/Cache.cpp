#include <iostream>
#include <list>

struct Node
{
	long long key, data;
	Node* next;
	Node* prev;
	Node()
	{
		next = nullptr;
		prev = nullptr;
		key = 0;
		data = 0;
	}
	Node(long long x, long long y) : Node()
	{
		key = x;
		data = y;
	}
};

class List
{
public:
	Node* head;
	Node* tail;
	long long size;
	long long capacity;
	List(long long capacity)
	{
		head = new Node();
		tail = new Node();
		size = 0;
		this->capacity = capacity;
	}

	void cutLast()
	{
		tail = tail->prev;
		tail->next = nullptr;
		size--;
	}
	void putLast(Node* el)
	{
		Node* copy = new Node();
		copy->key = el->key;
		copy->data = el->data;

		tail->next = copy;
		copy->prev = tail;
		tail = copy;
		copy->next = nullptr;
		Node* curr = head;
		while (curr != nullptr)
		{
			if (curr->key == copy->key)
			{	
				if (curr->prev != nullptr && curr->next != nullptr)
				{
					curr->prev->next = curr->next;
				}
				if (curr->next == nullptr)
				{
					tail = curr;
					tail->next = nullptr;
				}
				if (curr->prev == nullptr)
				{
					head = curr->next;
					head->prev = nullptr;
				}
			}
			curr = curr->next;
		}
	}

	void put(long long x, long long y)
	{
		Node* node = new Node(x, y);
		//List contains node
		
		//Max cap
		if (size == capacity)
		{
			cutLast();
		}
		//End of max cap

		//Empty list
		if (size == 0)
		{
			tail = node;
			head = node;
			size++;
			return;
		}
		//End of empty list

		//Add node
		putLast(node);
		size++;
	}
	void get(long long x)
	{
		Node* curr = head;
		while (curr != nullptr)
		{
			if (curr->key == x)
			{
				std::cout << std::endl << curr->data << std::endl;
				putLast(curr);
				return;
			}
			curr = curr->next;
		}
		std::cout << std::endl << -1 << std::endl;
	}

	void print()
	{
		Node* curr = head;
		while (curr != nullptr)
		{
			std::cout << curr-> key << ' ' << curr->data << std::endl;
			curr = curr->next;
		}
	}
};



int main()
{
	

}