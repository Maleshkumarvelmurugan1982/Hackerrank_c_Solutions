#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;
double get_area(triangle tr);
double get_area(triangle tr) {
    double s = (tr.a + tr.b + tr.c) / 2.0;
    return sqrt(s * (s - tr.a) * (s - tr.b) * (s - tr.c));
}

void sort_by_area(triangle* tr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            double area_i = get_area(tr[i]);
            double area_j = get_area(tr[j]);
            if (area_i > area_j) {
                // Swap triangles
                triangle temp = tr[i];
                tr[i] = tr[j];
                tr[j] = temp;
            }
        }
    }
}

int main()
{
	int n;
	scanf("%d", &n);
	triangle *tr = malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	sort_by_area(tr, n);
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}
