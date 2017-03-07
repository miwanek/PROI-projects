#include <stdlib.h>
#include <stdio.h>
// Michał Iwanek
//testujemy komende pull
int random_my(int min, int max)
{
  int tmp;
  if (max >= min)
  {
    max -= min;
  }
  else
  {
    tmp = min - max;
    min = max;
    max = tmp;
  }
  return max ? (rand() % max + min) : min;
}

int f()
{
  const int N = 12;
  int* x = (int *)malloc(N * sizeof(int));
  int i;
  int mean = 0;
  for (i = 0; i <= N; ++i)// powinno być <, nadpisujemy gdzieś pamięc
  {
    int val = random_my(0, 100);
    printf("%02d: %d\n", i, val);
    x[i] = val;
  }
  for (i = 0; i <= N; ++i)//błędnie liczy średnią
  {
    mean += x[i];
  }
  mean /= N;
  return mean;
}

int main(int argc, char * argv[])
{
  int val = f();//pamięć nie jest zwalniana
  printf("Mean: %d\n", val);
  return 0;
}
