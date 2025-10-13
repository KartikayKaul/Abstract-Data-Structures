## Abstract Data Structures

A personal library of Data Structures and Algorithms implemented from scratch in **C++**.  
It may later be extended to **Python** or **C** for comparative learning.

I am actively working on this project to revisit and practice concepts from *CLRS*, *Coursera*, and other algorithmic resources.

---

### Navigation

| Section | Description |
|----------|-------------|
| [Data Structures](#data-structures) | Core ADT implementations (stack, queue, trees, graph, etc.) |
| [Miscellaneous](#miscellaneous) | Specialized or utility data structures (e.g., matrix) |
| [Algorithms](#algorithms) | (Planned) Common algorithms like sorting, searching, and traversal |
| [Updates](#updates) | Progress logs and change history |
| [Contribute](#contribute) | How to contribute or suggest improvements |


Below is the navigation for different readme files distributed throughout the repository for detailed guidance or notes on corresponding titular folder name.
| Readme Files |
|-------------|
| [Graphs](./ADT/graph/Readme.md)|
| [Miscellaneous](./ADT/graph/Readme.md)|
---

## Data Structures

All core data structures are organized under the [`ADT`](./ADT/) subfolder.

| Category | Description | Link |
|-----------|--------------|------|
| Stack | LIFO implementation with templated support | [View Folder](./ADT/stack/) |
| Queue | FIFO structure and variations | [View Folder](./ADT/queue/) |
| Priority Queue | Min/Max heap-like structure | [View pqueue.h](./ADT/pqueue.h) |
| Trees | Binary trees, BSTs, AVL trees, etc. | [View Folder](./ADT/trees/) |
| Graphs | Undirected and Directed graphs | [View Folder](./ADT/graph/) |

Each folder may contain its own `README.md` file with details, structure, and usage examples. Navigation for the readme files is provided [above](#navigation).

---

## Miscellaneous

Some data structures serve specific or utility purposes.

- [Matrix Data Structure](./ADT/miscellaneous/matrix/matrix.h): Implements linear algebra operations and matrix manipulations.  
- Additional structures are available in the [`miscellaneous`](./ADT/miscellaneous/) folder.

---

## Algorithms

This section will include algorithms implemented from *CLRS*, *Coursera*, and related resources.

Planned topics include:
- Sorting and Searching
- Graph Algorithms (UCS, A*, Dijkstra)
- Dynamic Programming
- Recursion and Divide & Conquer

Refer to the [Algorithms folder](./Algorithms/) once populated/created.

---

## Updates

| Timestamp | Description |
|------------|-------------|
| 1402240328 | Turned [pqueue](./ADT/pqueue.h) into a templated class for generality. Considering generalizing `uGraph` and `diGraph` next. |
| 11212022 | Implemented `dequeue()` in `pqueue`. Currently debugging element swapping logic. |
| 11162022 | Began implementing priority queue data structure for future graph search algorithms such as UCS and A*. |

---

## Contribute

I am expanding this repository as I continue revisiting data structure and algorithm concepts.  
Contributions, suggestions, and improvements are always welcome.

- Open issues to suggest new structures or algorithms.  
- Submit pull requests for code improvements or documentation updates.  
- Use the discussion section for guidance or collaboration.

