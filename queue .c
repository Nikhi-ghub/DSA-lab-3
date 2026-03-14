#include &lt;stdio.h&gt;
#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int value) {
    if (rear == MAX - 1) {
        return;
    }
    if (front == -1)
        front = 0;
    queue[++rear] = value;
}

void printQueue() {
    for (int i = front; i &lt;= rear; i++) {
        printf(&quot;%d &quot;, queue[i]);
    }
}

void reverseQueue() {
    int stack[MAX];

    int top = -1;

    for (int i = front; i &lt;= rear; i++) {
        stack[++top] = queue[i];
    }

    for (int i = front; i &lt;= rear; i++) {
        queue[i] = stack[top--];
    }
}

int main() {
    int capacity, value;

    scanf(&quot;%d&quot;, &amp;capacity);

    for (int i = 0; i &lt; capacity; i++) {
        scanf(&quot;%d&quot;, &amp;value);
        enqueue(value);
    }

    printf(&quot;Original queue: &quot;);
    printQueue();
    printf(&quot;\n&quot;);

    reverseQueue();

    printf(&quot;Reversed queue: &quot;);
    printQueue();

    return 0;
}
