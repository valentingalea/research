### C++ syntax notes

##### *static* - all the different meanings?
1. at _file scope_: signifies "internal-linkage" i.e. not shared between translation units
2. at _function scope_: variable retains value between function calls
3. at _class scope_: signifies independence of class instance

##### *const* and *mutable*
Const member function doesn't alter the data it operates on; except the one marked as _mutable_

##### default *copy constructor* and *assignment operator* - when to override?
Rule of 3 in C++03 / Rule of 5 in C++11
When the class needs to be copy/move assignable - that is when it needs to be _cloneable_ i.e. has non-shareable data

##### *volatile* keyword
Depends on language and compiler. Usually marks _atomicity_ for data (but not guarantees it): reads from threads are guaranteed to have latest; marks that variable can be modified "externally"

##### *restrict* keyword
http://stackoverflow.com/questions/776283/what-does-the-restrict-keyword-mean-in-c

Optimisation hint to limit pointer aliasing and aid caching - it means a particular data is accessed only thru that pointer thus making optimisations like storing the ptr value in a registry for subsequent access
