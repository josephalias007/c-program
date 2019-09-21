#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "coeffs.h"
float A,B;
int a;
double **P,**S;

void save_a()
{

    FILE * fptr;
    fptr = fopen("./data/zx.dat","w");
    fprintf(fptr,"%lf",A);
    fclose(fptr);

}

void save_b()
{

    FILE * fptr;
    fptr = fopen("./data/zy.dat","w");
    fprintf(fptr,"%lf",B);
    fclose(fptr);

}

void save_t()
{

    FILE * fptr;
    fptr = fopen("./data/zg.dat","w");
    fprintf(fptr,"%lf",P[0][0]);
    fprintf(fptr,"\n");
    fprintf(fptr,"%lf",P[1][0]);
    fclose(fptr);

}

void save_o()
{

    FILE * fptr;
    fptr = fopen("./data/zl.dat","w");
    fprintf(fptr,"%lf",S[0][0]);
    fprintf(fptr,"\n");
    fprintf(fptr,"%lf",S[1][0]);
    fclose(fptr);

}










int main()
{

int a,b,c,d;
double **V,**m,**temp,**u,**theta;
//float B,A;
V=loadtxt("./data/v.dat",2,2);

a=V[0][0];
b=V[0][1];
c=V[1][1];
d=144;


A= sqrt(d/a);
B= sqrt(d/c);

m=loadtxt("./data/m.dat",2,1);
P=loadtxt("./data/P1.dat",2,1);
S=loadtxt("./data/s.dat",2,1);

P[1][0]=m[1][0]-S[1][0];
int e=1;

P[0][0]=sqrt((pow(A,2)*3)/4);

S[0][0]=P[0][0]-m[0][0];

temp = linalg_sub(P,S,2,1);
float u1,r;
u1=linalg_norm(temp,2);
r=u1*u1;
printf("the value of PA^2 is = %f",r);


save_a();
save_b();
save_t();
save_o();


}








