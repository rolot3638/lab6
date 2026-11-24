#include <stdio.h>

void task933() {
    int n,m;
    scanf("%d%d",&n,&m);
    int a[n][m];

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            scanf("%d",&a[i][j]);

    for(int j=0;j<m;j+=2) {
        for(int i=0;i<n-1;i++) {
            for(int k=0;k<n-i-1;k++) {
                if(a[k][j]>a[k+1][j]) {
                    int t=a[k][j];
                    a[k][j]=a[k+1][j];
                    a[k+1][j]=t;
                }
            }
        }
    }

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }
}

void task947() {
    int n;
    scanf("%d",&n);
    int a[n][n];

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&a[i][j]);

    int mx1=a[0][0],mn1=a[0][0];
    int mx2=a[0][n-1],mn2=a[0][n-1];

    for(int i=0;i<n;i++) {
        if(a[i][i]>mx1) mx1=a[i][i];
        if(a[i][i]<mn1) mn1=a[i][i];

        if(a[i][n-1-i]>mx2) mx2=a[i][n-1-i];
        if(a[i][n-1-i]<mn2) mn2=a[i][n-1-i];
    }

    int p1=0,p2=0,p3=0,p4=0;

    for(int i=0;i<n;i++) {
        if(a[i][i]==mx1 && p1==0)
            p1=i+1;

        if(a[i][i]==mn1)
            p3=i+1;

        if(a[i][n-1-i]==mn2 && p2==0)
            p2=i+1;

        if(a[i][n-1-i]==mx2)
            p4=i+1;
    }

    printf("a) %d %d\n",p1,p1);
    printf("b) %d %d\n",p2,n-p2+1);
    printf("c) %d %d\n",p3,p3);
    printf("d) %d %d\n",p4,n-p4+1);
}

void task973() {
    int n;
    scanf("%d",&n);
    int a[2*n][2*n];

    for(int i=0;i<2*n;i++) {
        for(int j=0;j<2*n;j++) {
            if(i<n && j<n)
                a[i][j]=1;
            else if(i<n && j>=n)
                a[i][j]=2;
            else if(i>=n && j<n)
                a[i][j]=3;
            else
                a[i][j]=4;
        }
    }

    for(int i=0;i<2*n;i++) {
        for(int j=0;j<2*n;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }
}

void task1017() {
    int n,m;
    scanf("%d%d",&n,&m);
    int a[n][m];

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            scanf("%d",&a[i][j]);

    for(int i=0;i<n;i++) {
        int ok=1;

        for(int j=0;j<m-1;j++) {
            if(a[i][j]==0 || a[i][j+1]==0 ||
               (a[i][j]>0)==(a[i][j+1]>0)) {
                ok=0;
                break;
            }
        }

        if(ok)
            printf("%d\n",i+1);
    }
}

void task968() {
    int a[20][10];
    double s=0;

    for(int i=0;i<20;i++)
        for(int j=0;j<10;j++)
            scanf("%d",&a[i][j]);

    for(int j=0;j<10;j++)
        s+=a[4][j];

    printf("%.2f\n",s/10);
}

int main() {
    int k;

    printf("Введіть номер завдання (933, 947, 968, 973, 1017): ");
    scanf("%d", &k);

    switch(k) {
        case 933:
            task933();
            break;
        case 947:
            task947();
            break;
        case 973:
            task973();
            break;
        case 1017:
            task1017();
            break;
        case 968:
            task968();
            break;
    }
}