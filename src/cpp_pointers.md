##### _pointers_
```
 ptr[offset] = offset[ptr] = *(ptr + offset) = *(offset + ptr);
&ptr[offset] = ptr + offset;
```

pointer arithmetic always adds in sizeof of the element
```
ptr[5] = *(ptr + 5) = *(ptr + 5 * sizeof(*ptr))
```

that's why this works
```
int array[] = { ... };
1[&array] - array; // gets the number of elements
```
because &array is a type that increments in the sizeof of the whole array
