Repository contains implementation code for Tree abstract data type (ADT) with help of array for storing tree data. 
Defualt way to create instance of ADT is also provided by giving definition of defualt ctor.
An object of tree can be created by providing vector with data elements using ctor with adress of that vector as argument.
ADT contains copy and move constructors to create an instance with contents same to another passing object and to create instance by moving contents of passing temporary object in order to enhance time and space complexity.
Simple assignment operator = and move assignment operators are also redefined for this ADT to avoid shallow copy behavior of default assignment operator.
The ! opertaor is defined to give result for bool isEmpty() const method.
A method addElement is defined to add nodes in Tree<T> instance. It takes an object of T type.
For traversal of Tree ADT three all methods of tree traversal are defined, ie. prefix, infix and postfix traversals.
Definition of destructor is also provided to release all resources just before the death/destruction of obejct or whenever it is needed.
