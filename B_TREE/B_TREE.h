#ifndef B_TREE_H
#define B_TREE_H

template <typename T>
struct Node<T>{
	Node<T>* left;
	Node<T>* right;
	T data;
};

template <typename T>
class B_TREE {
	Node<T>* head;
public:
	B_TREE(Node<T>* head_) : head(head_){
		head->left = nullptr;
		head->right = nullptr;
	}
	B_TREE(B_TREE &other){
		head = other.head;
	}
	B_TREE &operator=(B_TREE &other){
		head = other.head;
		return *this;
	}
	Node<T>* add_item(T);
};

#endif