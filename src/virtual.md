#### C++ virtual

##### What is a *virtual* function? 
A virtual function allows derived classes to replace the implementation provided by the base class.

When you refer to a derived class object using a pointer or a reference to the base class, you can call a virtual function for that object and execute the derived class's version of the function. Virtual functions ensure that the correct function is called for an object, regardless of the expression used to make the function call

##### *pure* virtual function
A virtual function that is required to be implemented by a derived class.

Classes containing pure virtual methods are termed "abstract"; they cannot be instantiated directly.

##### virtual *destructor* - when/why?
At the root of a class hierarchy to insure proper cleanup

##### virtual call in *assembly*
```
mov eax, dword ptr [this]
mov edx, dword ptr [eax]
mov eax, dword ptr [edx+4]
mov ecx, dword ptr [this]
call eax
```

##### co-variant return types

http://katyscode.wordpress.com/2013/08/22/c-polymorphic-cloning-and-the-crtp-curiously-recurring-template-pattern/
