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

<table>
<tr><td>

<br> ![1.](https://img.shields.io/badge/_1]_-Headers-000080?style=for-the-badge&logo=C&logoColor=white)   


*Code:*

```c

#include <stdio.h>   // For printf and scanf  
#include <stdlib.h>  // For exit()

```

*In Plain English:*

> "These are my toolkits. stdio.h helps me talk to you (input/output), and stdlib.h helps me quit when things go wrong."

</td></tr>  
</table>  

---

<table>
<tr><td>

<br> ![2.](https://img.shields.io/badge/_2]_-Define_Stack-000080?style=for-the-badge&logo=C&logoColor=white)   


*Code:*

```c

#define MAX 3   // Maximum size of the stack

typedef struct {
    int arr[MAX];   // Array to hold stack elements
    int top;        // Index of the top element
} Stack;

```

*Explanation:*

> - MAX defines the stack’s capacity.
> - arr[MAX] is the container holding stack elements.
> - top keeps track of where the top element is (starts at -1 when empty).

*Example:*

```html
MAX = 3 : arr[3]

        2 |_______|   \
        1 |_______|    |- arr
        0 |_______|   /
top -> -1
```

*In Plain English:*

> "Think of me as a stack of plates. arr is the plate rack, and top tells me which plate is on the very top. Initially, top = -1, meaning the rack is empty."

</td></tr>  
</table>  

---

<table>
<tr><td>

<br> ![3.](https://img.shields.io/badge/_3]_-Initialize_Stack-000080?style=for-the-badge&logo=C&logoColor=white)   

*Code:*

```c

void initStack(Stack *s) {
    s->top = -1;   // Empty stack
}

```

*Algorithm:*

```html

1. Set s->top = -1.

```
