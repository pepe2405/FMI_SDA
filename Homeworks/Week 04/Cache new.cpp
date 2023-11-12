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
	long long capacity;
	long long size;
	Node** nodes = new Node * [10000] {nullptr};

	List(long long capacity)
	{
		this->capacity = capacity;
		size = 0;
		head = new Node();
		tail = new Node();
	}

	void removeEnd()
	{
		int key = tail->key;
		nodes[key] = nullptr;
		if (head == tail)
		{
			head = tail = nullptr;
		}
		else
		{
			tail->prev->next = nullptr;
			tail = tail->prev;
		}

	}
	void addStart(long long x, long long y)
	{
		Node* node = new Node(x, y);
		if (size == 0 || head == nullptr)
		{
			head = tail = node;
		}
		else
		{
			node->next = head;
			head->prev = node;
			head = node;
			head->prev = nullptr;
		}
	}
	void moveStart(long long x)
	{
		if (nodes[x] != head) {
			if (nodes[x] == nullptr)
				return;

			Node* curr = nodes[x];
			Node* prevEl = nodes[x]->prev;
			Node* nextEl = nodes[x]->next;

			if (prevEl != nullptr && nextEl != nullptr)
			{
				prevEl->next = nextEl;
				nextEl->prev = prevEl;
			}
			if (prevEl == nullptr)
				return;
			if (nextEl == nullptr)
			{
				tail = prevEl;
				tail->next = nullptr;
			}

				
			
			curr->next = head;
			head->prev = curr;
			head = curr;
			head->prev = nullptr;
		}
	}

	void put(long long x, long long y)
	{
		//Contains
		if (nodes[x])
		{
			nodes[x]->data = y;
			moveStart(x);
			return;
		}
		//End of contains
		
		//Max size
		if (size == capacity)
		{
			removeEnd();
			addStart(x, y);
			nodes[x] = head;
			return;
		}
		//End of max size

		//Not existing
		addStart(x, y);
		size++;
		nodes[x] = head;
		//End of not existing
		
	}
	void get(long long x)
	{
		if (nodes[x] == nullptr)
		{
			std::cout << -1 << std::endl;
			return;
		}
		moveStart(x);
		std::cout << nodes[x]->data << std::endl;
	}
	void print() const
	{
		Node* curr = head;
		while (curr != nullptr)
		{
			std::cout << curr->key << ' ' << curr->data << std::endl;
			curr = curr->next;
		}
	}
};

int main()
{
	long long n, q, k, x, y, count = 0;
	std::string putComm = "put";
	std::string getComm = "get";
	std::cin >> n >> q >>k;
	List list(n);
	for (int i = 0; i < q; i++)
	{
		if ((i) % k == 0 && i > 0)
		{
			list.removeEnd();
			list.size--;
		}
		std::string str;
		std::cin >> str;
		if (str == putComm)
		{
			std::cin >> x >> y;
			list.put(x, y);
		}
		else if (str == getComm)
		{
			std::cin >> x;
			list.get(x);
		}

		
	}
}