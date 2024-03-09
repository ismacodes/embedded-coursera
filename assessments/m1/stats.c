/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material.
 *
 *****************************************************************************/
/**
 * @file stats.c
 * @brief Defines a program that returns helpful statistcs about a dataset.
 *
 *
 * @author Ismael Castro
 * @date September 4, 2023
 *
 */

#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

/* Add other Implementation File Code Here */

/**
 * @brief A funciton that prints the statistics of an array including minimum,
 * maximum, mean, and median.
 *
 *
 * @param <data> An array of unsigned chars.
 *
 * @return This function does not return anything. Void.
 */

void print_statistics(unsigned char data[])
{

  printf("Unsorted array:\n");
  print_array(data, SIZE);
  printf("\n\n");
  sort_array(data, SIZE);
  printf("Sorted array:\n");
  print_array(data, SIZE);
  printf("\n\n");
  const unsigned min = find_minimum(data, SIZE);
  const unsigned max = find_maximum(data, SIZE);
  const unsigned mean = find_mean(data, SIZE);
  const unsigned median = find_median(data, SIZE);

  printf("Minimum %d\n", min);
  printf("Maximum %d\n", max);
  printf("Mean %d\n", mean);
  printf("Median %d\n", median);
}

void print_array(unsigned char data[], size_t length)
{
  printf("%d", data[0]);
  for (size_t i = 1; i < length; i++)
  {
    printf(", %d", data[i]);
  }
}

/**
 * @brief Given an array of data and a length, returns the median value.
 *
 *
 * @param <data> An array of unsigned chars.
 * @param <length> The length of the array in `data`
 *
 * @return The median value of the input data. Type: unsigned char.
 */

unsigned char find_median(unsigned char data[], size_t length)
{
  const size_t midpoint = length / 2;
  unsigned char median;
  // Deal with even legnth
  if (length % 2 == 0)
  {
    printf("Hello %d\n", data[midpoint]);
    median = (data[midpoint] + data[midpoint - 1]) / 2;
  }
  else
  {
    median = data[midpoint];
  }
  return median;
}

/**
 * @brief Given an array of data and a length, returns the mean value.
 *
 *
 * @param <data> An array of unsigned chars.
 * @param <length> The length of the array in `data`
 *
 * @return The mean value of the input data. Type: unsigned char.
 */

unsigned char find_mean(unsigned char data[], size_t length)
{
  // Avoid division by 0 in later calculation
  if (length <= 0)
    return 0;

  unsigned char mean;
  unsigned int sum = 0;
  for (size_t i = 0; i < length; i++)
  {
    sum += data[i];
  }

  mean = sum / length;
  return mean;
}

/**
 * @brief Given an array of data and a length, returns the maximum value.
 *
 *
 * @param <data> An array of unsigned chars.
 * @param <length> The length of the array in `data`
 *
 * @return The maximum value of the input data. Type: unsigned char.
 */

unsigned char find_maximum(unsigned char data[], size_t length)
{
  if (length <= 0)
    return 0;

  unsigned char max = data[0];
  for (size_t i = 0; i < length; i++)
  {
    if (data[i] > max)
    {
      max = data[i];
    }
  }
  return max;
}

/**
 * @brief Given an array of data and a length, returns the minimum value.
 *
 *
 * @param <data> An array of unsigned chars.
 * @param <length> The length of the array in `data`
 *
 * @return The minimum value of the input data. Type: unsigned char.
 */

unsigned char find_minimum(unsigned char data[], size_t length)
{
  if (length <= 0)
    return 0;

  unsigned char min = data[0];
  for (size_t i = 0; i < length; i++)
  {
    if (data[i] < min)
    {
      min = data[i];
    }
  }
  return min;
}

static void merge(unsigned char arr[], int low, int mid, int high)
{
  int n1 = mid - low + 1; // Size of left subarray
  int n2 = high - mid;    // Size of right subarray

  // Create temporary arrays
  int left[n1], right[n2];

  // Copy data to temporary arrays
  for (int i = 0; i < n1; i++)
  {
    left[i] = arr[low + i];
  }
  for (int j = 0; j < n2; j++)
  {
    right[j] = arr[mid + 1 + j];
  }

  // Merge the temporary arrays back into arr[low..high]
  int i = 0, j = 0, k = low;
  while (i < n1 && j < n2)
  {
    if (left[i] <= right[j])
    {
      arr[k] = left[i];
      i++;
    }
    else
    {
      arr[k] = right[j];
      j++;
    }
    k++;
  }

  // Copy the remaining elements (if any)
  while (i < n1)
  {
    arr[k] = left[i];
    i++;
    k++;
  }
  while (j < n2)
  {
    arr[k] = right[j];
    j++;
    k++;
  }
}

static void merge_sort(unsigned char arr[], int low, int high)
{
  if (low < high)
  {
    // Find the middle point
    int mid = low + (high - low) / 2;

    // Sort first and second halves
    merge_sort(arr, low, mid);
    merge_sort(arr, mid + 1, high);

    // Merge the sorted halves
    merge(arr, low, mid, high);
  }
}

/**
 * @brief Given an array of data and a length, sorts the array from largest to smallest.
 *
 * The 0th element should be the largest value, and the last element should be the smallest.
 *
 * @param <data> An array of unsigned chars.
 * @param <length> The length of the array in `data`
 *
 * @return There is no return value. Void. Upon return `data` is sorted.
 */

void sort_array(unsigned char data[], size_t length)
{
  merge_sort(data, 0, length - 1);
}

void main()
{

  unsigned char test[SIZE] = {34, 201, 190, 154, 8, 194, 2, 6,
                              114, 88, 45, 76, 123, 87, 25, 23,
                              200, 122, 150, 90, 92, 87, 177, 244,
                              201, 6, 12, 60, 8, 2, 5, 67,
                              7, 87, 250, 230, 99, 3, 100, 90};

  /* Other Variable Declarations Go Here */
  /* Statistics and Printing Functions Go Here */
  print_statistics(test);
}
