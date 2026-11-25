#include <stdio.h>
#include <stdlib.h>

int **cr(int r, int c)
{
    int **a;
    int i;

    a = (int **)malloc(r * sizeof(int *));
    if (a == NULL)
        return NULL;

    for (i = 0; i < r; i++) {
        a[i] = (int *)malloc(c * sizeof(int));
        if (a[i] == NULL) {
            while (i > 0) {
                i--;
                free(a[i]);
            }
            free(a);
            return NULL;
        }
    }

    return a;
}

void fr(int **a, int r)
{
    int i;

    if (a == NULL)
        return;

    for (i = 0; i < r; i++)
        free(a[i]);

    free(a);
}

void t933()
{
    int n, m;
    int **a;
    int i, j, k, t;

    if (scanf("%d%d", &n, &m) != 2 || n <= 0 || m <= 0)
        return;

    a = cr(n, m);
    if (a == NULL) {
        printf("Помилка виділення пам'яті.\n");
        return;
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (scanf("%d", &a[i][j]) != 1) {
                fr(a, n);
                return;
            }
        }
    }

    for (j = 0; j < m; j += 2) {
        for (i = 0; i < n - 1; i++) {
            for (k = 0; k < n - i - 1; k++) {
                if (a[k][j] > a[k + 1][j]) {
                    t = a[k][j];
                    a[k][j] = a[k + 1][j];
                    a[k + 1][j] = t;
                }
            }
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++)
            printf("%5d", a[i][j]);
        printf("\n");
    }

    fr(a, n);
}

void t947()
{
    int n;
    int **a;
    int i, j;
    int x1, y1, x2, y2;
    int p1, p2, p3, p4;

    if (scanf("%d", &n) != 1 || n <= 0)
        return;

    a = cr(n, n);
    if (a == NULL) {
        printf("Помилка виділення пам'яті.\n");
        return;
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (scanf("%d", &a[i][j]) != 1) {
                fr(a, n);
                return;
            }
        }
    }

    x1 = a[0][0];
    y1 = a[0][0];
    x2 = a[0][n - 1];
    y2 = a[0][n - 1];

    for (i = 0; i < n; i++) {
        if (a[i][i] > x1)
            x1 = a[i][i];
        if (a[i][i] < y1)
            y1 = a[i][i];

        if (a[i][n - 1 - i] > x2)
            x2 = a[i][n - 1 - i];
        if (a[i][n - 1 - i] < y2)
            y2 = a[i][n - 1 - i];
    }

    p1 = 0;
    p2 = 0;
    p3 = 0;
    p4 = 0;

    for (i = 0; i < n; i++) {
        if (a[i][i] == x1 && p1 == 0)
            p1 = i + 1;

        if (a[i][i] == y1)
            p3 = i + 1;

        if (a[i][n - 1 - i] == y2 && p2 == 0)
            p2 = i + 1;

        if (a[i][n - 1 - i] == x2)
            p4 = i + 1;
    }

    printf("a) %d %d\n", p1, p1);
    printf("b) %d %d\n", p2, n - p2 + 1);
    printf("c) %d %d\n", p3, p3);
    printf("d) %d %d\n", p4, n - p4 + 1);

    fr(a, n);
}

void t973()
{
    int n;
    int **a;
    int i, j;

    if (scanf("%d", &n) != 1 || n <= 0)
        return;

    a = cr(2 * n, 2 * n);
    if (a == NULL) {
        printf("Помилка виділення пам'яті.\n");
        return;
    }

    for (i = 0; i < 2 * n; i++) {
        for (j = 0; j < 2 * n; j++) {
            if (i < n && j < n)
                a[i][j] = 1;
            else if (i < n && j >= n)
                a[i][j] = 2;
            else if (i >= n && j < n)
                a[i][j] = 3;
            else
                a[i][j] = 4;
        }
    }

    for (i = 0; i < 2 * n; i++) {
        for (j = 0; j < 2 * n; j++)
            printf("%5d", a[i][j]);
        printf("\n");
    }

    fr(a, 2 * n);
}

void t1017()
{
    int n, m;
    int **a;
    int i, j;
    int ok;

    if (scanf("%d%d", &n, &m) != 2 || n <= 0 || m <= 0)
        return;

    a = cr(n, m);
    if (a == NULL) {
        printf("Помилка виділення пам'яті.\n");
        return;
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (scanf("%d", &a[i][j]) != 1) {
                fr(a, n);
                return;
            }
        }
    }

    for (i = 0; i < n; i++) {
        ok = 1;

        for (j = 0; j < m - 1; j++) {
            if (a[i][j] == 0 || a[i][j + 1] == 0 ||
                (a[i][j] > 0) == (a[i][j + 1] > 0)) {
                ok = 0;
                break;
            }
        }

        if (ok)
            printf("%d\n", i + 1);
    }

    fr(a, n);
}

void t968()
{
    int a[20][10];
    int i, j;
    double s;

    s = 0.0;

    for (i = 0; i < 20; i++) {
        for (j = 0; j < 10; j++) {
            if (scanf("%d", &a[i][j]) != 1)
                return;
        }
    }

    for (j = 0; j < 10; j++)
        s += a[4][j];

    printf("%.2f\n", s / 10.0);
}

int main()
{
    int k;

    printf("Введіть номер завдання (933, 947, 968, 973, 1017): ");

    if (scanf("%d", &k) != 1)
        return 1;

    switch (k) {
        case 933:
            t933();
            break;
        case 947:
            t947();
            break;
        case 968:
            t968();
            break;
        case 973:
            t973();
            break;
        case 1017:
            t1017();
            break;
    }

    return 0;
}