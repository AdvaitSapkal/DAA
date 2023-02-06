#include <stdio.h> 
#include <math.h>


double constf(double n) {return 1;}

double logarithmicf(double n) {return log2(n);}

double linearf(double n) {return n;}

double linearithmicf(double n){return n*log2(n);}

double quadraticf(double n) {return pow(n,2);}

double cubicf(double n){return pow(n,3);}

double exponentialf(double n){return exp(n); }

double powerf(double n) { return pow(3.0/2,n);}

double logsquaredf(double n) {return pow(log2(n),2);}

double function11(double n) {return pow(sqrt(2), log2(n));}

double loglogf(double n){return log2(log2(n));}

double factorialf(double n){
if(n==0) return 1;
return n*factorialf(n-1);
}

int main(){
double ip[11]={0,10,20,30,40,50,60, 70, 80, 90, 100};
printf("%7c\t%7c\n", 'x','y');
printf("constant:\n");
for(int i=0;i<11;i++) printf("%3.3f\t%5.3f\n",ip[i],constf(ip[i])); 
printf("logarithmic:\n");
for(int i=0;i<11;i++) printf("%3.3f\t%5.3f\n",ip[i],logarithmicf(ip[i]));
printf("linear:\n");
for(int i=0;i<11;i++)printf("%3.3f\t%5.3f\n",ip[i],linearf(ip[i]));
printf("linearithmic:\n");
for(int i=0;i<11;i++)printf("%3.3f\t%5.3f\n",ip[i],linearithmicf(ip[i])); 
printf("quadratic:\n");for(int i=0;i<11;i++) printf("%3.3f\t%5.3f\n",ip[i],quadraticf(ip[i])); 
printf("cubic:\n");for(int i=0;i<11;i++) printf("%3.3f\t%5.3f\n",ip[i],cubicf(ip[i])); 
printf("exponential:\n");for(int i=0;i<11;i++) printf("%3.3f\t%5.3f\n", ip[i], exponentialf(ip[i])); 
printf("power:\n");for(int i=0;i<11;i++) printf("%3.3f\t%5.3f\n",ip[i],powerf(ip[i]));
printf("logsquared:\n"); for(int i=0;i<11;i++)printf("%3.3f\t%5.3f\n",ip[i],logsquaredf(ip[i])); 
printf("function11\n"); for(int i=0;i<11;i++) printf("%3.3f\t%5.3f\n", ip[i], function11(ip[i])); 
printf("loglog:\n"); for(int i=0;i<11;i++) printf("%3.3f\t%5.3f\n",ip[i],loglogf(ip[i])); 
printf("factorial:\n");for(int i=0;i<11;i++) printf("%3.3f\t%5.3f\n",ip[i],factorialf(ip[i]));
}
