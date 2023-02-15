#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *gen_rand_nums(int n);

void bubble_sort(int *nums, int n);

void print_nums(int *nums, int n);

int main()
{
  srand(time(NULL));

  int n;
  scanf("%d", &n);

  int *nums = gen_rand_nums(n);

  printf("Before: ");
  print_nums(nums, n);

  bubble_sort(nums, n);

  printf("After: ");
  print_nums(nums, n);

  free(nums);

  return 0;
}

int *gen_rand_nums(int n)
{
  int *nums = (int *)calloc(n, sizeof(int));

  for (int i = 0; i < n; i++)
    nums[i] = 1 + rand() % 101;

  return nums;
}

void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

void bubble_sort(int *nums, int n)
{
  // Iterate through each number
  for (int i = 0; i < n; i++)
  {
    // Iterate through each subsequent number
    for (int j = i + 1; j < n; j++)
    {
      // If the subsequent number is less than the current number, swap position
      if (nums[j] < nums[i])
      {
        swap(&nums[i], &nums[j]);
      }
    }
  }
}

void print_nums(int *nums, int n)
{
  for (int i = 0; i < n; i++)
  {
    printf("%d ", nums[i]);
  }
  printf("\n");
}