#include "Tree.h"
int main()
{
    Tree<int> t;
    for (int i=0; i<7; i++)
        t.addElement(i);
    t.doInfixTraversal();
    Tree<int> t2;
    (t2 = move(t)).doInfixTraversal();
    cout<<'\n'<<"after = \n";
    t.doInfixTraversal();
    cout<<'\n';
    t2.doInfixTraversal();
    return 0;
}