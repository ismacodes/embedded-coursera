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
 * @file stats.h 
 * @brief Header file for statistics assignment.
 *
 * This is for ese course c1m1.
 *
 * @author Ismael Castro
 * @date September 4, 2023
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */ 
#include <stddef.h>


/**
 * @brief A funciton that prints the statistics of an array including minimum,
 * maximum, mean, and median.
 *
 *
 * @param <data> An array of unsigned chars.
 *
 * @return This function does not return anything. Void.
 */

void print_statistics(unsigned char data[]); 

/**
 * @brief Given an array of data and a length, prints the array to the screen.
 * 
 *
 *
 * @param <data> An array of unsigned chars. 
 * @param <length> The length of the array in `data`
 *
 * @return This function does not return anything. Void.
 */

void print_array(unsigned char data[], size_t length);

/**
 * @brief Given an array of data and a length, returns the median value.
 *
 *
 * @param <data> An array of unsigned chars. 
 * @param <length> The length of the array in `data`
 *
 * @return The median value of the input data. Type: unsigned char.
 */

unsigned char find_median(unsigned char data[], size_t length);

/**
 * @brief Given an array of data and a length, returns the mean value.
 *
 *
 * @param <data> An array of unsigned chars. 
 * @param <length> The length of the array in `data`
 *
 * @return The mean value of the input data. Type: unsigned char.
 */

unsigned char find_mean(unsigned char data[], size_t length);

/**
 * @brief Given an array of data and a length, returns the maximum value.
 *
 *
 * @param <data> An array of unsigned chars. 
 * @param <length> The length of the array in `data`
 *
 * @return The maximum value of the input data. Type: unsigned char.
 */

unsigned char find_maximum(unsigned char data[], size_t length);

/**
 * @brief Given an array of data and a length, returns the minimum value.
 *
 *
 * @param <data> An array of unsigned chars. 
 * @param <length> The length of the array in `data`
 *
 * @return The minimum value of the input data. Type: unsigned char.
 */

unsigned char find_minimum(unsigned char data[], size_t length);

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

void sort_array(unsigned char data[], size_t length);


#endif /* __STATS_H__ */
