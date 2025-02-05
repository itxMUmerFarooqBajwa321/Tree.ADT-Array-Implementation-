#ifndef TREE_H
#define TREE_H
#include <iostream>
#include <vector>
using namespace std;
template <typename T>
class Tree
{
    vector<T> * data;
public:
    Tree(vector<T> * =nullptr);
    Tree(const Tree &);
    Tree(Tree &&);
    void addElement(const T & );
    void doPostFixTraversal(unsigned int=0)const;
    void doPreFixTraversal(unsigned int =0) const;
    void doInfixTraversal(unsigned int =0) const;
    Tree operator = (Tree &&);
    Tree operator = (const Tree & );
    bool operator ! () const;
    ~Tree();
};
template <typename T>
Tree<T>::Tree(vector<T> * d):data(nullptr)
{
    if(d)
        data=d;
}
template <typename T>
Tree<T>::Tree(const Tree<T> & ref):Tree()
{
    if( ! ref)
    {
        cout<<"Tree(const Tree<T> &) returns ";
        return;
    }
    data=new vector<T>;
    int s = ref.data->size();
    for(int j=0; j<s; j++)
    {
        data->push_back(ref.data->at(j));
    }
}
template <typename T>
bool Tree<T>::operator ! ()const
{
    if(!data)
        return true;
    return (data->size()) ? false:true;
}
template <typename T>
Tree<T>::Tree(Tree<T> && ref):Tree()
{
    if( ! ref)
    {
        cout<<"Tree(Tree<T> &&) returns ";
        return;
    }
    data = ref.data;
    ref.data= nullptr;
}
template <typename T>
void Tree<T>::addElement(const T & ele)
{
    if(! (*this) )
        data=new vector<T>;
    data->push_back(ele);
}
template <typename T>
void Tree<T>::doPostFixTraversal(unsigned int index)const
{
    if(!(*this))
        return;
    if(index >= data->size())
        return;
    doPostFixTraversal(2*index+1);
    doPostFixTraversal(2*index+2);
    cout<< data->at(index)<<' ';
}
template <typename T>
void Tree<T>::doPreFixTraversal(unsigned int index) const
{
    if(!(*this))
        return;
    if(index>= data->size())
        return;
    cout<<data->at(index)<<' ';
    doPreFixTraversal(2*index+1);
    doPreFixTraversal(2*index+2);
}
template <typename T>
void Tree<T>::doInfixTraversal(unsigned int index) const
{
    if(!(*this))
        return;
    if(index>=data->size())
        return;
    doInfixTraversal(2*index+1);
    cout<<data->at(index)<<' ';
    doInfixTraversal(2*index+2);
}
template <typename T>
Tree<T> Tree<T>::operator = (Tree<T> && ref)
{
    this->~Tree();
    if(!ref)
        return *this;
    data= ref.data;
    ref.data= nullptr;
    return *this;
}
template <typename T>
Tree<T> Tree<T>::operator = (const Tree<T> & ref)
{
    this->~Tree();
    if(!ref)
        return *this;
    data= new vector<T>;
    int siz = ref.data->size();
    for(int i=0; i<siz; i++)
        data->push_back(ref.data->at(i));
    return *this;
}
template<typename T>
Tree<T>::~Tree()
{
    if(!this || !(*this))
        return;
    delete data;
    data=nullptr;    
}
#endif
