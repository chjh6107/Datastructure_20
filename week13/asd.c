#include <stdio.h>
int cal_area(double radious);

int main(void)
{
    double r;
    double area;

    printf("원의 반지름 입력 : ");
    scanf("%lf", &r);

    printf("면적 : %lf", area);

    return 0;

}

int cal_area(double radious);
{
    const double PI = 3.14;
    double area;

    area = PI * r * r;

    return 0;
}