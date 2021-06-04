#include <float.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

struct Point
{
    int x, y;
};


float Dist(struct Point p1, struct Point p2)
{
    return sqrt( (p1.x - p2.x)*(p1.x - p2.x) +
                 (p1.y - p2.y)*(p1.y - p2.y)
               );
}

struct Point * BFClosestPoints(struct Point P[], int n)
{
    if ((n < 2) || (P == NULL))
    {
        fprintf(stderr, "Error: not enough points to find closest pair");
        exit(EXIT_FAILURE);
    }

    struct Point * closestPair = (struct Point *)malloc(2 * (sizeof(struct Point)));
    if (closestPair == NULL)
    {
        fprintf(stderr, "Error: memory allocation failed");
        exit(EXIT_FAILURE);
    }

    float Min = FLT_MAX;
    float dist = 0.0;
    int i, j;
    for (i = 0; i < n; ++i)
    {
        for (j = i+1; j < n; ++j)
        {
            dist = Dist(P[i],P[j]);

            if (dist < Min)
            {
                Min = dist;
                closestPair[0] = P[i];
                closestPair[1] = P[j];
            }
        }
    }
    return closestPair;
}


int main()
{
    int i,n;
    printf("Enter The Number Of Pairs: ");
    scanf("%d",&n);
    struct Point onPlain[n];
    printf("Enter Pair coordinates X & Y : ");
    for(i=0;i<n;i++)
    {
        scanf("%d%d",&onPlain[i].x,&onPlain[i].y);
    }

    struct Point *closest = BFClosestPoints(onPlain,n) ;

    printf( "Closest Pairs: \n"
            "X1: %i Y1: %i\n"
            "X2: %i Y2: %i\n"
            "Distance: %f: ", closest[0].x, closest[0].y, closest[1].x, closest[1].y,
            Dist(closest[0],closest[1]));

    return 0;
}




