#include <iostream>

struct Node {
    long long data;
    Node* next;
    Node* prev;

    Node(long long data) {
        this->data = data;
        next = nullptr;
        prev = nullptr;
    }
};

struct List {
    Node* head;
    Node* tail;
    Node* mid;
    long long count;

    List() {
        head = nullptr;
        tail = nullptr;
        mid = nullptr;
        count = 0;
    }

    void add(long long data)
    {
        Node* el = new Node(data);
	    if (head == nullptr)
	    {
            head = mid = tail = el;
            count = 1;
            return;
	    }
        tail->next = el;
        el->prev = tail;
        tail = el;
        count++;
        if (count % 2 == 0)
            mid = mid->next;
    }
    void gun()
    {
        if (tail == nullptr)
            return;
	    if (tail->prev == nullptr)
            head = mid = tail = nullptr;
	    else
	    {
            tail = tail->prev;
            tail->next = nullptr;
	    }
        count--;
        if (count % 2 == 1 && count != 1)
            mid = mid->prev;
    }
    void milen()
    {
	    if (head == nullptr || head->next == nullptr)
            return;
	    if (mid->prev == nullptr)
            return;
        Node* befMid = mid->prev;
        Node* newMid = mid;

        tail->next = head;
        head->prev = tail;
        if (count % 2 == 0)
            mid = head;
        else
            mid = tail;
        head = newMid;
        head->prev = nullptr;
        tail = befMid;
        tail->next = nullptr;
    }

    void print() const
    {
        Node* curr = head;
        while (curr)
        {
	        std::cout << curr->data << " ";
            curr = curr->next;
        }
        std::cout << std::endl;
    }
};

int main()
{
    long long n = 0, count = 0;
    std::cin >> n;
    std::string add = "add";
    std::string milen = "milen";
    std::string gun = "gun";
    List list;
    for (int i = 0; i < n; i++)
    {
        std::string str;
        std::cin >> str;
        if (str == add)
        {
            int k = 0;
            std::cin >> k;
            list.add(k);
            count++;
        }
        else if (str == gun)
        {
            list.gun();
            count--;
        }
        else if (str == milen)
            list.milen();
    }
    std::cout << count << std::endl;
    list.print();

}