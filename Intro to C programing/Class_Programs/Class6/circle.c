#include <stdio.h>

#define PI 3.14

int main()
{
    float radius, area, circumference;

    printf("Enter the radius: ");
    scanf("%f", &radius);

    area = PI * radius * radius;
    circumference = 2 * PI * radius;

    printf("Circle Radius = %.4f Area = %.4f Circumference = %.4f\n", radius, area, circumference);
}