//
//  main.c
//  longCallculation
//
//  Created by Даниил on 24.03.2024.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

struct number {
    char flag;
    size_t len;
    uint_fast64_t *number;
};

void num_reader(struct number*);
void num_memory(struct number*);
void cout(uint_fast64_t*, size_t);


int main(int argc, const char * argv[]) {
    
    struct number num1, num2; 
    num1.len = 0; num2.len = 0;   //как исправить?
    
    num_memory(&num1);
    num_reader(&num1);
    
    num_memory(&num1);
    num_reader(&num1);
    
    cout(num1.number, num1.len);
    printf("\n%lu", sizeof(*(num1.number)));
    return 0;
}

void num_memory(struct number* num){
    num->number = (uint_fast64_t*)calloc(10+num->len, sizeof(num->number)); //Чему равен len изначально?
}


void num_reader(struct number* num){
    const uint_fast64_t base = 1e18;
    char c = 0;
    int count = 0;
    while(((c = getchar()) >= '0' && c <= '9') || c == ' '){
        if(c >= '0' && c <= '9'){
            for(int i = count; i >= 0; i--){
                (num->number)[i+1] = (num->number)[i+1] + ((num->number)[i]*10)/base;     //Так нормально?
                (num->number)[i] = ((num->number)[i]*10)%base;
            }
            (num->number)[0] += (int)c-48;
            if((num->number)[count+1] > 0) count++;
        }
    }
    num->len = count+1;
}

void cout(uint_fast64_t* arr, size_t n){
    for(int i = 0; i < n; i ++){
        printf("%lld\t", arr[i]);
    }
}
