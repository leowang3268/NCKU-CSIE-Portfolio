#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <cmath>
#include <iomanip> 
#include <iostream>
#define SIGN(a,b) ((b) >= 0.0 ? fabs(a) : -fabs(a))
#define MAX(a,b) (a>b?a:b)
#define MIN(a,b) (a<b?a:b)

using namespace std;

double **Make2DArray(int row, int col){
    double **a;
    int i;
    a = (double **)malloc(row* sizeof(double *));
    for (i = 0; i<row; i++){
        a[i] = (double *)malloc(col* sizeof(double));
    }
    return a;
}
void SetZero(double** a, int m){
    int i, j;
    for (i = 0; i < m; i++){
        for (j = 0; j < m; j++){
            a[i][j] = 0;
        }
    }
}
void Free2DArray(double** a, int row){
    int i;
    for (i = 0; i<row; i++){
        free(a[i]);
    }
    free(a);
}

static double PYTHAG(double a, double b)
{
    double at = fabs(a), bt = fabs(b), ct, result;

    if (at > bt)       { ct = bt / at; result = at * sqrt(1.0 + ct * ct); }
    else if (bt > 0.0) { ct = at / bt; result = bt * sqrt(1.0 + ct * ct); }
    else result = 0.0;
    return(result);
}

int dsvd(double **a, int m, int n, double *w, double **v)
{
    int flag, i, its, j, jj, k, l, nm;
    double c, f, h, s, x, y, z;
    double anorm = 0.0, g = 0.0, scale = 0.0;
    double *rv1;

    if (m < n)
    {
        cout << "#rows must > #cols \n";
        return(1);
    }

    rv1 = (double *)malloc((unsigned int)n*sizeof(double));

    /* Householder reduction to bidiagonal form */
    for (i = 0; i < n; i++)
    {
        /* left-hand reduction */
        l = i + 1;
        rv1[i] = scale * g;
        g = s = scale = 0.0;
        if (i < m)
        {
            for (k = i; k < m; k++)
                scale += fabs((double)a[k][i]);
            if (scale)
            {
                for (k = i; k < m; k++)
                {
                    a[k][i] = a[k][i] / scale;
                    s += a[k][i] * a[k][i];
                }
                f = a[i][i];
                g = -SIGN(sqrt(s), f);
                h = f * g - s;
                a[i][i] = f - g;
                if (i != n - 1)
                {
                    for (j = l; j < n; j++)
                    {
                        for (s = 0.0, k = i; k < m; k++)
                            s += a[k][i] * a[k][j];
                        f = s / h;
                        for (k = i; k < m; k++)
                            a[k][j] += f * a[k][i];
                    }
                }
                for (k = i; k < m; k++)
                    a[k][i] = a[k][i] * scale;
            }
        }
        w[i] = scale * g;

        /* right-hand reduction */
        g = s = scale = 0.0;
        if (i < m && i != n - 1)
        {
            for (k = l; k < n; k++)
                scale += fabs(a[i][k]);
            if (scale)
            {
                for (k = l; k < n; k++)
                {
                    a[i][k] = a[i][k] / scale;
                    s += a[i][k] * a[i][k];
                }
                f = a[i][l];
                g = -SIGN(sqrt(s), f);
                h = f * g - s;
                a[i][l] = (f - g);
                for (k = l; k < n; k++)
                    rv1[k] = a[i][k] / h;
                if (i != m - 1)
                {
                    for (j = l; j < m; j++)
                    {
                        for (s = 0.0, k = l; k < n; k++)
                            s += a[j][k] * a[i][k];
                        for (k = l; k < n; k++)
                            a[j][k] += s * rv1[k];
                    }
                }
                for (k = l; k < n; k++)
                    a[i][k] = a[i][k] * scale;
            }
        }
        anorm = MAX(anorm, (fabs(w[i]) + fabs(rv1[i])));
    }

    /* accumulate the right-hand transformation */
    for (i = n - 1; i >= 0; i--)
    {
        if (i < n - 1)
        {
            if (g)
            {
                for (j = l; j < n; j++)
                    v[j][i] = a[i][j] / a[i][l] / g;
                /* double division to avoid underflow */
                for (j = l; j < n; j++)
                {
                    for (s = 0.0, k = l; k < n; k++)
                        s += a[i][k] * v[k][j];
                    for (k = l; k < n; k++)
                        v[k][j] += s * v[k][i];
                }
            }
            for (j = l; j < n; j++)
                v[i][j] = v[j][i] = 0.0;
        }
        v[i][i] = 1.0;
        g = rv1[i];
        l = i;
    }

    /* accumulate the left-hand transformation */
    for (i = n - 1; i >= 0; i--)
    {
        l = i + 1;
        g = w[i];
        if (i < n - 1)
            for (j = l; j < n; j++)
                a[i][j] = 0.0;
        if (g)
        {
            g = 1.0 / g;
            if (i != n - 1)
            {
                for (j = l; j < n; j++)
                {
                    for (s = 0.0, k = l; k < m; k++)
                        s += a[k][i] * a[k][j];
                    f = (s / a[i][i]) * g;
                    for (k = i; k < m; k++)
                        a[k][j] += f * a[k][i];
                }
            }
            for (j = i; j < m; j++)
                a[j][i] = a[j][i] * g;
        }
        else
        {
            for (j = i; j < m; j++)
                a[j][i] = 0.0;
        }
        ++a[i][i];
    }

    /* diagonalize the bidiagonal form */
    for (k = n - 1; k >= 0; k--)
    {                             /* loop over singular values */
        for (its = 0; its < 30; its++)
        {                         /* loop over allowed iterations */
            flag = 1;
            for (l = k; l >= 0; l--)
            {                     /* test for splitting */
                nm = l - 1;
                if (fabs(rv1[l]) + anorm == anorm)
                {
                    flag = 0;
                    break;
                }
                if (fabs(w[nm]) + anorm == anorm)
                    break;
            }
            if (flag)
            {
                c = 0.0;
                s = 1.0;
                for (i = l; i <= k; i++)
                {
                    f = s * rv1[i];
                    if (fabs(f) + anorm != anorm)
                    {
                        g = w[i];
                        h = PYTHAG(f, g);
                        w[i] = h;
                        h = 1.0 / h;
                        c = g * h;
                        s = (-f * h);
                        for (j = 0; j < m; j++)
                        {
                            y = a[j][nm];
                            z = a[j][i];
                            a[j][nm] = y * c + z * s;
                            a[j][i] = z * c - y * s;
                        }
                    }
                }
            }
            z = w[k];
            if (l == k)
            {                  /* convergence */
                if (z < 0.0)
                {              /* make singular value nonnegative */
                    w[k] = (-z);
                    for (j = 0; j < n; j++)
                        v[j][k] = (-v[j][k]);
                }
                break;
            }
            if (its >= 30) {
                free((void*)rv1);
                cout << "No convergence after 30,000! iterations \n" ;
                return(1);
            }

            /* shift from bottom 2 x 2 minor */
            x = w[l];
            nm = k - 1;
            y = w[nm];
            g = rv1[nm];
            h = rv1[k];
            f = ((y - z) * (y + z) + (g - h) * (g + h)) / (2.0 * h * y);
            g = PYTHAG(f, 1.0);
            f = ((x - z) * (x + z) + h * ((y / (f + SIGN(g, f))) - h)) / x;

            /* next QR transformation */
            c = s = 1.0;
            for (j = l; j <= nm; j++)
            {
                i = j + 1;
                g = rv1[i];
                y = w[i];
                h = s * g;
                g = c * g;
                z = PYTHAG(f, h);
                rv1[j] = z;
                c = f / z;
                s = h / z;
                f = x * c + g * s;
                g = g * c - x * s;
                h = y * s;
                y = y * c;
                for (jj = 0; jj < n; jj++)
                {
                    x = v[jj][j];
                    z = v[jj][i];
                    v[jj][j] = x * c + z * s;
                    v[jj][i] = z * c - x * s;
                }
                z = PYTHAG(f, h);
                w[j] = z;
                if (z)
                {
                    z = 1.0 / z;
                    c = f * z;
                    s = h * z;
                }
                f = (c * g) + (s * y);
                x = (c * y) - (s * g);
                for (jj = 0; jj < m; jj++)
                {
                    y = a[jj][j];
                    z = a[jj][i];
                    a[jj][j] = y * c + z * s;
                    a[jj][i] = z * c - y * s;
                }
            }
            rv1[l] = 0.0;
            rv1[k] = f;
            w[k] = x;
        }
    }
    free((void*)rv1);
    return(0);
}


