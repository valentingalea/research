##### *static* - all the different meanings?
1. at _file scope_: signifies "internal-linkage" i.e. not shared between translation units
2. at _function scope_: variable retains value between function calls
3. at _class scope_: signifies independence of class instance

##### *const* and *mutable*
Const member function doesn't alter the data it operates on; except the one marked as _mutable_

##### *volatile* keyword
Depends on language and compiler. Usually marks _atomicity_ for data (but not guarantees it): reads from threads are guaranteed to have latest; marks that variable can be modified "externally"

##### *restrict* keyword
Optimisation hint to limit pointer aliasing and aid caching - it means a particular data is accessed only thru that pointer thus making optimisations like storing the ptr value in a registry for subsequent access

http://stackoverflow.com/questions/776283/what-does-the-restrict-keyword-mean-in-c

##### *in place* new
Allows to explicitly specify the memory management of individual objects, i.e. their "placement" in memory.

new (expression) <type> [(arguments)]; for example:

```
char buffer[] = new char[256];
string *str = new (buffer) string("Hello world");
```

there is no placement delete syntax (but both _new_ and _delete_ functions can be overrided to specify the in-place)
