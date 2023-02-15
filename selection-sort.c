#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *gen_rand_nums(int n);
void print_nums(int *nums, int n);
void selection_sort(int *nums, int n);

int main()
{
  int n;
  scanf("%d", &n);

  int *nums = gen_rand_nums(n);

  printf("Before: ");
  print_nums(nums, n);

  selection_sort(nums, n);

  printf("After: ");
  print_nums(nums, n);

  free(nums);
}

int *gen_rand_nums(int n)
{
  int *nums = calloc(n, sizeof(int));

  for (int i = 0; i < n; i++)
  {
    nums[i] = 1 + rand() % 101;
  }

  return nums;
}

void print_nums(int *nums, int n)
{
  for (int i = 0; i < n; i++)
  {
    printf("%d ", nums[i]);
  }
  printf("\n");
}

void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

void selection_sort(int *nums, int n)
{
  for (int i = 0; i < n; i++)
  {
    int minIdx = i;
    for (int j = i + 1; j < n - 1; j++)
      if (nums[j] < nums[minIdx])
        minIdx = j;

    if (minIdx != i)
      swap(&nums[i], &nums[minIdx]);
  }
}
