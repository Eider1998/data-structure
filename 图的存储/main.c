#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct stu1
{
    int u, v, w;

} p[500010], t;

void qksort(struct stu1 p[], int l, int r)
{
    int i = l, j = r;
    struct stu1 key = p[i];
    if(i > j)
    {
        return ;
    }

    while(i < j)
    {
      while((p[j].w > key.w && i < j) || (p[j].w == key.w && p[j].u > key.u && i < j) || (p[j].w == key.w && p[j].u == key.u && p[j].v > key.v && i < j))
      {
        j--;
      }

       p[i] = p[j];



      while((p[i].w < key.w && i < j) || (p[i].w == key.w && p[i].u < key.u && i < j) || (p[i].w == key.w && p[i].u == key.u && p[i].v < key.v && i < j))
      {
          i++;
      }


       p[j] = p[i];

     }

     p[i] = key;
     qksort(p, l, i - 1);
     qksort(p, i + 1, r);

}

int main(void)
{
    int n, m, q;

    while(~scanf("%d %d", &n, &m))
    {
        int i;
        for(i = 0; i < m; i++)
        {
            scanf("%d %d %d", &p[i].u, &p[i].v, &p[i].w);
        }

        qksort(p, 0, m - 1);
        scanf("%d", &q);
        int num;
        for(i = 0; i < q; i++)
        {
            scanf("%d", &num);
            printf("%d %d\n", p[num].u, p[num].v);
        }
    }

    return 0;
}
