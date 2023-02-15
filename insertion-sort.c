#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *gen_rand_nums(int n);
void print_nums(int *nums, int n);
void insertion_sort(int *nums, int n);

int main()
{
  int n;
  scanf("%d", &n);

  int *nums = gen_rand_nums(n);

  printf("Before: ");
  print_nums(nums, n);

  insertion_sort(nums, n);

  printf("After: ");
  print_nums(nums, n);
}

void print_nums(int *nums, int n)
{
  for (int i = 0; i < n; i++)
  {
    printf("%d ", nums[i]);
  }
  printf("\n");
}

int *gen_rand_nums(int n)
{
  int *nums = (int *)calloc(n, sizeof(int));

  for (int i = 0; i < n; i++)
  {
    nums[i] = 1 + rand() % 101;
  }

  return nums;
}

void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

void insertion_sort(int *nums, int n)
{
  for (int i = 0; i < n; i++)
  {
    int j = i;

    while (j > 0 && nums[j - 1] > nums[j])
    {
      swap(&nums[j], &nums[j - 1]);
      j--;
    }
  }
}
