/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:12:12 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/01/24 16:28:37 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void Phonebook::AddContact() {
    std::string input;

    GetContact(index).SetIndex(index);

    std::cout << "\033[38;5;218mEnter first name >> \033[0m";
    std::getline(std::cin >> std::ws, input);
    contact[index].SetFirstName(input);

    std::cout << "\033[38;5;218mEnter last name >> \033[0m";
    std::getline(std::cin >> std::ws, input);
    contact[index].SetLastName(input);

    std::cout << "\033[38;5;218mEnter nickname >> \033[0m";
    std::getline(std::cin >> std::ws, input);
    contact[index].SetNickname(input);

    std::cout << "\033[38;5;218mEnter phone number >> \033[0m";
    std::getline(std::cin >> std::ws, input);
    contact[index].SetPhoneNumber(input);

    std::cout << "\033[38;5;218mEnter darkest secret >> \033[0m";
    std::getline(std::cin >> std::ws, input);
    contact[index].SetDarkestSecret(input);

    std::cout << std::endl
              << "\033[38;5;151m" << GetContact(index).GetFirstName() << " added to the phonebook \033[38;5;218m[" << index + 1 << "/8]\033[0m\n\n";

    IncrementIndex(++index);
    SetNumberOfContacts(++nContacts);
};

void Phonebook::PrintBook(){
    std::string input;
    int number;
    
    std::cout << std::endl;
    std::cout << "*___________________________________________*" << std::endl;
    std::cout << "|Index     |First Name|Last Name |Nickname  |" << std::endl;
    std::cout << "|----------|----------|----------|----------|" << std::endl;

    if (nContacts == 0)
    {
        std::cout << "\033[31mNo contacts registered!!\033[0m" << std::endl << std::endl;
        return ;
    }

    for (int i = 0; i < nContacts; i++)
    {
        std::cout << "|" << i + 1 << "         ";
        std::cout << "|" << Normalize(GetContact(i).GetFirstName());
        std::cout << "|" << Normalize(GetContact(i).GetLastName());
        std::cout << "|" << Normalize(GetContact(i).GetNickname()) << "|" << std::endl;
        std::cout << "|----------|----------|----------|----------|" << std::endl;
    }

    std::cout << std::endl << "\033[38;5;218mPlease, enter the desired index: \033[0m";
    std::getline(std::cin >> std::ws, input);
    std::stringstream ss(input);
    ss >> number;
    ProcessRequest(number);
    std::cout << std::endl;
}

std::string Phonebook::Normalize(const std::string& str) {
    std::string cpy = str.substr(0, 10);
   
    for (int i = cpy.length(); i < 10; i++)
        cpy += " ";
    if (cpy[9] != ' ')
        cpy[9] = '.';
    return(cpy);
}

void Phonebook::ProcessRequest(int index) {
    if (index < 1 || index > 8 || index > nContacts)
    {
        std::cout << "\033[38;5;218mInvalid index, returning to menu\n\033[0m";
        return ;
    }
    std::cout << std::endl << "\033[38;5;218mContact information:\n";
    std::cout << "\033[38;5;151mFirst: \033[38;5;218m" << GetContact(index - 1).GetFirstName() << std::endl;
    std::cout << "\033[38;5;151mLast Name: \033[38;5;218m" << GetContact(index - 1).GetLastName() << std::endl;
    std::cout << "\033[38;5;151mNickname: \033[38;5;218m" << GetContact(index - 1).GetNickname() << std::endl;
    std::cout << "\033[38;5;151mPhone Number: \033[38;5;218m" << GetContact(index - 1).GetPhoneNumber() << std::endl;
    std::cout << "\033[38;5;151mDarkest Secret: \033[38;5;218m" << GetContact(index - 1).GetDarkestSecret() << "\033[0m"<< std::endl;
}

Contact Phonebook::GetContact(int index) {
    return (contact[index]);
}

void Phonebook::SetNumberOfContacts(int n) {
    n < 8 ? nContacts = n : nContacts = 8;
}

void Phonebook::IncrementIndex(int newIndex) {
   (index > 7) ? index = 0 : index = newIndex;
}