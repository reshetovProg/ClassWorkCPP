#pragma once
#include <iostream>
using namespace std;

template <typename T>
struct Node {
	T value;
	Node<T>* left = nullptr;
	Node<T>* right = nullptr;
	Node<T>* parent = nullptr;
};

template <typename T>
class BinaryTree
{
private:
	Node<T>* root = nullptr;
	int count = 0;

	void showAll(Node<T>* el) {
		cout << el->value<<" ";
		if (el->left!= nullptr) showAll(el->left);
		if (el->right != nullptr) showAll(el->right);
	}
	

public:
	void add(T value) {
		
		Node<T>* newNode = new Node<T>{ value };
		if (root == nullptr) {
			root = newNode;
			count++;
			return;
		}
		Node<T>* buf = root;
		while (true) {
			if (value > buf->value) {
				if (buf->right == nullptr) {
					buf->right = newNode;
					newNode->parent = buf;
					break;
				}
				buf = buf->right;
			}
			else {
				if (buf->left == nullptr) {
					buf->left = newNode;
					newNode->parent = buf;
					break;
				}
				buf = buf->left;
			}
		}
		count++;
	}

	//Node<T>* getEl(Node<T>* el, T value) {
	//	if (el->value == value) 
	//		return el;
	//	else {
	//		if (el->left != nullptr) getEl(el->left, value);
	//		if (el->right != nullptr) getEl(el->right, value);
	//	}

	//}

	//Node<T>* getEl(T value) {
	//	if (root != nullptr) 
	//		return getEl(root, value);
	//}

	void show() {
		if (root!=nullptr) showAll(root);
	}

	

	void smallLeftRotate(){//Node<T>* supportEl) {
		Node<T>* el1 = root;
		Node<T>* el2 = el1->right;
		Node<T>* el3 = el2->left;
		root = el2;
		root->parent = el1->parent;
		el2->left = el1;
		el1->parent = el2;
		el1->right = el3;
		el3->parent = el1;
	}

	void smallRightRotate() {//Node<T>* supportEl) {
		Node<T>* el1 = root;
		Node<T>* el2 = el1->left;
		Node<T>* el3 = el2->right;
		root = el2;
		root->parent = el1->parent;
		el2->right = el1;
		el1->parent = el2;
		el1->left = el3;
		el3->parent = el1;
	}




};

