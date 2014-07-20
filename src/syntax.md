#### C++ syntax notes

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

##### *in place* new
Allows to explicitly specify the memory management of individual objects, i.e. their "placement" in memory.

new (expression) <type> [(arguments)]; for example:

```
char buffer[] = new char[256];
string *str = new (buffer) string("Hello world");
```

there is no placement delete syntax (but both _new_ and _delete_ functions can be overrided to specify the in-place)

##### *typename* keyword

1. alias for the *class* keyword when declaring template parameters
2. a method to indicate that a dependent name is a type

If the compiler can't tell if a dependent name (one that contains a template parameter) is a value or a type, then it will assume that it is a value.

```
template <typename T>
void foo() {
   T::bar * p; // won't compile, because without the typename prefix it will be interpreted as a multiplication
}
 
struct Gotcha {
   typedef int bar;
};

foo<Gotcha>();
```

##### SFINAE

If an error occurs during the substitution of a set of arguments for any given template, the compiler removes the potential overload from the candidate set instead of stopping with a compilation error

http://en.wikipedia.org/wiki/SFINAE

##### Meyers Singleton

```
static Singleton& Instance()
{
  static Singleton theSingleton; // initialized at first function call
  return theSingleton;
}
```

##### Alignment

general: (last mod is for offset = 0 to work)

    new_offset = offset + padding = offset + (align - (offset mod align)) mod align

power-of-2:

    new_offset = (offset + align - 1) & ~(align - 1)
