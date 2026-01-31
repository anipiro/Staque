---

# Staque — Unique Integer Hybrid (Stack + Deque) using Doubly Linked List

## 📌 Description

**Staque** is a custom data structure that stores **only unique integers** and combines behaviors of a **stack (LIFO)** and a **deque (double-ended insertion)**.

* **Insertion depends on parity**

  * **Odd** numbers are inserted on the **left**
  * **Even** numbers are inserted on the **right**
* **Removal follows LIFO**

  * Regardless of where a value was inserted, the *last inserted value* is removed first
* Implemented strictly using a **doubly linked list**

---

## ✅ Core Rules

1. Only **unique integers** are stored (duplicates are ignored).
2. The structure is implemented with a **doubly linked list** (`prev` / `next`).
3. **Parity-based insertion**:

   * Even → right end
   * Odd → left end
4. **LIFO behavior** is respected for removal and “last inserted” access.

---

## 🧱 Functionality

### Get Last Inserted Value (Peek)

Returns the most recently inserted value without removing it.

---

### Search

Search behavior depends on the parity of the target value:

* **Even value search**

  * starts from the **right end**
  * traverses **only even values**
  * stops immediately if an odd value is encountered

* **Odd value search**

  * starts from the **left end**
  * traverses **only odd values**
  * stops immediately if an even value is encountered

This ensures that search never crosses into the opposite parity zone.

---

### Delete (with Default Arguments)

A single deletion function supports multiple deletion modes through default parameters.

#### Delete Even Values

* Deletes a specified number of **even values from the right end**
* If there are not enough even values, **nothing is deleted** and a message is printed

#### Delete Odd Values

* Deletes a specified number of **odd values from the left end**
* If there are not enough odd values, **nothing is deleted** and a message is printed

#### Delete Using LIFO

* Deletes a specified number of values following **LIFO order**
* If fewer values exist than requested:

  * all elements are deleted
  * a message is printed

The exact function signature and number of parameters are implementation-defined.

---

### Insert

Adds a new value only if it does not already exist:

* odd → inserted on the left
* even → inserted on the right
  Updates all links and LIFO tracking.

---

### Extract Only Evens / Only Odds

Returns a collection containing:

* only even values, or
* only odd values

Argument design is flexible (flag, enum, etc.).

---

### Copy Control (Rule of 3)

The structure properly implements:

* Copy constructor
* Assignment operator
* Destructor

This guarantees safe deep copying and correct memory management.

---

### Output Operator `<<`

Overloaded output operator prints the structure in a readable and organized format.

---

## 🧪 Driver Program (`main`)

The `main()` function demonstrates full functionality:

* Creates a `Staque` object and fills it with **50 random integers** in the range **[1, 100]**
* Demonstrates deletion in three scenarios:

  1. Deleting both odd and even values
  2. Deleting only odd values
  3. Deleting a fixed number of elements using LIFO
* Clearly shows the use of:

  * all methods
  * output operator
  * copy constructor
  * assignment operator
  * destructor behavior through object lifetime

---

## 📁 Suggested Project Structure

```
Staque/
│
├── Staque.h
├── Staque.cpp
├── main.cpp
└── README.md
```

---

## 🧠 Concepts Practiced

* Doubly linked list implementation
* Unique element enforcement
* Hybrid stack–deque behavior
* Parity-restricted traversal
* Default arguments in function design
* Copy control (Rule of 3)
* Operator overloading

---

## 📌 Notes

* Duplicate values are ignored during insertion.
* Search never crosses into the opposite parity.
* Deletion is atomic when requirements are not met:

  * even/odd deletion deletes nothing if insufficient values exist
  * LIFO deletion removes all elements if fewer than requested

---

