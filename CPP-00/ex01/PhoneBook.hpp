/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:12:12 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/01/24 16:22:22 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <sstream>
#include "Contact.hpp"

class Phonebook {
public:
    void		SetNumberOfContacts(int n);
	void		AddContact();
	void		PrintBook();
	void		ProcessRequest(int index);
	void		IncrementIndex(int index);

	std::string	Normalize(const std::string& str);
	
	Contact		GetContact(int index);
	
private:
	Contact contact[8];
	int		index;
	int		nContacts;
};

#endif