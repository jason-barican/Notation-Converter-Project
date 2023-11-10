//Jason Barican U18728557
//Samuel Sau U44954874

#include "NotationDeque.hpp"

/*********************************
-  Doubly Linked List Functions  -
*********************************/

DLinkedList::DLinkedList() {
    header = new DNode;
    trailer = new DNode;
    header->next = trailer;
    trailer->prev = header;
}

DLinkedList::~DLinkedList() {
    while (!empty()) removeFront();
    delete header;
    delete trailer;
}

bool DLinkedList::empty() const {
    return (header->next == trailer);
}

const std::string& DLinkedList::front() const {
    return header->next->str;
}

const std::string& DLinkedList::back() const {
    return trailer->prev->str;
}

void DLinkedList::add(DNode* v, const std::string& e) {
    DNode* u = new DNode;
    u->str = e;
    u->next = v;
    u->prev = v->prev;
    v->prev = u;
    v->prev->prev->next = v->prev;
}

void DLinkedList::add(DNode* v, const char& e) {        //overload function for char elem
    DNode* u = new DNode;
    u->str = e;
    u->next = v;
    u->prev = v->prev;
    v->prev = u;
    v->prev->prev->next = v->prev;
}

void DLinkedList::addFront(const std::string& e) {
    add(header->next, e);
}

void DLinkedList::addFront(const char& e) {             //overload function for char elem
    add(header->next, e);
}

void DLinkedList::addBack(const std::string& e) {
    add(trailer, e);
}

void DLinkedList::addBack(const char& e) {              //overload function for char elem
    add(trailer, e);
}

void DLinkedList::remove(DNode* v) {
    DNode* u = v->prev;
    DNode* w = v->next;
    u->next = w;
    w->prev = u;
    delete v;
}

void DLinkedList::removeFront(){
    remove(header->next);
}

void DLinkedList::removeBack() {
    remove(trailer->prev);
}

/*****************************
-  Notation Deque Functions  -
*****************************/

int NotationDeque::size() const{
    return n;
}

bool NotationDeque::empty() const{
    return D.empty();
}

const std::string& NotationDeque::front() {
    return D.front();
}

const std::string& NotationDeque::back() {
    return D.back();
}

void NotationDeque::insertFront(const std::string& e) {
    D.addFront(e);
    n++;
}

void NotationDeque::insertFront(const char& e) {            //overload for char
    D.addFront(e);
    n++;
}

void NotationDeque::insertBack(const std::string& e) {
    D.addBack(e);
    n++;
}

void NotationDeque::insertBack(const char& e) {             //overload for char
    D.addBack(e);
    n++;
}



void NotationDeque::removeFront() {
    D.removeFront();
    n--;
}

void NotationDeque::removeBack() {
    D.removeBack();
    n--;
}