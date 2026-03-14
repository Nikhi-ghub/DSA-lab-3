#include &lt;stdio.h&gt;

#define MAX 100

struct Node
{
    int data;
    int next;
};

struct Node list[MAX];
int head = -1;
int avail = 0;

void insertBegin(int value)
{
    int newNode = avail++;
    list[newNode].data = value;
    list[newNode].next = head;
    head = newNode;
}

void reverseList()
{
    int prev = -1;
    int curr = head;
    int next;

    while (curr != -1)
    {
        next = list[curr].next;
        list[curr].next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

void display()
{
    int temp = head;
    while (temp != -1)
    {
        printf(&quot;%d &quot;, list[temp].data);
        temp = list[temp].next;
    }
    printf(&quot;\n&quot;);
}

int main()
{
    int n, i, x;

    scanf(&quot;%d&quot;, &amp;n);

    for (i = 0; i &lt; n; i++)
    {
        scanf(&quot;%d&quot;, &amp;x);
        insertBegin(x);
    }

    display();
    reverseList();
    display();

    return 0;
}
