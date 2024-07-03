#include<stdio.h>
#include<stdlib.h>
int main(int argc, char** argv){
if(argc!=4){
printf("please enter 3  numbers\n");
return 1;
}
int  a=atoi(argv[1]);
int b=atoi(argv[2]);
int c=atoi(argv[3]);
 int min, max;
max=min=a;
if(b>max){max=b;}
if(c>max){max=c;}
if(b<min){min=b;}
if(c<min){min=c;}
printf("min number %d\n",min);
printf("max number %d\n", max);

}
