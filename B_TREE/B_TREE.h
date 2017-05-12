#ifndef B_TREE_H
#define B_TREE_H

template <typename T>
struct Node{
	struct Node* left;
	struct Node* right;
	T data;
};

template <typename T>
class B_TREE {
	struct Node<T>* head;
public:
	B_TREE(){
		head = nullptr;
	}
	B_TREE(struct Node<T>* head_ = nullptr) : head(head_){
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
	void add_item(T item){
		Node<T>* node = &head;
		if (!head){
			head->data = item;
			return;
		}
		while(node){
			if (node->right && node->left){
				if(item < node->data)
					node = node->left;
				else
					node = node->right;
			}
			else if (!node->left){
				node->left = new Node<T>;
				node = node->left;
				node->data = item;
				return;
			}else if (!node->right){
				node->right = new Node<T>;
				node = node->right;
				node->data = item;
				return;
			}
		}
	}
};

#endif