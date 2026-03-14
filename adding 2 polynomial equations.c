#include &lt;stdio.h&gt;

int main() {
    int poly1[20][2], poly2[20][2], result[40][2];
    int n1, n2;
    int i = 0, j = 0, k = 0;

    printf(&quot;Enter number of terms in first polynomial: &quot;);
    scanf(&quot;%d&quot;, &amp;n1);

    printf(&quot;Enter terms of first polynomial (coefficient exponent):\n&quot;);
    for (i = 0; i &lt; n1; i++) {
        scanf(&quot;%d %d&quot;, &amp;poly1[i][0], &amp;poly1[i][1]);
    }

    printf(&quot;Enter number of terms in second polynomial: &quot;);
    scanf(&quot;%d&quot;, &amp;n2);

    printf(&quot;Enter terms of second polynomial (coefficient exponent):\n&quot;);
    for (j = 0; j &lt; n2; j++) {
        scanf(&quot;%d %d&quot;, &amp;poly2[j][0], &amp;poly2[j][1]);
    }

    i = 0;
    j = 0;
    k = 0;

    while (i &lt; n1 &amp;&amp; j &lt; n2) {
        if (poly1[i][1] &gt; poly2[j][1]) {
            result[k][0] = poly1[i][0];
            result[k][1] = poly1[i][1];
            i++;
            k++;
        }
        else if (poly1[i][1] &lt; poly2[j][1]) {
            result[k][0] = poly2[j][0];

            result[k][1] = poly2[j][1];
            j++;
            k++;
        }
        else {
            result[k][0] = poly1[i][0] + poly2[j][0];
            result[k][1] = poly1[i][1];
            i++;
            j++;
            k++;
        }
    }

    while (i &lt; n1) {
        result[k][0] = poly1[i][0];
        result[k][1] = poly1[i][1];
        i++;
        k++;
    }

    while (j &lt; n2) {
        result[k][0] = poly2[j][0];
        result[k][1] = poly2[j][1];
        j++;
        k++;
    }

    printf(&quot;\nResultant Polynomial after Addition:\n&quot;);
    for (i = 0; i &lt; k; i++) {

        printf(&quot;%dx^%d&quot;, result[i][0], result[i][1]);
        if (i != k - 1)
            printf(&quot; + &quot;);
    }

    printf(&quot;\n&quot;);
    return 0;
}
