#include &lt;stdio.h&gt;
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

void enqueue(int value) {
    if (rear == SIZE - 1) {
        printf(&quot;Queue Overflow\n&quot;);
    } else {
        if (front == -1)
            front = 0;
        rear++;
        queue[rear] = value;
        printf(&quot;Inserted: %d\n&quot;, value);
    }
}

void dequeue() {
    if (front == -1 || front &gt; rear) {
        printf(&quot;Queue Underflow\n&quot;);
    } else {
        printf(&quot;Deleted: %d\n&quot;, queue[front]);
        front++;
    }
}

void search(int key) {
    if (front == -1 || front &gt; rear) {
        printf(&quot;Queue is empty\n&quot;);
        return;
    }

    for (int i = front; i &lt;= rear; i++) {
        if (queue[i] == key) {
            printf(&quot;Element %d found at position %d\n&quot;, key, i);
            return;
        }
    }

    printf(&quot;Element %d not found\n&quot;, key);
}

void display() {
    if (front == -1 || front &gt; rear) {
        printf(&quot;Queue is empty\n&quot;);
        return;
    }

    printf(&quot;Queue: &quot;);
    for (int i = front; i &lt;= rear; i++) {
        printf(&quot;%d &quot;, queue[i]);
    }
    printf(&quot;\n&quot;);
}

int main() {
    int choice, value;

    while (1) {
        printf(&quot;\n1.Enqueue 2.Dequeue 3.Search 4.Display 5.Exit\n&quot;);
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
