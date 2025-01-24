/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:12:12 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/01/24 13:48:44 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void Contact::SetIndex(int newIndex) {
    index = newIndex;
}

void Contact::SetFirstName(const std::string& input) {
    firstName = input;
}

void Contact::SetLastName(const std::string& input) {
    lastName = input;
}

void Contact::SetNickname(const std::string& input) {
    nickname = input;
}

void Contact::SetPhoneNumber(const std::string& input) {
    phoneNumber = input;
}

void Contact::SetDarkestSecret(const std::string& input) {
    darkestSecret = input;
}

int	Contact::GetIndex() {
	return (index);
}

std::string Contact::GetFirstName() {
	return firstName;
}

std::string Contact::GetLastName() {
	return lastName;
}

std::string Contact::GetNickname() {
	return nickname;
}

std::string Contact::GetPhoneNumber() {
	return phoneNumber;
}

std::string Contact::GetDarkestSecret() {
	return darkestSecret;
}