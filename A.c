#include <stdio.h>

void sorting(char str[]){
    //insertion sort
    int i = 1;
    while(str[i] != '\0'){
        char temp = str[i];
        int j=i-1;
        while(j>=0 && str[j]>temp){
            str[j+1] = str[j];
            j--;
        }
        str[j+1]=temp;
        i++;
    }
}

int main(){
    char input[1000000];
    scanf("%s", input);

    sorting(input);
    printf("%s\n",input);
    return 0;
}