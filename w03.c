//
//  w03.c
//  hopefullythelastcprojectnameicomeupwith
//
//  Created by User on 5/8/24.
//

#include "w03.h"
void func (int para){
    para += 3;
    printf("Your number is %d\n", para);
}
void func2 (int *para){
    *para += 3;
    printf("Your number is %d\n", *para);
}
int main (void){
    int para;
    printf("Give me an integer. ");
    scanf("%d", &para);
    func(para);
    printf("Your number is %d\n", para);
    func2(&para);
    printf("Your number is %d\n", para);
    return 0;
}
