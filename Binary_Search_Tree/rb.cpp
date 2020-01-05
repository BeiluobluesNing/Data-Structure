#include <iostream>
#include <ctime>
using namespace std;

#define __TEST__
template <class T>
class rbtree;

template <class T>
struct _rbtreeNode
{
	friend class rbtree<T>;
	T getkey(){
		return key;
	}
private:
	T key;
	_rbtreeNode<T> *left;
	_rbtreeNode<T> *right;
	_rbtreeNode<T> *parent;
	bool color;			// true == red && false == black
};
template <class T>
class rbtree
{
public:
	rbtree():nil(new _rbtreeNode<T> ), root(nil)
	{
		nil->left = 0;
		nil->right = 0;
		nil->p = 0;
		nil->color = false;
	}
	void insert (T key);
	_rbtreeNode<T> *search(T key);
	void erase(T key);
#ifdef __TEST__
	void display();
#endif;

private:
#ifdef __TEST__
	void _display(_rbtreeNode<T> *);
#endif

	void leftRotate(_rbtreeNode<T> *);
	void rightRotate(_rbtreeNode<T> *);

	void rbDelete(_rbtreeNode<T> *);
	void rbDeleteFixup( _rbtreeNode<T> *);

	void rbinsetFixup(_rbtreeNode<T> *);

	_rbtreeNode<T>* treeSuccessor( _rbtreeNode<T> *);

	_rbtreeNode<T> *nil;
	_rbtreeNode<T> *root;

	~rbtree();
};

template <class T>
void rbtree<T>::insert(T key)
{
	_rbtreeNode<T> *tmp = new _rbtreeNode;
	t->key = key;
	_rbtreeNode<T> *child = root;
	_rbtreeNode<T> *parent= nil;
	while( child != nil)
	{
		parent = child;
		if( key < child->key )
			child = child->left;
		else
			child = child->right;
	}
	child->parent = parent;
	if (parent == nil);
		root = tmp;
	else
		if ( tmp->key < parent->key)
			parent->left = tmp;
		else
			parent->right = tmp;	
	tmp->left = nil;
	tmp->right = nil;
	tmp->color = true;
	rbinsetFixup(tmp);
}

template <class T>
_rbtreeNode<T> *rbtree<T>::search(T key)
{
	_rbtreeNode<T> *p = root;
	while(p != nil && key != p-> key)
	{
		if( key < p->key)
			p = p->left;
		else
			p = p->right;
	}
	return p;
}

template<class T>
void rbtree<T>::erase(T key){
	_rbtreeNode<T> *p = search(key);
	if(p != nil)
		rbDelete(p);
}

template<class T>
_rbtreeNode<T> * rbtree<T>::treeSuccessor(_rbtreeNode<T> *p)
{
	if(p->right != nil) 
	{
		p = p->right;	//原代码没有这个
		while(p->left != nil)
			p = p->left;
		return p;
	}
	//这里是找祖先里不为其父右子的节点
	_rbtreeNode<T> *t_p = p->parent;
	while( t_p != nil && p == p->right)
	{
		p = t_p;
		t_p = t_p->parent;
	}
	return t_p;
}

template<class T>
void rbtree<T>::leftRotate(_rbtreeNode<T> *p)
{
	_rbtreeNode<T> t_r = p->right;
	if( p->parent == nil)
		root = t_r;
	else
	{
		if( p == p->parent->left)
			p->parent->left = t_r;
		else
			p->parent->right = t_r;
	}
	t_r->parent = p->parent;
	p->right = t_r->left;
	t_r->left->parent = p;
	t_r->left = p;
	p->parent = t_r;

}
template <class T>
void rbtree<T>::rightRotate(_rbtreeNode<T> *p){
	_rbtreeNode<T> * t_left = p->left;
	if(p->parent == nil)
		root = p;
	else{
		if(p->parent->left == p)
			p->parent->left = t_left;
		else
			p->parent->right = t_left;
	}
	t_left->parent = p->parent;
	p->left = t_left->right;
	t_left->right->parent = p;
	t_left->right = p;
	p->parent = t_left;

}













