# Djkistra_Algo

<br> ![Author: Deviprasad Shetty](https://img.shields.io/badge/Author-💫_Deviprasad%20Shetty-000000?style=for-the-badge&labelColor=white)
<br> 


# My Intro:
<br> Hi, 😃👋 I'm Deviprasad Shetty, highly passionate for coding, learning and exploring new fields in Computer Science domain. 
<br> I'm excited 😃 to dive deeper into my technical skills, collaborate with others, and take on projects that challenge me to grow. 
<br> Always eager to learn and connect with others who share similar interests! 🤗🧑‍💻
<br> 
| [![LinkedIn](https://img.shields.io/badge/LinkedIn-%230077B5?style=for-the-badge&logo=LinkedIn&logoColor=white)](https://linkedin.com/in/deviprasad-shetty-4bba49313) | [![Website](https://img.shields.io/badge/Website-indigo?style=for-the-badge&logo=About.me&logoColor=white)](https://yourwebsite.com/) | [![My Portfolio](https://img.shields.io/badge/My_Portfolio-000?style=for-the-badge&logo=GitHub&logoColor=white)](https://github.com/DeviprasadShetty9833/My_Portfolio)  |                      
|---|---|---|
<br> 

---

| [![DSA_in_C_Tutorial](https://img.shields.io/badge/Back_to-DSA_in_C_Tutorial-000080?style=for-the-badge&logo=C&logoColor=white)](https://github.com/DeviprasadShetty9833/DSA_in_C_Tutorial) | [![Resources](https://img.shields.io/badge/📚_Back_to-Resources-A52A2A?style=for-the-badge&logo=book&logoColor=white)](https://github.com/DeviprasadShetty9833/Resources) |
|---|---|

---

# Djkistra Algorithm

📂 Source code to implement a Djkistra Algorithm ( file : [src.c](https://github.com/DeviprasadShetty9833/Djkistra_Algo/blob/443d58824dcc70d2ac21490bf013fe3cb622a85b/src/Djkistra.c) )

Of course! Here are detailed, point-by-point notes on Dijkstra's Algorithm, covering everything from its core concept to its complexities and limitations.

### **1. Introduction & Core Concept**

*   **Purpose:** Dijkstra's Algorithm is a **graph search algorithm** that solves the **single-source shortest path problem** for a graph with **non-negative edge weights**.
*   **Objective:** It finds the shortest path from a designated **starting node (source node)** to **all other nodes** in the graph.
*   **Output:** The algorithm produces two key pieces of information for each node:
    1.  The **shortest distance** from the source node to that node.
    2.  The **previous node** that leads to this shortest path, allowing the entire path sequence to be reconstructed.
*   **Greedy Nature:** It is a **greedy algorithm**. At each step, it chooses the node that appears to be closest to the source, and this local optimal choice leads to a global optimum for the problem.

---

### **2. Key Requirements & Assumptions**

*   **Non-Negative Weights:** This is the most critical requirement. **All edge weights must be zero or positive.** The algorithm fails if negative weights are present because it cannot re-evaluate a node once it is "closed" or processed, and a negative edge could create a shorter path later.
*   **Directed or Undirected:** The algorithm works on both directed and undirected graphs. For undirected graphs, an edge between A and B is treated as two directed edges (A->B and B->A).

---

### **3. The Algorithm: Step-by-Step Procedure**

Let's define:
*   `graph`: The graph structure (e.g., adjacency list).
*   `start`: The source node.
*   `dist`: An array where `dist[node]` stores the current shortest known distance from `start` to `node`. Initialize `dist[start] = 0` and all others to **infinity**.
*   `prev`: An array to store the predecessor of a node in the shortest path. Initialize all to `null` or `undefined`.
*   `visited` (or `processed`): A set to keep track of all nodes whose shortest distance has been definitively found.
*   `priority_queue`: A min-priority queue that stores nodes based on their current `dist` value. The node with the smallest `dist` is always at the front.

**Steps:**

1.  **Initialization:**
    *   Set `dist[source] = 0`.
    *   Set `dist[v] = Infinity` for all other nodes `v`.
    *   Set `prev[v] = null` for all nodes `v`.
    *   Add all nodes to the `priority_queue`. (Alternatively, you can start by adding only the source node).

2.  **Main Loop:** While the `priority_queue` is not empty:
    a.  **Extract Minimum:** Remove the node `u` from the `priority_queue` that has the smallest `dist[u]`. This node is now being processed.
    b.  **Mark as Visited:** Add `u` to the `visited` set. The shortest distance to `u` is now considered final.
    c.  **Explore Neighbors:** For each unvisited neighbor `v` of `u`:
        *   Calculate a **tentative distance**: `tentative_dist = dist[u] + weight(u, v)`.
        *   **Relaxation:** If this `tentative_dist` is **less than** the current `dist[v]`:
            *   **Update:** Set `dist[v] = tentative_dist`.
            *   **Update Predecessor:** Set `prev[v] = u`.
            *   **Update Queue:** If using a mutable queue, decrease the key/priority of `v` in the `priority_queue`. If not, you may need to re-add it with the new priority.

3.  **Termination:** The algorithm ends when the `priority_queue` is empty. At this point, `dist[]` contains the shortest distances from the source to every node, and `prev[]` can be used to backtrack and reconstruct the actual paths.

---

### **4. A Simple Walkthrough with an Example**

Consider a graph with nodes A (source), B, C, D.

*   Edges: A->B (4), A->C (2), B->C (1), B->D (5), C->D (8)

| Step | Node Processed | Priority Queue (Node: dist) | Distance Array (A, B, C, D) | Action                                                              |
| :--- | :------------- | :-------------------------- | :--------------------------- | :------------------------------------------------------------------ |
| 0    | -              | A:0, B:∞, C:∞, D:∞          | [0, ∞, ∞, ∞]                 | Initialization.                                                     |
| 1    | **A** (0)      | C:2, B:4, D:∞               | [0, 4, 2, ∞]                 | Process A. Update neighbors B and C.                                |
| 2    | **C** (2)      | B:3, D:10                   | [0, 3, 2, 10]                | Process C. Path to B via C (2+1=3) is shorter. Update B and D.      |
| 3    | **B** (3)      | D:8                         | [0, 3, 2, 8]                 | Process B. Path to D via B (3+5=8) is shorter than 10. Update D. |
| 4    | **D** (8)      | (empty)                     | [0, 3, 2, 8]                 | Process D. No unvisited neighbors. Algorithm complete.              |

**Final Shortest Distances from A:** A=0, B=3, C=2, D=8.

---

### **5. Time Complexity**

The time complexity depends heavily on the data structure used for the priority queue.

*   **Using a Simple Array (or List):**
    *   Finding the min: O(V)
    *   Doing this for all V nodes: O(V²)
    *   Updating neighbors (Relaxation): O(E)
    *   **Total Complexity: O(V²)**
    *   This is efficient for **dense graphs** (where E is close to V²).

*   **Using a Binary Min-Heap:**
    *   Finding/Extracting min: O(log V)
    *   Doing this for all V nodes: O(V log V)
    *   Updating (Decreasing key) a neighbor's distance: O(log V)
    *   Doing this for all E edges: O(E log V)
    *   **Total Complexity: O((V + E) log V)**
    *   This is efficient for **sparse graphs** (where E is much less than V²). This is the most common implementation.

*   **Using a Fibonacci Heap:**
    *   Extract-Min: O(log V) amortized.
    *   Decrease-Key: O(1) amortized.
    *   **Total Complexity: O(E + V log V)**
    *   This is theoretically the best for graphs with a very large number of vertices and edges.

---

### **6. Space Complexity**

*   **O(V):** To store the `dist` and `prev` arrays.
*   **O(V):** For the priority queue, which can hold all V nodes.
*   **O(E):** To store the graph itself (e.g., adjacency list).
*   **Total: O(V + E)**

---

### **7. Why It Fails with Negative Weights**

Dijkstra's algorithm fails with negative-weight edges because of its **greedy nature**.

*   Once a node is marked as "visited" and processed, its shortest distance is considered final.
*   However, a negative edge weight elsewhere in the graph could create a new, shorter path to a node that has already been processed.
*   The algorithm has no mechanism to "re-open" a processed node to find a better path.

**Example:**
Nodes: A (source), B, C.
Edges: A->B (4), A->C (5), B->C (-3).
*   Dijkstra will process A, set B=4 and C=5. It will then process B (the closest), and then mark C as done with cost 5.
*   However, the path A->B->C has a total cost of 4 + (-3) = **1**, which is cheaper. But the algorithm will never find this because C was already finalized.

For graphs with negative weights, use the **Bellman-Ford algorithm**.

---

### **8. Applications**

Dijkstra's algorithm is fundamental in computer science and has countless real-world applications:
*   **Network Routing Protocols:** Like OSPF (Open Shortest Path First) for finding the best path in a network.
*   **Google Maps / GPS Navigation Systems:** Finding the shortest or fastest route between two locations.
*   **Telephone Networks:** For routing calls through the least costly path.
*   **Social Networks:** Finding the degree of separation between people (if all weights are 1, it becomes BFS).
*   **In File Transfer Protocols:** To find the path with the least traffic or latency.

---

### **9. Pseudocode (using a Min-Heap)**

```python
import heapq

def dijkstra(graph, start):
    n = len(graph)
    dist = [float('inf')] * n
    prev = [None] * n
    dist[start] = 0
    
    # Priority queue: (distance, node)
    pq = [(0, start)]
    
    while pq:
        current_dist, u = heapq.heappop(pq)
        
        # If we found a better path to `u` already, skip processing.
        if current_dist > dist[u]:
            continue
            
        for v, weight in graph[u]:
            new_dist = dist[u] + weight
            # Relaxation step
            if new_dist < dist[v]:
                dist[v] = new_dist
                prev[v] = u
                heapq.heappush(pq, (new_dist, v))
                
    return dist, prev
```

<table>  
<tr><td>  
  ⏺️ A stack is a linear data structure that follows the LIFO (Last In, First Out) principle.

  ⏺️ The stack has a maximum size, and operations must check for overflow (too many elements) and underflow (trying to pop from an empty stack).

<details>  
  <summary>Click to expand 🔻</summary>  
<br> 🟠 Basic Operations:

```html

- Push (insert an element) onto the top of the stack unless the stack is full.

- Pop (remove an element) from the top of the stack unless the stack is empty.

- Peek (get top element) the top element without removing it unless the stack is empty.

- Display (print all elements in stack order)

```

<br> 🟠 Applications:

```html

- Expression evaluation (postfix/prefix).

- Undo/Redo in editors.

- Function call management in recursion.

- Browser forward/backward navigation.

```

<br> 🟠 Advantages:

```html

- Easy to implement with arrays or linked lists.

- Ensures controlled access order.

```

</details>  

</td></tr>  
</table>  

---

*Example:*

```html

Vertices - 7 (A, B, C, D, E, F, G)
Edges - 11
Weights / Distance : AC - 3 , CD - 4 , DB - 1 , BG - 2 , GF - 2 , FA - 2 , CF - 2 , CE - 1 , FE - 3 , EB - 2 , FB - 6  

    C ------- D
 /  |  \        \
A   |   E ------ B
\   |   /     / /
 \  |  /   /  /
  \ | / /    /
    F ---- G


Source - u , Vertex - v , Visited vertices - VV

1]
u = A
v = C , F
VV = A

select F


```


<table>
<tr><td>

<br> ![1.](https://img.shields.io/badge/_1]_-Headers-000080?style=for-the-badge&logo=C&logoColor=white)   


*Code:*

```c

#include <stdio.h>
#include <limits.h>

#define MAX 100
#define INF INT_MAX

```

*In Plain English:*

> "These are my toolkits. stdio.h helps me talk to you (input/output), and stdlib.h helps me quit when things go wrong."

</td></tr>  
</table>  

---

<table>
<tr><td>

<br> ![4.](https://img.shields.io/badge/_4]_-Push_Operation-000080?style=for-the-badge&logo=C&logoColor=white)   

*Code:*

```c

void push(Stack *s, int data) {
    if (s->top == MAX - 1) {
        printf("Stack Overflow! Cannot push %d\n", data);
        return;
    }
    s->arr[++(s->top)] = data;
    printf("%d pushed into stack\n", data);
}

```

*Algorithm:*

```html

1. Check if stack is full → if yes, print “Overflow”.
2. Increment top.
3. Place data at arr[top].

```

*Example:*

```html

Before push: [ ] (top = -1)

Push 10 → arr[0] = 10, top = 0
Push 20 → arr[1] = 20, top = 1

Stack: [10, 20] (20 is on top)

```

*In Plain English:*

> "I check if the rack is full. If not, I place your plate on the top and move the marker up. Voilà — plate stacked!"

</td></tr>  
</table>  

---
