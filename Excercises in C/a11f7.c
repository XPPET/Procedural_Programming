#include <stdio.h>
#include <string.h>

int main(){

int front,back;
char str[80];
char out[80];
char name[80];
char server[80];

printf("Dwse email address\n");
gets(str);

front=0;
while( str[front]==' '){front++;}
back=strlen(str)-1;
while(str[back]==' '){back--;}
strncpy(out, str+front, back-front+1);
out[back - front + 1] = '\0';


int index = 0;
while(str[index] != '@' && str[index] != '\0'){index++;}
strncpy(name,str,index);
name[index]='\0';

strncpy(server,str+index+1,(strlen(str)-index));

printf("Clear Address: %s\n",out);
printf("Name: %s ,\nLen: %d\n", name,strlen(name));
printf("Server: %s \n",server);
return 0;
}
