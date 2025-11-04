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

| [![DSA_Journal](https://img.shields.io/badge/Back_to-DSA_Journal-000080?style=for-the-badge&logo=C&logoColor=white)](https://github.com/DeviprasadShetty9833/DSA_Journal) | [![Resources](https://img.shields.io/badge/📚_Back_to-Resources-A52A2A?style=for-the-badge&logo=book&logoColor=white)](https://github.com/DeviprasadShetty9833/Resources) |
|---|---|

---

# Djkistra Algorithm

📂 Source code to implement a Djkistra Algorithm ( file : [src.c](https://github.com/DeviprasadShetty9833/Djkistra_Algo/blob/443d58824dcc70d2ac21490bf013fe3cb622a85b/src/Djkistra.c) )


<table>  
<tr><td>  
  ⏺️ Dijkstra’s Algorithm is a greedy graph search method used to find the shortest path from a single source to all other nodes in a graph with non-negative edge weights.

  ⏺️ At each step, it selects the nearest unvisited node from the source.

  ⏺️ It records:
  - The shortest distance to each node.
  - The previous node for reconstructing the path.

 🟠 Key Points:
 - Works for both directed and undirected graphs.
 - All edge weights must be non-negative.

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
