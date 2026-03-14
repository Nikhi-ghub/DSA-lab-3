#include &lt;stdio.h&gt;

#define MAX 100

char stack[MAX];
int top = -1;

void push(char item) {

    stack[++top] = item;
}

char pop() {
    if (top == -1) return -1;
    return stack[top--];
}

int precedence(char ch) {
    if (ch == &#39;^&#39;) return 3;
    if (ch == &#39;*&#39; || ch == &#39;/&#39;) return 2;
    if (ch == &#39;+&#39; || ch == &#39;-&#39;) return 1;
    return 0;
}

int isOperand(char ch) {
    return (ch &gt;= &#39;0&#39; &amp;&amp; ch &lt;= &#39;9&#39;) || (ch &gt;= &#39;a&#39; &amp;&amp; ch &lt;= &#39;z&#39;) || (ch &gt;= &#39;A&#39; &amp;&amp; ch &lt;=
&#39;Z&#39;);
}

int main() {
    char infix[MAX], postfix[MAX];
    int i = 0, j = 0;

    printf(&quot;Enter infix expression: &quot;);
    scanf(&quot;%s&quot;, infix);

    while (infix[i] != &#39;\0&#39;) {
        char item = infix[i];

        if (isOperand(item)) {
            postfix[j++] = item;
        } else if (item == &#39;(&#39;) {
            push(item);
        } else if (item == &#39;)&#39;) {
            char temp = pop();
            if (temp == -1) { // Stack was empty, no matching &#39;(&#39;
                printf(&quot;Error: Mismatched parentheses (Extra closing bracket)\n&quot;);
                return 1;
            }
            while (temp != &#39;(&#39;) {
                postfix[j++] = temp;
                temp = pop();
            }
        } else {
            while (top != -1 &amp;&amp; precedence(stack[top]) &gt;= precedence(item)) {
                postfix[j++] = pop();
            }
            push(item);
        }
        i++;
    }

    while (top != -1) {
        char temp = pop();
        if (temp == &#39;(&#39;) {
            printf(&quot;Error: Mismatched parentheses (Missing closing bracket)\n&quot;);
            return 1;

        }
        postfix[j++] = temp;
    }

    postfix[j] = &#39;\0&#39;;
    printf(&quot;Postfix Expression: %s\n&quot;, postfix);
    return 0;
}
