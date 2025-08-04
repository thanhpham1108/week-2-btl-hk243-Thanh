#include "DoublyLinkedList.h"

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList() : length(0)
{
    head = new Node(); // dummy head
    tail = new Node(); // dummy tail
    head->next = tail;
    tail->prev = head;
} // day la dummy

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList(){
Node *current = head;
while(current != nullptr){
    Node* next =current->next;
    delete current;
    current= next;
}

}

template <typename T>
void DoublyLinkedList<T>::insertAtHead(T data){

Node * new_node = new Node(data);
new_node->next = head->next;
new_node->prev = head;
head->next->prev=new_node;
head->next = new_node;
length++;

}
template <typename T>
void DoublyLinkedList<T>::insertAtTail(T data){
Node* new_node = new Node(data);
new_node->next = tail;
new_node->prev = tail->prev;
tail->prev->next = new_node;
tail->prev = new_node;

length++;
}

template <typename T>
void DoublyLinkedList<T>::insertAt(int index, T data){

Node *new_node = new Node(data);

if(index < 0 || index > length){
    throw out_of_range("Index is invalid!");
}
if(index == 0){
   insertAtHead(data);
   return;
}
if(index == length ){
    insertAtTail(data);
    return;
}

Node *current = head->next;
for(int i = 0 ; i<index ;i++){
    current = current->next;
}
new_node->prev = current->prev;
new_node->next = current;
current->prev->next = new_node;
current->prev= new_node;
length++;


}

template <typename T>
void DoublyLinkedList<T>::deleteAt(int index){
if(index < 0 || index >= length){
    throw out_of_range("Index is invalid!");
}
Node *current = head->next;
for(int i= 0; i<index ; i++){
    current=current->next;

}
current->prev->next = current->next;
current->next->prev = current->prev;
delete current;
length--;
}
template <typename T>
T& DoublyLinkedList<T>::get(int index) const {
Node *current = head->next;
if(index < 0 || index >= length){
    throw out_of_range("Index is invalid!");
}
for(int i = 0 ; i <index ; i++){
    current = current->next;

}
return current->data;
}
template <typename T>
int DoublyLinkedList<T>::indexOf(T item) const{

Node *current = head->next;
for(int i = 0 ; i<length ; i++){
    if(current->data == item){
        return i;

    }
    current = current->next;
}
return -1;
}
template <typename T>
bool DoublyLinkedList<T>::contains(T item) const{
Node *current = head->next;
for(int i = 0 ; i<length; i++){
    if(current->data == item) return true;
    current=current->next;
}

return false;
}
template <typename T>
int DoublyLinkedList<T>::size()const {
return length;
}

template <typename T>
void DoublyLinkedList<T>::reverse(){
Node *current = head;

while(current != nullptr){
    swap(current->next ,current->prev);
    current=current->prev;



}
swap (head,tail);


}

string convert2str(char& c){ return string(1,c);}
string convert2str(string& s) {return s;}
string convert2str(int& x ){return to_string(x);}
string convert2str(double& d){
ostringstream os;
os<<fixed<<setprecision(2)<<d;
return os.str();

}
string convert2str(float& f){
ostringstream os;
os<<fixed<<setprecision(2)<<f;
return os.str();

}
string convert2str(Point& p){
return "("+to_string(p.getX())+ "," +to_string(p.getY())+"," + to_string(p.getZ()) +")";
}
template <typename T>
string DoublyLinkedList<T>::toString(string (*convert2str)(T &)) const{
string result = "[";
Node *current = head->next;
for(int i = 0 ; i < length ; i++){
    result += convert2str (current->data);
    if(i != length -1 ) result += ", ";
    current = current->next;
}
result += "]";

return result;
}

// TODO implement DoublyLinkedList

// Explicit template instantiation for char, string, int, double, float, and Point
template class DoublyLinkedList<char>;
template class DoublyLinkedList<string>;
template class DoublyLinkedList<int>;
template class DoublyLinkedList<double>;
template class DoublyLinkedList<float>;
template class DoublyLinkedList<Point>;
