/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:18:29 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/01/24 19:50:00 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include <iomanip>
#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account() {
	_accountIndex = getNbAccounts();
	_amount = 0;
	_nbAccounts++;
	_displayTimestamp();
	std::cout << " index:\033[34m" << _accountIndex << "\033[0m"
		<< ";amount:\033[34m" << 0 << "\033[0m"
		<< ";created" << std::endl;
}

Account::Account(int initial_deposit) {
	_accountIndex = getNbAccounts();
	_amount += initial_deposit;
	_totalAmount += initial_deposit;
	_nbAccounts++;
	_displayTimestamp();
	std::cout << " index:\033[34m" << _accountIndex << "\033[0m"
		<< ";amount:\033[34m" << initial_deposit << "\033[0m"
		<< ";created" << std::endl;
}

Account::~Account() {
	_displayTimestamp();
	std::cout << " index:\033[34m" << _accountIndex << "\033[0m"
		<< ";amount:\033[34m" << _amount << "\033[0m"
		<< ";closed" << std::endl;
}

int	Account::getNbAccounts() {
	return(_nbAccounts);
}

int	Account::getTotalAmount() {
	return(_totalAmount);
}

int Account::getNbDeposits() {
	return(_totalNbDeposits);
}

int Account::getNbWithdrawals() {
	return(_totalNbWithdrawals);
}

void Account::displayAccountsInfos() {
	_displayTimestamp();
	std::cout << " accounts:\033[34m" << getNbAccounts() << "\033[0m"
		<< ";total:\033[34m" << getTotalAmount() << "\033[0m"
		<< ";deposits:\033[34m" << getNbDeposits() << "\033[0m"
		<< ";withdrawals:\033[34m" << getNbWithdrawals() << std::endl << "\033[0m";
}

void Account::makeDeposit(int deposit) {
	_displayTimestamp();
	std::cout << " index:\033[34m" << _accountIndex << "\033[0m"
		<< ";p_amount:\033[34m" << checkAmount() << "\033[0m";
	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	std::cout << ";deposit:\033[34m" << deposit << "\033[0m"
		<< ";amount:\033[34m" << checkAmount() << "\033[0m"
		<< ";nb_deposits:\033[34m" << _nbDeposits << std::endl << "\033[0m";
}

bool Account::makeWithdrawal(int withdrawal) {
	if (_amount > withdrawal)
	{
		_displayTimestamp();
		std::cout << " index:\033[34m" << _accountIndex << "\033[0m"
		<< ";p_amount:\033[34m" << checkAmount() << "\033[0m";
		_amount -= withdrawal;
		_totalAmount -= withdrawal;	
		_nbWithdrawals++;
		_totalNbWithdrawals++;
		std::cout << ";withdrawal:\033[34m" << withdrawal << "\033[0m"
		<< ";amount:\033[34m" << checkAmount() << "\033[0m"
		<< ";nb_withdrawals:\033[34m" << _nbWithdrawals << std::endl << "\033[0m";
		return true;
	}
	_displayTimestamp();
	std::cout << " index:\033[34m" << _accountIndex << "\033[0m"
		<< ";p_amount:\033[34m" << checkAmount() << "\033[0m"
		<< "withdrawal:refused" << std::endl;
	return(false);
}

int	Account::checkAmount() const {
	return(_amount);
}

void Account::displayStatus() const{
	_displayTimestamp();
	std::cout << " index:\033[34m" << _accountIndex << "\033[0m"
		<< ";amount:\033[34m" << checkAmount() << "\033[0m"
		<< ";deposits:\033[34m" << _nbDeposits << "\033[0m"
		<< ";withdrawals:\033[34m" << _nbWithdrawals << std::endl << "\033[0m";
}

void Account::_displayTimestamp() {
    std::time_t now = std::time(0);

    std::tm* localTime = std::localtime(&now);


    std::cout << "["
              << std::setw(4) << std::setfill('0') << (localTime->tm_year + 1900)
              << std::setw(2) << std::setfill('0') << (localTime->tm_mon + 1)
              << std::setw(2) << std::setfill('0') << localTime->tm_mday 
              << "_"
              << std::setw(2) << std::setfill('0') << localTime->tm_hour
              << std::setw(2) << std::setfill('0') << localTime->tm_min 
              << std::setw(2) << std::setfill('0') << localTime->tm_sec 
              << "]";
}