#include &lt;stdio.h&gt;

#define MAX 100

int stack[MAX];
int top = -1;

void push(int item) {
    stack[++top] = item;
}

int pop() {

    return stack[top--];
}

int main() {
    char postfix[MAX];
    int i = 0, val1, val2, result;

    printf(&quot;Enter postfix expression (e.g., 53+ for 5+3): &quot;);
    scanf(&quot;%s&quot;, postfix);

    while (postfix[i] != &#39;\0&#39;) {
        char ch = postfix[i];

        if (ch &gt;= &#39;0&#39; &amp;&amp; ch &lt;= &#39;9&#39;) {
            push(ch - &#39;0&#39;);
        }
        else {
            val2 = pop(); // Second operand
            val1 = pop(); // First operand

            switch (ch) {
                case &#39;+&#39;: result = val1 + val2; break;
                case &#39;-&#39;: result = val1 - val2; break;
                case &#39;*&#39;: result = val1 * val2; break;
                case &#39;/&#39;: result = val1 / val2; break;
            }
            push(result);
        }
        i++;

    }

    printf(&quot;Evaluation Result: %d\n&quot;, pop());
    return 0;
}
