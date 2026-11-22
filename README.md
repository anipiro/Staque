# Staque

A C++ container of unique integers built on a doubly linked list: odd values go in at the left end, even values at the right end, and the last value added can be read or removed like a stack. Written for a university assignment.

Identifiers and console messages are Georgian written in Latin letters. The class is spelled `Staquee` in the code.

## What it does

- **Add.** `add(value)` puts an odd value at the left end and an even value at the right end. It returns `false` and changes nothing if the value is already stored.
- **Last added.** `getLastAdded()` returns the most recently added value without removing it. On an empty staque it throws `std::runtime_error`.
- **Search by parity.** `search(value)` starts from the right end for an even value and from the left end for an odd one, and stops as soon as it meets a value of the other parity.
- **Remove.** `remove(evens, odds, total)` has three modes, picked by which argument is positive: remove that many even values from the right end, that many odd values from the left end, or that many values in last-in, first-out order.
- **Read one parity.** `getValues(true)` returns the even values as a `std::vector<int>`, `getValues(false)` the odd ones, both in left-to-right order.
- **Copy and print.** Copy constructor, copy-and-swap assignment, destructor, and `operator<<`, which prints `Staque [a, b, c]`.

## How it works

Each `Elementi` node holds a value, the two list links and a sequence number taken from a counter that goes up on every successful `add`. `Staquee` keeps pointers to the left end, the right end and the node added last.

Because odd values are only ever added on the left and even values only on the right, all odd values sit to the left of all even values. That is why a search can stop at the first value of the other parity.

All three arguments of `remove` default to 0 and exactly one must be positive, otherwise it prints a message and removes nothing. If there are fewer even or odd values than asked for, nothing is removed. If `total` is larger than the size, everything is removed. Removing the node added last makes the staque scan for the remaining node with the highest sequence number.

| Operation | Cost |
| --- | --- |
| `add` | O(n), from the scan for duplicates |
| `getLastAdded`, `isEmpty`, `getZoma` (size) | O(1) |
| `search`, `getValues`, `getEvenCount`, `getOddCount` | O(n) |
| `remove` | O(n) for each value removed |

## Example

Consistent with `main()` in `staque1.cpp`:

```cpp
Staquee s;
s.add(5);
s.add(10);
s.add(15);
s.add(20);              // list order is now 15, 5, 10, 20
s.add(10);              // false, already stored

s.getLastAdded();       // 20
s.search(10);           // true
cout << s << endl;

s.remove(1);            // one even value from the right end
s.remove(0, 1);         // one odd value from the left end
s.remove(0, 0, 1);      // the value added last
```

`main()` fills a staque with 50 distinct random values from 1 to 100, then shows search, copying, assignment, the three removal modes and the error cases.

## Build and run

The repository is a Visual Studio solution: open `staque1.slnx` and run it. With g++:

```
g++ -std=c++17 staque1/staque1.cpp -o staque
./staque
```
