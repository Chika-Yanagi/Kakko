#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSTACK 512

typedef char elementtype;
struct stack{
  int top;
  elementtype contents[MAXSTACK];
};

void initstack(struct stack *p){
  p->top = -1;
}

int stackempty(struct stack *p){
  if(p->top == -1){
    return 1;
  }else{
    return 0;
  }
}

elementtype pop(struct stack *p){   
  if(stackempty(p) == 1){    
     printf("Underflow\n");
     exit(1);
  }else{ 
    return p->contents[(p->top)--]; 
  } 
}
void push(struct stack *p,elementtype e){
  if(p->top == MAXSTACK-1){ 
     printf("Overflow\n");
     exit(1);
  }else{
    p->contents[++(p->top)] = e;   
  }
} 
int balance(struct stack *p,elementtype a[],int j){
  int i;
  for(i=0;i<j;i++){
    if(a[i]=='('||a[i]=='{'||a[i]=='['||a[i]=='<'){
      push(p,a[i]);
    }else if(a[i]==')'||a[i]=='}'||a[i]==']'||a[i]=='>'){
      if(a[i]==')'&&p->contents[p->top]=='('){
        pop(p);
      }else if(a[i]=='}'&&p->contents[p->top]=='{'){
        pop(p);
      }else if(a[i]==']'&&p->contents[p->top]=='['){
        pop(p);
      }else if(a[i]=='>'&&p->contents[p->top]=='<'){
        pop(p);
      }else{return 0;}
    }
  }
  if(stackempty(p)==1){
    return 1;
  }else{
    return 0;
  }
} 
int main(){
  struct stack s;
  int i = 0;
  char buf[MAXSTACK+2];
  initstack(&s);
  fgets(buf,sizeof(buf),stdin);
  while(buf[i]!='\n'){
    i++;
  }
  if(balance(&s,buf,i)==1){
    printf("Good\n");
  }else{
    printf("Bad\n");
  }
  return 0;
}          
          
       
