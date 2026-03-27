#include <stdio.h>
#include <math.h>

#define PLANCK 6.62607015e-34  
#define MASS 9.10938356e-31    
#define PI 3.141592653589793

double energy_level(int n, double L) {
    return (pow(n, 2) * pow(PLANCK, 2)) / (8.0 * MASS * pow(L, 2));
}

double wavefunction(int n, double x, double L) {
    return sqrt(2.0 / L) * sin(n * PI * x / L);
}

int main() {
    int n, max_n, i, steps;
    double L, x, dx;

    char unit;
printf("Enter the length of the box (e.g., u for µm,  n for nm,  m for m): ");
scanf("%lf %c", &L, &unit);

if (unit == 'u') L *= 1e-6;
else if (unit == 'n') L *= 1e-9;
else if (unit == 'm') L *= 1.0;
else {
    printf("Unknown unit. Assuming meters.\n");
}

    printf("Enter the maximum quantum number n: ");
    scanf("%d", &max_n);

    printf("Enter the number of position steps to evaluate wavefunction: ");
    scanf("%d", &steps);

    dx = L / (steps - 1);

    printf("\nEnergy levels for a particle in a box of length %.2e m:\n", L);
    for (n = 1; n <= max_n; n++) {
        double E = energy_level(n, L);
        printf("n = %d, Energy = %.4e J\n", n, E);
    }

    printf("\nWavefunctions (psi_n(x)) at different positions:\n");
    for (n = 1; n <= max_n; n++) {
        printf("\nn = %d:\n", n);
        for (i = 0; i < steps; i++) {
            x = i * dx;
            printf("x = %.4e m, psi_%d(x) = %.4e\n", x, n, pow(wavefunction(n, x, L),2));
        }
    }

    return 0;
}
