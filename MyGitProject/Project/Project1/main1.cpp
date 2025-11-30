#include<iostream>
using namespace std;

template<typename T>
struct ListNode {
	T date;
	ListNode* next;
	ListNode(T d) :date(d), next(NULL) {}
};

template<typename T>
struct TreeNode {
	T data;
	ListNode<TreeNode<T>*>* childrenHead;

	void AddChild(TreeNode<T>* node) {
		ListNode<TreeNode<T>*>* ChildNode = new ListNode<TreeNode<T>*>(node);
		if (childrenHead == NULL) {
			childrenHead = ChildNode;
		}
		else {
			ChildNode->next = childrenHead;
			childrenHead = ChildNode;
		}
	}
};

template<typename T>
class Tree {
private:
	TreeNode<T>* nodes;
	TreeNode<T>* root;
public:
	Tree();
	Tree(int maxNodes);
	~Tree();
	TreeNode<T>* GetTreeNode(int id);
	void SetRoot(int id);
	void AddChild(int parentID, int sonID);
	void AssignDate(int nodeID, T date);
	void Print(TreeNode<T>* node = NULL);
};

template<typename T>
Tree<T>::Tree() {
	nodes = new TreeNode<T>[1000];
	root = NULL;
}

template<typename T>
Tree<T>::Tree(int maxNodes) {
	nodes = new TreeNode<T>[maxNodes];
	root = NULL;
}

template<typename T>
Tree<T>::~Tree() {
	delete[] nodes;
}

template<typename T>
TreeNode<T>* Tree<T>::GetTreeNode(int id) {
	return &nodes[id];
}

template<typename T>
void Tree<T>::SetRoot(int id) {
	root = GetTreeNode(id);
}

template<typename T>
void Tree<T>::AddChild(int parentID, int sonID) {
	TreeNode<T>* parentNode = GetTreeNode(parentID);
	TreeNode<T>* sonNode = GetTreeNode(sonID);
	parentNode->AddChild(sonNode);
}

template<typename T>
void Tree<T>::AssignDate(int ID, T data) {
	GetTreeNode(ID)->data = data;
}

template<typename T>
void Tree<T>::Print(TreeNode<T>* node) {
	if (node == NULL) {
		node = root;
	}
	cout << node->data;
	ListNode<TreeNode<T>*>* tmp = node->childrenHead;
	while (tmp) {
		print(tmp);
		tmp = tmp->next;
	}
}/

int main() {

	return 0;
}