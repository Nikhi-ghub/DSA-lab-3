#include &lt;stdio.h&gt;

void convertToSparse(int m, int n, int mat[10][10], int sparse[100][3]) {
    int i, j, k = 1;

    sparse[0][0] = m;
    sparse[0][1] = n;

    for (i = 0; i &lt; m; i++) {

        for (j = 0; j &lt; n; j++) {
            if (mat[i][j] != 0) {
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = mat[i][j];
                k++;
            }
        }
    }
    sparse[0][2] = k - 1;
}

void addSparse(int a[100][3], int b[100][3], int c[100][3]) {
    int i = 1, j = 1, k = 1;
    int t1 = a[0][2], t2 = b[0][2];

    if (a[0][0] != b[0][0] || a[0][1] != b[0][1]) {
        printf(&quot;Matrix addition not possible\n&quot;);
        return;
    }

    while (i &lt;= t1 &amp;&amp; j &lt;= t2) {
        if (a[i][0] &lt; b[j][0] ||
           (a[i][0] == b[j][0] &amp;&amp; a[i][1] &lt; b[j][1])) {
            c[k][0] = a[i][0];
            c[k][1] = a[i][1];
            c[k][2] = a[i][2];
            i++;
            k++;

        }
        else if (b[j][0] &lt; a[i][0] ||
                (b[j][0] == a[i][0] &amp;&amp; b[j][1] &lt; a[i][1])) {
            c[k][0] = b[j][0];
            c[k][1] = b[j][1];
            c[k][2] = b[j][2];
            j++;
            k++;
        }
        else {
            int sum = a[i][2] + b[j][2];
            if (sum != 0) {
                c[k][0] = a[i][0];
                c[k][1] = a[i][1];
                c[k][2] = sum;
                k++;
            }
            i++;
            j++;
        }
    }

    while (i &lt;= t1) {
        c[k][0] = a[i][0];
        c[k][1] = a[i][1];
        c[k][2] = a[i][2];
        i++;
        k++;
    }

    while (j &lt;= t2) {
        c[k][0] = b[j][0];
        c[k][1] = b[j][1];
        c[k][2] = b[j][2];
        j++;
        k++;
    }

    c[0][0] = a[0][0];
    c[0][1] = a[0][1];
    c[0][2] = k - 1;
}

void printSparse(int s[100][3]) {
    int i;
    printf(&quot;\nRow  Col  Val\n&quot;);
    for (i = 0; i &lt;= s[0][2]; i++) {
        printf(&quot;%d    %d    %d\n&quot;, s[i][0], s[i][1], s[i][2]);
    }
}

int main() {
    int m, n;
    int A[10][10], B[10][10];
    int SA[100][3], SB[100][3], SC[100][3];

    printf(&quot;Enter rows and columns: &quot;);
    scanf(&quot;%d %d&quot;, &amp;m, &amp;n);

    printf(&quot;\nEnter Matrix A:\n&quot;);
    for (int i = 0; i &lt; m; i++)
        for (int j = 0; j &lt; n; j++)
            scanf(&quot;%d&quot;, &amp;A[i][j]);

    printf(&quot;\nEnter Matrix B:\n&quot;);
    for (int i = 0; i &lt; m; i++)
        for (int j = 0; j &lt; n; j++)
            scanf(&quot;%d&quot;, &amp;B[i][j]);

    convertToSparse(m, n, A, SA);
    convertToSparse(m, n, B, SB);

    printf(&quot;\nSparse Matrix A:&quot;);
    printSparse(SA);

    printf(&quot;\nSparse Matrix B:&quot;);
    printSparse(SB);

    addSparse(SA, SB, SC);

    printf(&quot;\nResultant Sparse Matrix After Addition:&quot;);
    printSparse(SC);

    return 0;
}
