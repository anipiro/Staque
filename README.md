

# Staque Data Structure

## Overview

**Staque** is a custom data structure designed to store **only unique integers**.
It combines characteristics of a **stack (LIFO)** and a **deque**, while being implemented entirely using a **doubly linked list**.

The structure enforces special rules based on whether values are **odd or even**, both during insertion and search.

---

## Core Rules

* Only **unique integers** are allowed (duplicates are ignored).
* The structure is implemented using a **doubly linked list**.
* **Odd numbers** are inserted on the **left end**.
* **Even numbers** are inserted on the **right end**.
* Removal of elements follows the **LIFO (Last In, First Out)** principle.

---

## Main Operations

### Insert

* Inserts a value only if it does not already exist.
* Odd values are inserted on the left.
* Even values are inserted on the right.
* Updates the internal LIFO tracking order.

---

### Get Last Inserted Value

* Returns the most recently inserted value.
* Does not remove the value from the structure.

---

### Search

Search behavior depends on the parity of the searched value:

* Searching for an **even value**:

  * Starts from the **right end**
  * Traverses **only even values**
  * Stops immediately if an odd value is encountered

* Searching for an **odd value**:

  * Starts from the **left end**
  * Traverses **only odd values**
  * Stops immediately if an even value is encountered

The search never crosses into the opposite parity.

---

### Delete (with Default Arguments)

A single delete function supports multiple deletion modes:

* Delete a given number of **even values** from the right end
* Delete a given number of **odd values** from the left end
* Delete a given number of values using **LIFO order**

Behavior rules:

* If there are not enough values for even/odd deletion, nothing is deleted.
* If LIFO deletion requests more values than exist, all elements are deleted.
* Informative messages are printed for each case.

The exact function signature is implementation-defined.

---

### Extract Only Evens or Only Odds

* Returns a collection containing only even values **or** only odd values.
* Argument design is flexible (flag, enum, etc.).

---

### Copy Control

The structure correctly implements:

* Copy constructor
* Assignment operator
* Destructor

This ensures safe memory management and deep copying.

---

### Output Operator

The output operator (`<<`) is overloaded to print the contents of the structure in a readable format.

---

## Driver Program (main)

The `main()` function demonstrates full functionality:

* Creates a `Staque` object
* Fills it with **50 random integers** in the range `[1, 100]`
* Demonstrates deletion in three scenarios:

  * deleting both odd and even values
  * deleting only odd values
  * deleting a fixed number of elements using LIFO
* Clearly shows usage of:

  * all methods
  * output operator
  * copy constructor
  * assignment operator
  * destructor behavior through object lifetime

---

## Project Structure

```
Staque/
│
├── Staque.h
├── Staque.cpp
├── main.cpp
└── README.md
```


---

## Concepts Demonstrated

* Doubly linked list implementation
* Unique element enforcement
* Hybrid stack and deque behavior
* Parity-restricted traversal logic
* Default arguments in function design
* Rule of Three
* Operator overloading

---

## Notes

* Duplicate values are ignored during insertion.
* Search operations are strictly parity-based.
* Deletion operations behave atomically when requirements are not met.

---

