/*TA : Huq sider, The credit is given from him 
The author: Hyo Kyung kang, Huq sider//
//Do not use  withoud 2 people permission mentioned upper.//


#include <iostream>
using namespace std;


class Term {
    float coff;
    int exp;
public:
    Term() {};
    Term(float c, int e) { coff = c; exp = e; };
	Term(){}
	bool operator==(Term t);
	friend ostream&operator<<(ostream& os, const Term& t);
    float get_coff() { return coff; };
    int get_exp() { return exp; };

};
template <class T>
struct Node {
    T data;
    Node * next;
};

template <class T>
class LinkedList {


public:

    LinkedList() : head(NULL), size(0) {};
    ~LinkedList();
    bool addNode(T data);
    bool deleteNode(T data);
    Node<T> * searchNode(T data);
    void printList();
    void reverseList();
    Node<T> * get_head() { return head;};

private:
    Node<T> * head;
    int size;

};

template <class T>
LinkedList<T>::~LinkedList() {
    Node<T> * tmp = NULL;
    while (head) {
        tmp = head;
        head = head->next;
        //cout << "deleting data " << tmp->data << std::endl;
        delete(tmp);
    }
};

template <class T>
bool LinkedList<T>::addNode(T data) {
    try {
        Node<T> * tmp = new Node<T>();
        tmp->data = data;
        tmp->next = head;
        head = tmp;
        ++size;
        return true;
    }
    catch (std::exception & ex) {
        return false;
    }
}

template <class T>
bool LinkedList<T>::deleteNode(T data) {
    Node<T> *current = head, *prev = NULL;

    while (current) {
        if (current->data == data)
            break;

        prev = current;
        current = current->next;
    }

    if (current) {
        if (prev)
            prev->next = current->next;
        else
            head = current->next;

        delete(current);
        --size;
        return true;
    }
    else {
        return false;
    }
}

template <class T>
Node<T> * LinkedList<T>::searchNode(T data) {
    Node<T> * tmp = head;
    while (tmp) {
        if (tmp->data == data) {
            return tmp;
        }
        tmp = tmp->next;
    }
    return NULL;
}



template <class T>
void LinkedList<T>::printList() {
    Node<T> * tmp = head;
    bool printNewLine = (tmp) ? true : false;
    while (tmp) {
        std::cout <<"("<< tmp->data.get_coff() << "," << tmp->data.get_exp() << ")";
        tmp = tmp->next;
        if(tmp)
            std::cout<<",";
    }

    if (printNewLine) {
        std::cout << std::endl;
    }
}

template <class T>
void LinkedList<T>::reverseList() {
    Node<T> *curr = head, *prev = head, *save = NULL;

    while (curr) {
        save = curr->next;
        curr->next = prev;
        prev = curr;
        curr = save;
    }

    head->next = NULL;
    head = prev;
}

int main() {
    LinkedList<Term> p, q, r;
    Term t1(5.0, 4), t2(3.0, 2), t3(9.0, 1);
    Term qt1(3.0, 7), qt2(7.0, 5), qt3(100.0, 1);

    p.addNode(t3);
    p.addNode(t2);
    p.addNode(t1);
    q.addNode(qt3);
    q.addNode(qt2);
    q.addNode(qt1);

    Node<Term> *p_ptr, *q_ptr ;
    p_ptr = p.get_head();
    q_ptr = q.get_head();



    /*cout << "coef: " << p_ptr->data.get_coff() << "exp: " << p_ptr->data.get_exp() << endl;
    p_ptr = p_ptr->next;
    cout << "coef: " << q_ptr->data.get_coff() << "exp: " << q_ptr->data.get_exp() << endl;
    q_ptr = q_ptr->next;*/

    int p_exp,q_exp;
    float p_coff,q_coff;

    while(1){
       if(p_ptr){
        p_exp=p_ptr->data.get_exp();
        p_coff=p_ptr->data.get_coff();
      }else{
        p_exp=-1;
        p_coff=0;
      }
      if(q_ptr){
        q_exp=q_ptr->data.get_exp();
        q_coff=q_ptr->data.get_coff();
      }
      else{
        q_exp=-1;
        q_coff=0;
      }

      cout<<p_exp << " " << q_exp <<endl;

    if(!p_ptr&&!q_ptr){
            break;
        }








        if(p_exp>q_exp){//else if exp of p_ptr>exp q_ptr
            Term rt(p_coff,p_exp) ;//copy the current term of p to r
            r.addNode(rt);

            p_ptr=p_ptr->next; //p_ptr=p_ptr->next
        }
        else if(q_exp>p_exp){
            Term rt(q_coff,q_exp) ;//copy the current term of p to r
            r.addNode(rt);

            q_ptr=q_ptr->next;
        }
        else if(p_exp==q_exp){
            if (p_coff + q_coff != 0){
                Term rt(p_coff+q_coff,p_exp) ;//copy the current term of p to r////add coef of p to coef of q //copy the resultant term in r
                r.addNode(rt);
            }

            p_ptr=p_ptr->next;

            q_ptr=q_ptr->next;
        }

    }
//this is not point to null
    p.printList();
    q.printList();
    r.reverseList();
    r.printList();
    //cout<<"x^0=1";
    return 0;
}
