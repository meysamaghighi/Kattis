// Meysam Aghighi

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

//int lcm(int x,int y)
//{
//    int t;
//    while (y != 0)
//    {
//      t=y;
//      y=x%y;
//      x=t;
//    }
//    return x;
//}

//void gaussian1(double **a, int n){
//    for(int i=0;i<n-1;i++){
//       for(int j=i+1;j<n;j++){
//         int l=lcm(a[i][i],a[j][i]);
//         if(l!=0&&(a[i][i]!=0&&a[j][i]!=0)){
//           l=(a[i][i]*a[j][i])/l;
//           int d1=l/a[i][i];
//           int d2=l/a[j][i];
//           a[j][i]=0;
//           for(int k=i+1;k<n;k++){
//             a[j][k]=(d2*a[j][k])-(d1*a[i][k]);
//           }
//         }
//       }
//    }
//    cout<<"\nThe given Matrix after Gauss Elimination is:\n";
//    for(int i=0;i<n;i++){
//      for(int j=0;j<n;j++){
//         cout<<a[i][j]<<"\t";
//      }
//      cout<<"\n";
//    }
//}

void print(vector< vector<double> > A) {
    int n = A.size();
    for (int i=0; i<n; i++) {
        for (int j=0; j<n+1; j++) {
            cout << A[i][j] << "\t";
            if (j == n-1) {
                cout << "| ";
            }
        }
        cout << "\n";
    }
    cout << endl;
}

vector<double> gauss(vector< vector<double> > &A) {
    int n = A.size();

    for (int i=0; i<n; i++) {
        // Search for maximum in this column
        double maxEl = abs(A[i][i]);
        int maxRow = i;
        for (int k=i+1; k<n; k++) {
            if (abs(A[k][i]) > maxEl) {
                maxEl = abs(A[k][i]);
                maxRow = k;
            }
        }

        // Swap maximum row with current row (column by column)
        for (int k=i; k<n+1;k++) {
            double tmp = A[maxRow][k];
            A[maxRow][k] = A[i][k];
            A[i][k] = tmp;
        }

        // Make all rows below this one 0 in current column
        for (int k=i+1; k<n; k++) {
            // change
            double c;
            if (A[i][i] != 0){
                c = -A[k][i]/A[i][i];

                for (int j=i; j<n+1; j++) {
                    if (i==j) {
                        A[k][j] = 0;
                    } else {
                        A[k][j] += c * A[i][j];
                    }
                }
            }
        }
    }

    // Solve equation Ax=b for an upper triangular matrix A
    vector<double> x(n);
    for (int i=n-1; i>=0; i--) {
        if (A[i][i] != 0){
            x[i] = A[i][n]/A[i][i];

            for (int k=i-1;k>=0; k--) {
                A[k][n] -= A[k][i] * x[i];
            }
        }
    }
    return x;
}

int main(){
    int n;
    while (cin>>n && n){
        double **a,b[n];
        a = new double *[n];
        for (int i=0;i<n;i++)
            a[i] = new double[n];
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++)
                cin >> a[i][j];
        for (int i=0;i<n;i++)
            cin >> b[i];


        vector<double> line(n+1,0);
        vector< vector<double> > A(n,line);

        // Read input data
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                A[i][j] = a[i][j];
            }
        }

        for (int i=0; i<n; i++) {
            A[i][n] = b[i];
        }

        // Print input
//        print(A);

        // Calculate solution
        vector<double> x(n);
        x = gauss(A);

        // Print output
        print(A);
        int state = 0; // state=0: good
//        for (int i=0;i<n;i++)
//            for (int j=0;j<n+1;j++)
//                if (!isfinite(A[i][j]))
//                    state = 1;

//        if (state == 1){ // state=1: multiple
        for (int i=0;i<n;i++){
            int j = 0;
            while (A[i][j] == 0 && j<=n)
                j++;
//            cout << "n=" << n << ":" << i << ":" << j << endl;
            if ( j==n && (A[i][n] != 0) ) state = 2; // state=2: inconsistent
            if ( j==n+1) state = 1;
        }
//        }
        switch(state){
        case 0:
            for (int i=0;i<n;i++)
                cout << (i?" ":"") << x[i];
            cout << endl;
            break;
        case 1: cout << "multiple" << endl; break;
        case 2: cout << "inconsistent" << endl; break;
        }

//        gaussian1(a,n);


    }




    return 0;
}




