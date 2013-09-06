#### STL

##### containers speed

Container | Implementation   | Insert   | Remove   | Index  | Find
--------- | ---------------- | -------- | -------- | ------ | -------
vector    | dynamic array    | O(n)     | O(n)     | O(1)   | O(log n)
list      | double link list | O(1)     | O(1)     | -      | O(n)
map       | red-black b tree | O(log n) | O(log n) | O(1)   | O(log n)
hashmap   | hash table       | O(1)     | O(1)     | O(1)   | O(1)
