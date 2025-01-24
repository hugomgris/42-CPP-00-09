/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:12:12 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/01/24 13:53:13 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>


class Contact {
	public:
	void SetIndex(int newIndex);
    void SetFirstName(const std::string& input);
    void SetLastName(const std::string& input);
    void SetNickname(const std::string& input);
    void SetPhoneNumber(const std::string& input);
    void SetDarkestSecret(const std::string& input);

	int 		GetIndex();
    std::string GetFirstName();
    std::string GetLastName();
    std::string GetNickname();
    std::string GetPhoneNumber();
    std::string GetDarkestSecret();

	private:
		int 		index;
		std::string firstName;
		std::string lastName;
		std::string nickname;
		std::string	phoneNumber;
		std::string	darkestSecret;
};

#endif