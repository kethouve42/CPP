/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kethouve <kethouve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:06:47 by kethouve          #+#    #+#             */
/*   Updated: 2024/11/19 15:12:17 by kethouve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template <typename T>
void iter(T *array, size_t len, void (*f)(T &))
{
	if (!array || !f)
		return;

	for(size_t i = 0; i < len; i++)
	{
		f(array[i]);
	}
}

template <typename T>
void iter(T *array, size_t len, void (*f)(const T &))
{
	if (!array || !f)
		return;

	for(size_t i = 0; i < len; i++)
	{
		f(array[i]);
	}
}