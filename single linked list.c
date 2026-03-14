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

void insertFront(int value)
{
    int newNode = avail++;
    list[newNode].data = value;
    list[newNode].next = head;

    head = newNode;
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

int findMiddle()
{
    int slow = head;
    int fast = head;

    while (fast != -1 &amp;&amp; list[fast].next != -1)
    {
        slow = list[slow].next;
        fast = list[list[fast].next].next;
    }
    return list[slow].data;
}

int main()
{

    int n, i, x;

    scanf(&quot;%d&quot;, &amp;n);

    for (i = 0; i &lt; n; i++)
    {
        scanf(&quot;%d&quot;, &amp;x);
        insertFront(x);
    }

    display();

    printf(&quot;Middle Element: %d&quot;, findMiddle());

    return 0;
}
