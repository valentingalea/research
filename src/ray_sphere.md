#### Ray-Sphere intersection
Given a ray defined by origin **O** and direction **d**
```
	ray(t) = O + td, t >= 0
```
and a sphere of center **C** and radius **r**, for which a point **P** lies on the surface if
```
	(P - C)(P - C) = r^2
```
you plug the ray definition into this equation, turning it into a quadratic one one; if it has real roots then the ray intersected the sphere.

http://wiki.cgsociety.org/index.php/Ray_Sphere_Intersection
http://en.wikipedia.org/wiki/Line%E2%80%93sphere_intersection
