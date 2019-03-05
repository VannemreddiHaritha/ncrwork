#include<iostream>
#include<algorithm>
using namespace std;
struct node {
	int data;
	struct node *left, *right;

};
class BST {
	struct node *start;
public:
	BST();
	void insert(int);
	void delete_ele(int);
    void inorder();
	void preorder();
	void postorder();
	int findMax();
	int findMin();
	int height();
	int NLN();//number of leaf nodes
	int NNLN();//number of non leaf nodes
	~BST();
	friend void print_inorder(node *);
	friend void print_preorder(node *);
	friend void print_postorder(node *);
	friend node * insert1(node*, int);
	friend node *delete_ele1(int, node*);
	friend int findMax1(node *);
	friend int height1(node *);
	friend int NLN1(node *);
	friend int NNLN1(node*);
	 void delete_node(node *);
};
BST::BST()
{
	start = NULL;
}
int BST::NLN()
{
	    int x;
		x=NLN1(start);
		return x;
}
int NLN1(struct node*curr)
{
	if (curr == NULL)
		return 0;
	else if (curr->left != NULL && curr->right != NULL)
		return 1;
	else
	return(NLN1(curr->left) + NLN1(curr->right));
}
int BST::NNLN()
{
	int y = NNLN1(start);
}

	int NNLN1(struct node*curr)
	{
	if (curr == NULL)
		return 0;
	else if (curr->left != NULL && curr->right != NULL)
		return 0;
	else
	return(NNLN1(curr->left) + NNLN1(curr->right)+1);
}
int BST::findMin()
{
	if (start != NULL)
	{
		struct node *curr = start;
		while (curr->left != NULL)
			curr = curr->left;
		return curr->data;
	}
	return -1;

}
int BST:: findMax()
{
	if (start != NULL)
	{
		struct node *curr = start;
		while (curr->right!= NULL)
			curr = curr->right;
		return curr->data;
	}
	 return -1;
}
int findMax1(struct node *curr)
{
	if(curr!=NULL)
	{
		while (curr->right != NULL)
			curr = curr->right;
		return curr->data;
	}
	else return -1;

}
int BST::height()
{
	int n = height1(start);
}
int height1(struct node*curr)
{
	if (curr == NULL)
		return -1;
	else
		return(max(height1(curr->left),height1(curr->right)) + 1);
}
void BST::inorder()
{
	if (start != NULL)
		print_inorder(start);
}
void print_inorder(struct node*curr)
{
	if (curr != NULL)
	{
		print_inorder(curr->left);
		cout << curr->data;
		print_inorder(curr->right);
	}

}
void BST::preorder()
{
	if (start != NULL)
		print_inorder(start);
}
void print_preorder(struct node*curr)
{
	if (curr != NULL)
	{
		cout << curr->data;
		print_preorder(curr->left);
		print_preorder(curr->right);
	}

}
void BST::postorder()
{
	if (start != NULL)
		print_postorder(start);
}
void print_postorder(struct node*curr)
{
	if (curr != NULL)
	{
		cout << curr->data;
		print_postorder(curr->right);
		print_postorder(curr->left);
	}

}
void BST::delete_node(node *curr)
{
	if (curr != NULL)
	{
		delete_node(curr->left);
		delete_node(curr->right);
		delete curr;
	}
}
void BST::insert(int ele)
{
	start = insert1(start, ele);
}
node* insert1(struct node * curr,int ele)
{

	if (curr == NULL)
	{
		struct node *temp;
		temp = new node;
		temp->left = NULL;
		temp->right = NULL;
		return temp;
	}
	else 
	{
		if (ele < curr->data)
			curr->left = insert1( curr->left,ele);
		else
			curr->right = insert1(curr->right,ele);
		return curr;
	}
}
void BST::delete_ele(int ele)
{
	start = delete_ele1(ele, start);
}
node *delete_ele1(int ele, struct node *curr)
	{
	if (curr != NULL)
	{
		if (ele > curr->data)
			curr->right = delete_ele1(ele, curr->right);
		else
			curr->left = delete_ele1(ele, curr->left);
	}
	else
	{
		if (curr->left != NULL && curr->right != NULL)
		{
			curr->data = findMax1(curr->left);
			curr->left = delete_ele1(curr->data, curr->left);
		}
		else
		{
			struct node*temp;
		    temp = curr;
			if (curr->left == NULL)
				curr = curr->right;
			else
				curr = curr->left;
			delete temp;

		}
		return curr;
	}
}

BST::~BST()
{
	if (start != NULL)
		delete_node(start);
}
int main()
{
	BST b1;
	int choice;
	while (1)
	{
		cout << "1.insert element" << endl << "2.delete element" << endl << "3.find no.of leaf nodes" << endl << "4.find no.of non leaf nodes" << endl << "5.max element" << endl << "6.min element" << endl << "7.inorder" << endl << "8.post order" << endl << "9.pre order" << endl << "10.height" << endl<<"11.exit"<<endl;
		cout << "enter the choice"<<endl;
		cin >> choice;
		switch (choice)
		{
		case 1:int ele;
			cout << "enter the element";
			cin >> ele;
            b1.insert(ele);
			break;
		case 2:
			int ele;
			cout << "enter the element"<<endl;
			cin >> ele;
			b1.delete_ele(ele);
			break;
		case 3:int n;
			cout << "no.of leaf nodes"<<endl;
			n = b1.NLN();
			break;
		case 4:int n2;
			cout << "no.of non leaf nodes" << endl;
			n2 = b1.NNLN();
			break;
		case 5:int n3;
			cout << "maximum element" << endl;
             n3 = b1.findMax();
			break;
		case 6:int n3;
			cout << "minimum element" << endl;
			n3 = b1.findMin();
			break;
		case 7:cout << "inorder " << endl;
			b1.inorder();
			break;
		case 8:cout << "postorder " << endl;
			b1.postorder();
			break;
		case 9:
			cout << "preorder " << endl;
			b1.preorder();
			break;
		case 10:cout << "height " << endl;
			int n4;
			n4=b1.height();
		case 11:exit(0);
			break;
		default:cout << "invalid option";

		}
	}

	system("pause");
	return 0;
}