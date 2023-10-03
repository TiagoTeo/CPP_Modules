/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiago-s <mtiago-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 18:46:15 by mtiago-s          #+#    #+#             */
/*   Updated: 2023/10/03 19:55:08 by mtiago-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;


Account::Account(int initial_deposit){
	_displayTimestamp();
	this->_accountIndex = _nbAccounts;
	_nbAccounts++;
	this->_amount = initial_deposit;
	_totalAmount += initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	std::cout << "index:" << this->_accountIndex \
	<< ";amount:" << this->_amount << ";created" << std::endl;
}

Account::~Account(){
	_displayTimestamp();
	_nbAccounts -= 1;
	_totalAmount -= this->_amount;
	std::cout << "index: " << this->_accountIndex \
	<< ";amount:" << this->_amount \
	<< ";closed" << std::endl;
}

void	Account::makeDeposit(int deposit){
	int	og_amount;

	_displayTimestamp();
	og_amount = this->_amount;
	this->_amount += deposit;
	this->_nbDeposits++;
	this->_totalNbDeposits++;
	this->_totalAmount += deposit;
	std::cout << "index:" << this->_accountIndex \
	<< ";p_amount:" << og_amount \
	<< ";deposit:" << deposit \
	<< ";amount:" << this->_amount \
	<< ";nb_deposits:" << this->_nbDeposits << std::endl;
}

bool	Account::makeWithdrawal(int withdrawl){
	int	og_amount;

	_displayTimestamp();
	og_amount = this->_amount;
	std::cout << "index:" << this->_accountIndex \
	<< ";p_amount:" << og_amount;
	if (this->_amount >= withdrawl)
	{
		this->_amount -= withdrawl;
		this->_totalAmount -= withdrawl;
		this->_nbWithdrawals++;
		this->_totalNbWithdrawals++;
		std::cout << ";withdrawal:" << withdrawl \
		<< ";amount:" << this->_amount \
		<< ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
		return (true);
	}
	std::cout << ";withdrawal:refused" << std::endl;
	return (false);
}

void	Account::_displayTimestamp(){
	std::time_t	now = time(0);
	tm	*gmt = gmtime(&now);
	std::cout << "[" << gmt->tm_year + 1900 << std::setfill('0') \
	<< std::setw(2) << gmt->tm_mon << std::setfill('0') \
	<< std::setw(2) << gmt->tm_mday << std::setfill('0') \
	<< std::setw(2) << gmt->tm_hour << std::setfill('0') \
	<< std::setw(2) << gmt->tm_min << std::setfill('0') \
	<< std::setw(2) << gmt->tm_sec << std::setfill('0') << "] ";
}

void	Account::displayStatus() const{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex \
	<< ";amount:" << this->_amount \
	<< ";deposits:" << this->_nbDeposits \
	<< ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

int	Account::checkAmount() const{
	return (this->_amount);
}

int	Account::getNbAccounts(){
	return (_nbAccounts);
}

int	Account::getNbDeposits(){
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals(){
	return (_totalNbWithdrawals);
}

int	Account::getTotalAmount(){
	return (_totalAmount);
}

void	Account::displayAccountsInfos(){
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts \
	<< ";total:" << _totalAmount \
	<< ";deposits:" << _totalNbDeposits \
	<< ";withdrawals:" << _totalNbWithdrawals << std::endl;
}