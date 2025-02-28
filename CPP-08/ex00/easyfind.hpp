/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 09:14:11 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/02/26 15:30:11 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <stdexcept>

template <typename T>
typename T::iterator easyfind(T &t, int n) {
    typename T::iterator it = std::find(t.begin(), t.end(), n);
    if (it == t.end())
        throw std::runtime_error("Value not found in container");
    return it;
}

#endif