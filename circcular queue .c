#include &lt;stdio.h&gt;
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

int isFull() {
    return (front == (rear + 1) % SIZE);
}

int isEmpty() {
    return (front == -1);
}

void enqueue(int value) {
    if (isFull()) {
        printf(&quot;Queue is Full\n&quot;);
        return;
    }

    if (isEmpty())
        front = rear = 0;
    else
        rear = (rear + 1) % SIZE;

    queue[rear] = value;
    printf(&quot;Inserted: %d\n&quot;, value);
}

void dequeue() {
    if (isEmpty()) {
        printf(&quot;Queue is Empty\n&quot;);
        return;
    }

    printf(&quot;Deleted: %d\n&quot;, queue[front]);

    if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % SIZE;
}

void search(int key) {
    if (isEmpty()) {
        printf(&quot;Queue is Empty\n&quot;);
        return;
    }

    int i = front;
    int found = 0;
    int pos = 1;

    while (1) {
        if (queue[i] == key) {
            printf(&quot;Element %d found at position %d\n&quot;, key, pos);
            found = 1;

            break;
        }
        if (i == rear) break;
        i = (i + 1) % SIZE;
        pos++;
    }

    if (!found)
        printf(&quot;Element not found\n&quot;);
}

void display() {
    if (isEmpty()) {
        printf(&quot;Queue is Empty\n&quot;);
        return;
    }

    int i = front;
    printf(&quot;Queue: &quot;);

    while (1) {
        printf(&quot;%d &quot;, queue[i]);
        if (i == rear) break;
        i = (i + 1) % SIZE;
    }
    printf(&quot;\n&quot;);
}

int main() {

    int choice, value;

    while (1) {
        printf(&quot;\n--- Circular Queue Menu ---\n&quot;);
        printf(&quot;1. Enqueue\n&quot;);
        printf(&quot;2. Dequeue\n&quot;);
        printf(&quot;3. Search\n&quot;);
        printf(&quot;4. Display\n&quot;);
        printf(&quot;5. Exit\n&quot;);
        printf(&quot;Enter choice: &quot;);
        scanf(&quot;%d&quot;, &amp;choice);

        switch (choice) {
            case 1:
                printf(&quot;Enter value: &quot;);
                scanf(&quot;%d&quot;, &amp;value);
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                printf(&quot;Enter element to search: &quot;);
                scanf(&quot;%d&quot;, &amp;value);
                search(value);
                break;

            case 4:
                display();
                break;

            case 5:
                return 0;

            default:
                printf(&quot;Invalid choice\n&quot;);
        }
    }
}
