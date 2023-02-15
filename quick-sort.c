// TODO: Implement

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *gen_rand_nums(int n);
void print_nums(int *nums, int n);
void quick_sort(int *nums, int low, int high);

int main()
{
  int n;
  scanf("%d", &n);

  int *nums = gen_rand_nums(n);

  printf("Before: ");
  print_nums(nums, n);

  quick_sort(nums, 0, n - 1);

  printf("After: ");
  print_nums(nums, n);

  free(nums);
}

int *gen_rand_nums(int n)
{
  int *nums = (int *)calloc(n, sizeof(int));

  for (int i = 0; i < n; i++)
    nums[i] = 1 + rand() % 101;

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

int partition(int *nums, int low, int high)
{
  int pivot = nums[high];

  int i = low - 1;

  for (int j = low; j <= high - 1; j++)
  {
    if (nums[j] < pivot)
    {
      i++;
      swap(&nums[i], &nums[j]);
    }
  }

  swap(&nums[i + 1], &nums[high]);
  return i + 1;
}

void quick_sort(int *nums, int low, int high)
{
  if (low < high)
  {
    int partitionIndex = partition(nums, low, high);
    quick_sort(nums, low, partitionIndex - 1);
    quick_sort(nums, partitionIndex + 1, high);
  }
}
