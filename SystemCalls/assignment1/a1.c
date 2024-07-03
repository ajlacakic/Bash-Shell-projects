#include <stdlib.h>
#include <stdio.h>

int main(int argc,char** argv) {
    int sum=0;
    for(int i=1;i<argc;i++){
        int n=atoi(argv[i]);
        if(n>=0){
            sum=sum+n;
        }
    }

printf("sum is %d\n",sum);    
}
