#### Quaternions
alternative mathematical entity similar to complex number and are of the form:
```
Q = a + bi + cj + dk
```

##### Conjugate
```
Q* = a - bi - ck - dk
```

##### Norm
```
norm(Q) = sqrt(Q Q*) = sqrt(a^2 + b^2 + c^2 + d^2)
```

##### Inverse (or Reciprocal)
```
inv(Q) = Q* / norm(Q)^2
```

##### Multiplication
Hamilton product:
```
A B =
	 a1b1 - a2b2 - a3b3 - a4b4   +
	(a1b2 + a2b1 + a3b4 - a4b3)i +
	(a1b3 + a2b4 + a3b1 + a4b2)j +
	(a1b4 + a2b3 - a3b2 + a4b1)k
```

Quaternions can be interpreted as a scalar plus a vector by writing Q = (s, V). Multiplication is easy then:
```
Q V = (s1, V1) (s2 V2) = (s1 s2 - V1 . V2, s1 V2 + s2 V1 + V1 x V2)
```

##### Unit quaternions or *versors*
provide a convenient mathematical notation for representing orientations and rotations of objects in three dimensions. Compared to Euler angles they are simpler to compose and avoid the problem of gimbal lock. Compared to rotation matrices they are more numerically stable and may be more efficient.

A rotation about the unit vector N by an angle *theta* can be computed using the quaternion: (due to generalized Euler formula)
```
Q = (s, V) = (cos theta/2, sin theta/2 N)
rotated P = (0, P) Q = Q P inv(Q) = Q P Q*
```

##### Rotate vector example
1. Compute the matrix product of a 3x3 rotation matrix R and the original 3x1 column matrix representing v. This requires 3 x (3 multiplications + 2 additions) = 9 multiplications and 6 additions, the most efficient method for rotating a vector.

2. A rotation can be represented by a unit-length quaternion Q = (w, R) with scalar (real) part w and vector (imaginary) part R. The rotation can be applied to a 3D vector V via the formula:
```
V' = V + 2R x (R x V + wV)
```
This requires only 15 multiplications and 15 additions to evaluate. This yields the same result as the less efficient but more compact formula:
```
V' = Q V inv(Q)
```

##### SLERP
http://run.usc.edu/cs520-s12/assign2/p245-shoemake.pdf
http://number-none.com/product/Understanding%20Slerp,%20Then%20Not%20Using%20It/
