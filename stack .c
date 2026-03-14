#include &lt;stdio.h&gt;
#define MAX 5
int stack[MAX];  
int top = -1;

int isFull() {
    return top == MAX - 1;
}
int isEmpty() {
    return top == -1;
}

void push(int val) {
    if (isFull()) {
        printf(&quot;Stack Overflow! Cannot push %d\n&quot;, val);
    } else {
        stack[++top] = val;
        printf(&quot;Pushed %d\n&quot;, val);
    }
}
void pop() {
    if (isEmpty()) {
        printf(&quot;Stack Underflow! Stack is empty\n&quot;);
    } else {
        printf(&quot;Popped %d\n&quot;, stack[top--]);
    }
}

int peek() {
    if (isEmpty()) {
        printf(&quot;Stack is empty\n&quot;);
        return -1;

    }
    return stack[top];
}
void display() {
    if (isEmpty()) {
        printf(&quot;Stack is empty\n&quot;);
        return;
    }
    printf(&quot;Stack elements: &quot;);
    for (int i = 0; i &lt;= top; i++) {
        printf(&quot;%d &quot;, stack[i]);
    }
    printf(&quot;\n&quot;);
}
int size() {
    return top + 1;
}
int main() {
    printf(&quot;=== Stack Implementation using Array ===\n\n&quot;);
   
    printf(&quot;Pushing elements: 10, 20, 30, 40, 50\n&quot;);
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
   
    printf(&quot;\nStack size: %d\n&quot;, size());
    display();
   
    printf(&quot;\nTop element (peek): %d\n&quot;, peek());
   
    printf(&quot;\nAttempting to push 60 (should fail - stack full):\n&quot;);
    push(60);
   
    printf(&quot;\nPopping 2 elements:\n&quot;);
    pop();
    pop();
   
    printf(&quot;\nStack after popping:\n&quot;);

    display();
    printf(&quot;Stack size: %d\n&quot;, size());
   
    printf(&quot;\nPopping remaining elements:\n&quot;);
    pop();
    pop();
    pop();
   
    printf(&quot;\nAttempting to pop from empty stack:\n&quot;);
    pop();
   
    return 0;
}
