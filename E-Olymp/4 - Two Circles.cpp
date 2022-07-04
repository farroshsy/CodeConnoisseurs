#include <stdio.h>
#include <math.h>
typedef double db;

db rls(db c) {
    if(c < 0)
        c = -1 * c;
    return c;
}

int main() {
    db x1, x2, y1, y2, r1, r2, rr;
    scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &r1, &x2, &y2, &r2);
    rr = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    if(rr == 0 && (r1 - r2) == 0)
        printf("-1\n");
    else if(rr < rls(r1 - r2) || rr > (r1 +r2))
        printf("0\n");
    else if(rr == rls(r1 - r2) || rr == (r1 +r2))
        printf("1\n");
    else
        printf("2\n");
    return 0;
}
