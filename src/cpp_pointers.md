##### _pointers_
```
 ptr[offset] = *(ptr + offset);
&ptr[offset] = ptr + offset;
```

pointer arithmetic always adds in sizeof of the element
```
ptr[5] = *(ptr + 5) = *(ptr + 5 * sizeof(*ptr))
```
