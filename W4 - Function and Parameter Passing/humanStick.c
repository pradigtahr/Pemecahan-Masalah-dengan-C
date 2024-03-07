#include <stdio.h>

/* Function Prototypes */
void draw_circle(void);
void draw_intersect(void);
void draw_base(void);
void draw_triangle(void);

int main(void){
    /*Draw a circle*/
    draw_circle();
    /*Draw a triangle*/
    draw_triangle();
    /*Draw intersecting lines*/
    draw_intersect();

    return 0;
}

void draw_circle(void){
    printf("  *     \n");
    printf("*   *   \n");
    printf(" * *    \n");
}

void draw_intersect(void){
    printf("  /\\    \n");
    printf(" /  \\   \n");
    printf("/    \\  \n");
}

void draw_base(void){
    printf("-------  \n");
}

void draw_triangle(void){
    draw_intersect();
    draw_base();
}