/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:21:07 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/02/25 16:27:55 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T, typename Func>

void iter(T *arr, size_t len, Func f){
	for (size_t i = 0; i < len; i++){
		f(arr[i]);
	}
}

#endif