struct Node {
	int data;
	Node* left;
	Node* right;
};
	
void inorderTraversal(Node* node) {
	if(!node)
		return;

	if(node->left)
		inorderTraversal(node->left);

	std::cout << node->data << std::endl;

	if(node->right)
		inorderTraversal(node->right);
}

void postorderTraversal(Node* node) {
	if(!node)
		return;

	if(node->left)
		postorderTraversal(node->left);

	if(node->right)
		postorderTraversal(node->right);

	std::cout << node->data << std::endl;
}
