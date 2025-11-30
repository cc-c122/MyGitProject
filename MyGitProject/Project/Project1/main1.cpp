#include<iostream>
using namespace std;

template<typename T>
struct TreeNode {
	T val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() :val(0), left(NULL), right(NULL) {}
	TreeNode(T d) :val(d), left(NULL), right(NULL) {}
};

template<typename T>
class Tree {
private:
	TreeNode<T>* nodes;
	TreeNode<T>* root;
	rsize_t nodeSize;
	TreeNode<T>* Creat(T a[], int size, int nodeID, T nullNode) {
		if (nodeID >= size || nodeID == nullNode) {
			return NULL;
		}
		TreeNode<T>* nowNode = GetTreeNode(nodeID);
		nowNode->val = a[nodeID];
		nowNode->left = creat(a, size, nodeID * 2, nullNode);
		nowNode->right = creat(a, size, nodeID * 2+1, nullNode);
		return nowNode;
	}
	void visit(TreeNode<T>* node) {
		cout << node->val;
	}
	void preOrder(TreeNode<T>* node) {
		if (node) {
			visit(node);
			preOrder(node->left);
			preOrder(node->right);
		}
	}
	void inOrder(TreeNode<T>* node) {
		if (node) {
			inOrder(node->left);
			visit(node);
			inOrder(node->right);
		}
	}
	void postOrder(TreeNode<T>* node) {
		if (node) {
			postOrder(node->left);
			postOrder(node->right);
			visit(node);
		}
	}
	void levelOrder(TreeNode<T>* node) {
		if (node) {
			visit(node);
			preOrder(node->left);
			preOrder(node->right);
		}
	}
public:
	Tree();
	Tree(int maxNodes);
	~Tree();
	TreeNode<T>* GetTreeNode(int id);
	void CreateTree(T a[], int size, T nullNode);
	void inOrderTraversal();
	void postOrderTraversal();
	void levelOrderTraversal();
};
template<typename T>
Tree<T>::Tree() {
	nodes = new TreeNode * [10000];
}

template<typename T>
Tree<T>::Tree(int maxNodes) {
	nodes = new TreeNode * [maxNodes];
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
void Tree<T>::CreateTree(T a[], int size, T nullNode) {
	root = Creat(a, size, 1, nullNode);
}

template<typename T>
void Tree<T>::inOrderTraversal() {
	preOrder(root);
}

template<typename T>
void Tree<T>::postOrderTraversal() {
	postOrder(root);
}

template<typename T>
void Tree<T>::inOrderTraversal() {
	inOrder(root);
}/

int main() {

	return 0;
}