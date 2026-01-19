# LRU Cache System (C++)
This project implements a **Least Recently Used (LRU) Cache** using **C++**, designed to provide **O(1)** time complexity for both `get` and `put` operations.  
It simulates how real-world backend systems efficiently manage frequently accessed data.


## What is an LRU Cache?
An **LRU (Least Recently Used) Cache** stores recently accessed data in fast memory.  
When the cache reaches its capacity, it **automatically removes the data that has not been used for the longest time**.

This eviction strategy helps systems remain fast while using limited memory efficiently.


## Features
- O(1) time complexity for `get` and `put`
- Uses **Hash Map + Doubly Linked List**
- Automatically evicts least recently used entries
- Command-line based request simulation
- Displays cache hits, misses, and current cache state


## Design & Approach
The cache is implemented using two data structures:


#### 1. Hash Map
- Maps keys to nodes in the linked list
- Enables O(1) access to cache elements


#### 2. Doubly Linked List
- Maintains the order of usage
- Most recently used element is placed at the front
- Least recently used element is placed at the end

This combination ensures efficient updates and eviction.


## Supported Operations
- **put(key, value)**  
  Inserts or updates a key-value pair in the cache.  
  Evicts the least recently used item if capacity is exceeded.

- **get(key)**  
  Returns the value if the key exists (Cache Hit).  
  Returns `-1` if the key is not present (Cache Miss).

## Key–Value Representation
In this implementation:
- **Key** represents a unique identifier (e.g., product ID, request ID)
- **Value** represents associated data (e.g., price, count, or cached result)

- For example:
put 1 10
- stores:
Key = 1 ; Value = 10
#### Sample Commands
- put 1 10
- put 2 20
- get 1
- put 3 30
- get 2


## How to Run
```bash
g++ main.cpp -o lru
./lru

