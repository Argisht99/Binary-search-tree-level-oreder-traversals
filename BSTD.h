#pragma once
#include <iostream>
#include <queue>

template<class T>
class bst
{
public:
	struct node
	{
		node(T data, node* left = nullptr, node* right = nullptr) : data(data), left(left), right(right) {}


	private:

		node* left;
		node* right;
		T data;
		friend class bst;

	};

public:
	void insert(T key);
	bool find(T key);
	void remove(T key);
	//node* DeleteNodeInBST(node* root, T data);
	void printpreorder();
	void printpostorder();
	void printinorder();
	void printlevelorder();

public:
	node* root = nullptr;
	unsigned int left_size;
	unsigned int right_size;

private:
	node* FindMax(node* root)
	{
		if (root == nullptr)
			return nullptr;

		while (root->right != nullptr)
		{
			root = root->right;
		}
		return root;
	}
	
	node* DeleteNodeInBST(node* root, T data)
	{
		if (root == nullptr)
		{
			return root;
		}
		else if (data < root->data)
		{
			root->left = DeleteNodeInBST(root->left, data);
		}
		else if (data > root->data)
		{
			root->right = DeleteNodeInBST(root->right, data);
		}
		else
		{
			//No child
			if (root->right == nullptr && root->left == nullptr)
			{
				delete root;
				root = nullptr;
			}
			//One child 
			else if (root->right == nullptr)
			{
				node* temp = root;
				root = root->left;
				delete temp;
			}
			else if (root->left == nullptr)
			{
				node* temp = root;
				root = root->right;
				delete temp;
			}
			//two child
			else
			{
				node* temp = FindMax(root->left);
				root->data = temp->data;
				root->left = DeleteNodeInBST(root->left, temp->data);
			}
		}
		return root;
+-  	}

	node* findefordeletion(T key)
	{
		if (root == nullptr)
		{
			return nullptr;
		}

		node* ptr = root;
		while (true)
		{
			if (ptr->data < key)
			{
				if (ptr->data == key)
				{
					return ptr;
				}
				else if (ptr->right != nullptr)
				{
					ptr = ptr->right;
				}
				else
				{
					return nullptr;
				}
			}
			else if (ptr->data >= key)
			{
				if (ptr->data == key)
				{
					return ptr;
				}
				else if (ptr->left != nullptr)
				{
					ptr = ptr->left;
				}
				else
				{
					return nullptr;
				}
			}
			else
			{
				return nullptr;
			}
		}


	}

	void printllevelorder(node* root)
	{
		node* ptr = root;

		std::queue<node*> que;
		que.push(ptr);

		while (que.size() > 0)
		{
			ptr = que.front();
			que.pop();

			std::cout << ptr->data << "\n";

			if (ptr->left != nullptr)
			{
				que.push(ptr->left);
			}

			if (ptr->right != nullptr)
			{
				que.push(ptr->right);
			}
		}

	}

	void printppreorder(node* ptr)
	{
		if (ptr == nullptr)
		{
			return;
		}
		std::cout << ptr->data << "\n";
		printppreorder(ptr->left);
		printppreorder(ptr->right);
	}
	void printppostorder(node* ptr)
	{
		if (ptr == nullptr)
		{
			return;
		}

		printppostorder(ptr->left);
		printppostorder(ptr->right);
		std::cout << ptr->data << "\n";
	}

	void printiinorder(node* ptr)
	{
		if (ptr == nullptr)
		{
			return;
		}
		printiinorder(ptr->left);
		std::cout << ptr->data << "\n";
		printiinorder(ptr->right);
	}

};
