//niesprawdzone
#include <stdio.h>
#include <stdlib.h>

int uncompress(double **a_table, int *indexes, int size)
{
    int j = 0;
    double *tab = calloc(*(indexes + size - 1) + 1, sizeof(double));
    if (tab == NULL)
        return -1;
    for (int i = 0; i < *(indexes + size - 1) + 1; i++)
    {
        if (i == indexes[j])
        {
            tab[i] = (*a_table)[j];
            j++;
        }
    }
    *a_table = tab;
    return *(indexes + size - 1) + 1;
}

int main()
{
    int l = 10;
    double *tab = calloc(l, sizeof(double));
    tab[2] = 3.0, tab[5] = 1.0, tab[8] = 7.0;
    int *pos = compress(&tab, &l);

    for (int i = 0; i < l; i++)
    {
        printf("%f ", tab[i]);
        printf("%i\n", pos[i]);
    }
    printf("\n");

    l = uncompress(&tab, pos, l);
    for (int i = 0; i < l; i++)
    {
        printf("%f ", tab[i]);
    }

    free(tab);
    free(pos);
    return 0;
}
