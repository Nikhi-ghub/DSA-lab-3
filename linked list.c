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

void insertEnd(int value)
{
    int newNode = avail++;
    list[newNode].data = value;
    list[newNode].next = -1;

    if (head == -1)
    {
        head = newNode;
    }
    else
    {
        int temp = head;
        while (list[temp].next != -1)
        {
            temp = list[temp].next;
        }
        list[temp].next = newNode;
    }
}

void display()
{
    int temp = head;
    while (temp != -1)
    {
        printf(&quot;%d &quot;, list[temp].data);
        temp = list[temp].next;
    }
}

int main()
{
    int n, i, roll;

    scanf(&quot;%d&quot;, &amp;n);

    for (i = 0; i &lt; n; i++)
    {
        scanf(&quot;%d&quot;, &amp;roll);
        insertEnd(roll);
    }

    display();

    return 0;
}