int main()
{
    int N, i, j;
    ifstream inFile("input.txt", ios::in);
    if(!inFile){
        cerr << "Failed opening" << endl;
        exit(1);
    }
    ofstream outFile("output.txt", ios::out);
    if(!outFile){
        cerr << "Failed opening" << endl;
        exit(1);
    }
    inFile >> N;
    outFile << N << endl;
    while(N>0) {
        int m, n;
        inFile >> m >> n;
        double** a = Make2DArray(m, n);
        for (i=0; i<m; i++)
            for (j=0; j<n;j++)
                inFile >> a[i][j];
        int mn = MAX(m, n);
    	int nn = MIN(m, n);
    	double** u = Make2DArray(mn, mn);
    	double** v = Make2DArray(mn, mn);
    	double* w = (double *)malloc(mn* sizeof(double));
    	SetZero(u, mn);
    	for (i = 0; i < m; i++) {
       		for (j = 0; j < n; j++)
            	u[i][j] = a[i][j];
    	}
    	dsvd(u, mn, mn, w, v);
    	
    	outFile << m << " " << m << endl;
        for (i=0; i<m; i++)
        {
            for (j=0; j<m; j++)
                outFile << fixed << setprecision(2) << u[i][j] << " ";
            outFile << endl;
        }

        outFile << m << " " << n << endl;
        for (i=0; i<m; i++)
        {
            for (j=0; j<n; j++) { 
            	if(i==j)
                	outFile << fixed << setprecision(2) << w[i] << " " ;
                else 
                	outFile << fixed << setprecision(2) << 0.00 << " " ;
            }
			outFile << endl; 
        }
        
        outFile << n << " " << n << endl;
        for (i=0; i<n; i++)
        {
            for (j=0; j<n; j++)
                outFile << fixed << setprecision(2) << v[i][j] << " ";
                outFile << endl;
        }

    	Free2DArray(a, m);
    	Free2DArray(u, mn);
    	Free2DArray(v, mn);
    	free(w);
    	getchar();
        
        
        
        N--;
    }
    return 0;
}

