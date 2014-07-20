##### *move assignment*?  When to use it?

Tied to the concept of rvalue-reference (or xvalue)

The move assignment operator is called whenever it is selected by overload resolution, e.g. when an object appears on the left side of an assignment expression, where the right-hand side is an rvalue of the same or implicitly convertible type.

Move assignment operators typically "steal" the resources held by the argument (e.g. pointers to dynamically-allocated objects, file descriptors, TCP sockets, I/O streams, running threads, etc), rather than make copies of them, and leave the argument in some valid but otherwise indeterminate state. For example, move-assigning from a std::string or from a std::vector leaves the right-hand side argument empty.

More http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2006/n2027.html#Move_Semantics

##### *std::move()*

Obtains an rvalue reference to its argument and converts it to an xvalue.

Code that receives such an xvalue has the opportunity to optimize away unnecessary overhead by moving data out of the argument, leaving it in a valid but unspecified state.

Basically it's just a cast:

```
template<typename _Tp>
constexpr typename std::remove_reference<_Tp>::type&& move(_Tp&& __t) noexcept
{
    return static_cast<typename std::remove_reference<_Tp>::type&&>(__t);
}
```
