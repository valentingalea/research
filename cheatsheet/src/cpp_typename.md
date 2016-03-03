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
