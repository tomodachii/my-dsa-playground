# Introduction
## Mathematical sets:
- Abstract.
- **Static** (unchanging).

## Sets managed by algorithms:
- Can grow, shrink, or otherwise change over time.
- Such sets are called **dynamic**.
- Dynamic set objects may have an identifying **key** field that uniquely identifies the object.

# Elements of a Dynamic Set:
- Each element of a dynamic set is represented by an object.
- The object has attributes that can be examined and manipulated given a pointer to the object.
- Some kinds of dynamic sets assume that one of the object's attribute is an identifying **key**.
- The object may contain both attributes that are manipulated by set operations and __satellite data__ (for example, if the dynamic sets represetns a set of students, the __satellite data__ might include name, age, grade, ect.), which are carried around in other object attributes but are unused by the set implementation.

# Operations on dynamic sets
Can be grouped into two categories:
- **queries**, which simply return information about the set.
- **modifying operations**, which change the set.

Typical operations. Specific application will usually require only a few of this to be implemented:

### SEARCH(S, k)
- A **query**.
- Given a set **S** and a key value **k**.
- Returns a pointer **x** to an element in **S** such that $x.key = k$, or **NIL** if no such element belongs to **S**.

### INSERT(S, k)
- A **modifying operation**.
- Adds the element pointed to by **x** to the set **S**.
- Note that attributes that needed by the set implementation in **x** should have already been initialized.

### DELETE(S, x)
- A **modifying operation**.
- Given the pointer **x** to an element in set **S**.
- Removes **x** from **S**.
- Note that this operation takes a pointer not a key value.

Below are operations for a totally ordered set implementation (**S** is an ordered set).
### MINIMUM(S)
- A **Query**.
- Given a totally ordered set **S**.
- Returns a pointer to the elment of **S** with the __smallest key__.

### MAXIMUM(S)
- A **Query**.
- Given a totally ordered set **S**.
- Returns a pointer to the elment of **S** with the __largest key__.

### SUCCESSOR(S, x)
- A **Query**.
- Given a totally ordered set **S** and an element **x** in **S**.
- Returns a pointer to the __next larger element__ in **S**, or **NIL** if **x** is the __maximum element__.

### SUCCESSOR(S, x)
- A **Query**.
- Given a totally ordered set **S** and an element **x** in **S**.
- Returns a pointer to the __next smaller element__ in **S**, or **NIL** if **x** is the __minimum element__.

# Array
A dynamic set (ofc) can be implement with an array.

Advantages:
- The algorithms for the dynamic set operations are simple.

Disadvantages:
- If the array is not sorted, INSERT and DELETE can take $\Theta(1)$