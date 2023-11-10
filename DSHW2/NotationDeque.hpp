//Jason Barican U18728557
//Samuel Sau U44954874

#ifndef NOTATIONDEQUE_H
#define NOTATIONDEQUE_H

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <sstream>

using namespace std;
typedef string Elem;						//sets "Elem" to type string

class DNode {								//declares node for DLinkedList
private:
	friend class DLinkedList;
	Elem str;
	DNode* prev;
	DNode* next;
};

class DLinkedList {
public:
	DLinkedList();
	~DLinkedList();
	bool empty() const;
	const Elem& front() const;
	const Elem& back() const;
	void addFront(const Elem& e);
	void addFront(const char& e);			//overload function for char elem
	void addBack(const Elem& e);
	void addBack(const char& e);			//overload function for char elem
	void removeFront();
	void removeBack();

private:
	DNode* header;
	DNode* trailer;

protected:
	void add(DNode* v, const Elem& e);
	void add(DNode* v, const char& e);		//overload function for char elem
	void remove(DNode* v);
};

class NotationDeque {
public:
	int size() const;
	bool empty() const;
	const Elem& front();
	const Elem& back();

	void insertFront(const Elem& e);
	void insertFront(const char& e);		//overload function for char elem

	void insertBack(const Elem& e);
	void insertBack(const char& e);			//overload function for char elem

	void removeFront();
	void removeBack();
	
private:
	DLinkedList D;
	int n = 0;
};
#endif //!NOTATIONCONVERTERINTERFACE_H