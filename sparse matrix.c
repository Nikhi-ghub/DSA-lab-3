#include &lt;stdio.h&gt;

int main() {
    int mat[10][10];
    int sp[20][3], tr[20][3];
    int rows, cols;
    int i, j, k = 1, t = 1;

    printf(&quot;Enter number of rows and columns:\n&quot;);
    scanf(&quot;%d %d&quot;, &amp;rows, &amp;cols);

   
    printf(&quot;Enter matrix elements:\n&quot;);
    for (i = 0; i &lt; rows; i++) {
        for (j = 0; j &lt; cols; j++) {
            scanf(&quot;%d&quot;, &amp;mat[i][j]);
        }
    }
    printf(&quot;\nNormal Matrix:\n\n&quot;);

    printf(&quot;        &quot;);
    for (j = 0; j &lt; cols; j++) {
        printf(&quot;Col %d  &quot;, j + 1);
    }
    printf(&quot;\n&quot;);

    for (i = 0; i &lt; rows; i++) {
        printf(&quot;Row %d   &quot;, i + 1);
        for (j = 0; j &lt; cols; j++) {
            printf(&quot;%3d    &quot;, mat[i][j]);
        }
        printf(&quot;\n&quot;);
    }
    sp[0][0] = rows;
    sp[0][1] = cols;
    sp[0][2] = 0;
    for (i = 0; i &lt; rows; i++) {
        for (j = 0; j &lt; cols; j++) {
            if (mat[i][j] != 0) {
                sp[k][0] = i + 1;
                sp[k][1] = j + 1;      
                sp[k][2] = mat[i][j];  
                k++;
                sp[0][2]++;
            }
        }
    }
    printf(&quot;\nSparse Matrix (Triplet Form: row column value):\n&quot;);
    for (i = 0; i &lt;= sp[0][2]; i++) {

        printf(&quot;%d %d %d\n&quot;, sp[i][0], sp[i][1], sp[i][2]);
    }

    tr[0][0] = sp[0][1];
    tr[0][1] = sp[0][0];
    tr[0][2] = sp[0][2];
    for (i = 1; i &lt;= sp[0][1]; i++) {
        for (j = 1; j &lt;= sp[0][2]; j++) {
            if (sp[j][1] == i) {
                tr[t][0] = sp[j][1];
                tr[t][1] = sp[j][0];
                tr[t][2] = sp[j][2];
                t++;
            }
        }
    }
    printf(&quot;\nTranspose Sparse Matrix (Triplet Form):\n&quot;);
    for (i = 0; i &lt;= tr[0][2]; i++) {
        printf(&quot;%d %d %d\n&quot;, tr[i][0], tr[i][1], tr[i][2]);
    }

    return 0;
}
