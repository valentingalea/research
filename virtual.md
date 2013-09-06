#### C++ virtual

##### What is a *virtual* function? 
A virtual function allows derived classes to replace the implementation provided by the base class.

When you refer to a derived class object using a pointer or a reference to the base class, you can call a virtual function for that object and execute the derived class's version of the function.

Virtual functions ensure that the correct function is called for an object, regardless of the expression used to make the function call

