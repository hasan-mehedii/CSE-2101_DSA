#include <stdio.h>

int recur(int a){
    if(a == 1){
        return 1;
    } 
    
    else{
        return a + recur(a-1);
    }
}

int print(int num){
    if(num == 0){
        return;
    }
    else{
        printf("%d, ",num);
    }
}

int main(){
    printf("Result: %d\n",recur(50));
    return 0;
}
