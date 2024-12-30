#include <stdio.h> 
#include <unistd.h> 
#define MSGSIZE 19 
char* msg1 = "PPWC"; 
char* msg2 = "class"; 
char* msg3 = "AkSHAY"; 
  
int main() 
{ 
    char inbuf[MSGSIZE]; 
    int p[2], i; 
  
    if (pipe(p) < 0) 
       return 1;  
  
    /* continued */
    /* write pipe */
  
    write(p[1], msg1, MSGSIZE); 
    write(p[1], msg2, MSGSIZE); 
    write(p[1], msg3, MSGSIZE); 
  
    for (i = 0; i < 3; i++) { 
        /* read pipe */
        read(p[0], inbuf, MSGSIZE); 
        printf("%s\n", inbuf); 
    } 
    return 0; 
} 
