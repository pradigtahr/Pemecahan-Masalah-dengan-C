#include <stdio.h>

/* Funtion Prototypes*/
// int nestedStatement(int x);

/*Main funtion*/
int main(){
    // Variable declaration
    int x;

    // User input
    printf("Enter a number x>\t");
    scanf("%d", &x);

    // Process the logical expression
    // nestedStatement(x);
    if (x > 0){
        x = x + 1;
    }

    else{
        if (x < 0){
            x = x - 1;
        }
        else{
            x = x + 1;
        }
    }


    // print the result
    printf("Result>\t %d", x);

    return(0);
}

// int nestedStatement(int x){
//     /* Increment num_pos, num_neg, or num_zero depending on x */
//     /* Logical expression */
//     if (x > 0){
//         x = x + 1;
//     }

//     else{
//         if (x < 0){
//             x = x - 1;
//         }
//         else{
//             x = x + 1;
//         }
//     }

//     return(x);
// }