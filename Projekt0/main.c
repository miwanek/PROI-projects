#include <stdlib.h>
#include <stdio.h>

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
  const int N = 10;
  int* x = (int *)malloc(N * sizeof(int));
  int i;
  int mean = 0;
  for (i = 0; i <= N; ++i)
  {
    int val = random_my(0, 100);
    printf("%02d: %d\n", i, val);
    x[i] = val;
  }
  for (i = 0; i <= N; ++i)
  {
    mean += x[i];
  }
  mean /= N;
  return mean;
}

int main(int argc, char * argv[])
{
  int val = f();
  printf("Mean: %d\n", val);
  return 0;
}
