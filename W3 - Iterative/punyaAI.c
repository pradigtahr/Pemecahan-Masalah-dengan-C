#include <stdio.h>
#include <math.h>

float dt;
float y, yi, xi, y_asli, galat, hasil;

int main() {
    dt = 0.005 ;
    xi = 3 ;
    y = 0 ;
    y_asli = 1572.6 ;
    hasil = 0 ;
    
    while(xi <= 10) {
        yi = 5*xi*xi - 7;
        y = yi * dt;
        hasil = hasil + y;
        xi = xi + dt;
    }
    printf("hasil riemann: %f\n", hasil) ;
    
    galat = ((hasil - y_asli) / y_asli) * 100 ; // Mengonversi galat ke dalam persen
    
    printf("galat: %f%%\n", galat) ;
    
    return 0;
}