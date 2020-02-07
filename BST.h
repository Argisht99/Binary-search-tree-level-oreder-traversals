#pragma once
#include "BSTD.h"

template <class T>
inline void bst<T>::insert(T key)
{
	if (root == nullptr)
	{
		root = new node(key);
		return;
	}
	node* ptr = root;
	while (true)
	{
		if (ptr->data > key)
		{
			if (ptr->left == nullptr)
			{
				ptr->left = new node(key);
				return;
			}
			else
			{
				ptr = ptr->left;
			}
		}
		else
		{
			if (ptr->right == nullptr)
			{
				ptr->right = new node(key);
				return;
			}
			else
			{
				ptr = ptr->right;
			}
		}
	}

}

template<class T>
inline bool bst<T>::find(T key)
{
	if (root == nullptr)
	{
		return false;
	}
	node* ptr = root;
	while (true)
	{
		if (ptr->data > key)
		{
			if (ptr->data == key)
			{
				return true;

			}
			else if (ptr->left != nullptr)
			{
				ptr = ptr->left;
			}

			else
			{
				return false;
			}

		}
		else
		{
			if (ptr->data == key)
			{
				return true;
			}
			else if (ptr->right != nullptr)
			{
				ptr = ptr->right;
			}

			else
			{
				return false;
			}
		}
	}
}
template<class T>
void bst<T>::remove(T key)
{
	if (root == nullptr)
	{
		std::cout << "Don't have a Elememt \n";
		return;
	}
	node* ptr = root;

	DeleteNodeInBST(ptr, key);
}

//template<class T>
//inline void bst<T>::remove(T key)
//{
//	node* ptr = findefordeletion(key);
//
//	if (ptr == nullptr)
//	{
//		std::cout << "don't have a Element \n";
//		return;
//	}
//
//	if (ptr->left == nullptr && ptr->right == nullptr)
//	{
//		std::cout << "Element deleted \n";
//		delete ptr;
//		ptr = nullptr;
//	}
//	else if (ptr->left && ptr->right == nullptr)
//	{
//		node* dptr = ptr;
//		ptr = ptr->left;
//		std::cout << "element deleted \n";
//		delete dptr;
//		dptr = nullptr;
//	}
//	else if (ptr->left != nullptr && ptr->right)
//	{
//		node* dptr = ptr;
//		ptr = ptr->right;
//		std::cout << "Element Deleted \n";
//		delete dptr;
//		dptr = nullptr;
//	}
//	else if (ptr->left && ptr->right)
//	{
//		//coming soon
//	}
//}

template<class T>
inline void bst<T>::printpreorder()
{
	printppreorder(root);
}

template<class T>
inline void bst<T>::printpostorder()
{
	printppostorder(root);
}

template<class T>
inline void bst<T>::printinorder()
{
	printiinorder(root);
}

//template<class T>
//inline void bst<T>::printlevelorder(node* root)
//{
//	std::queue<node*> que;
//	que.push(root);
//
//	node* ptr = nullptr;
//	//int i = 0;
//	while (que.size() > 0)
//	{
//		//i = 0;
//		ptr = que.front();
//		que.pop();
//
//		std::cout << ptr->data << " ";
//
//		if (ptr->left != nullptr)
//		{
//			que.push(ptr->left);
//			//++i;
//		}
//		
//
//		if (ptr->right != nullptr)
//		{
//			que.push(ptr->right);
//			//++i;
//		}
//		
//	}
//}

template<class T>
inline void bst<T>::printlevelorder()
{

	printllevelorder(root);

}
