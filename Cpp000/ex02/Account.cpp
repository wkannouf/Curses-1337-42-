/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkannouf <wkannouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 21:18:12 by wkannouf          #+#    #+#             */
/*   Updated: 2025/10/20 20:22:15 by wkannouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_nbWithdrawals = 0;
	_nbDeposits = 0;
	_totalAmount += _amount;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created\n";
	_nbAccounts++;
}

int	Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" <<_nbAccounts << ";total:" << _totalAmount << ";deposits:" << _totalNbDeposits
		 << ";withdrawals:" << _totalNbWithdrawals << '\n';
}

void	Account::makeDeposit(int deposit)
{
	int	p_amount;

	p_amount = _amount;
	_totalNbDeposits += 1;
	_nbDeposits += 1;
	_amount += deposit;
	_totalAmount += deposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex <<";p_amount:" << p_amount <<";deposit:" << deposit
		<< ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << '\n';
}

bool	Account::makeWithdrawal(int withdrawal)
{
	int	p_amount;

	p_amount = _amount;
	_displayTimestamp();
	if (p_amount < withdrawal)
	{
		std::cout << "index:" << _accountIndex << ";p_amount:" << p_amount << ";withdrawal:refused\n";
		return (0);
	}
	_nbWithdrawals += 1;
	_totalNbWithdrawals += 1;
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	std::cout << "index:" << _accountIndex << ";p_amount:" << p_amount << ";withdrawal:" << withdrawal
		<< ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << '\n';
	return (1);
}

int		Account::checkAmount(void) const
{
	return (_amount);
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits
		<< ";withdrawals:" << _nbWithdrawals << '\n';
}

void	Account::_displayTimestamp(void)
{
	std::time_t	time;
	std::tm		*local_time;
	time = std::time(NULL);
	local_time = std::localtime(&time);	
	std::cout << '[';
	std::cout << local_time->tm_year + 1900;
	if (local_time->tm_mon < 9)
		std::cout << '0';
	std::cout << local_time->tm_mon + 1;
	if (local_time->tm_mday < 9)
		std::cout << '0';
	std::cout << local_time->tm_mday;
	std::cout << '-';
	if (local_time->tm_hour < 9)
		std::cout << '0';
	std::cout << local_time->tm_hour;
	if (local_time->tm_min < 9)
		std::cout << '0';
	std::cout << local_time->tm_min;
	if (local_time->tm_sec < 9)
		std::cout << '0';
	std::cout << local_time->tm_sec;
	std::cout << "] ";
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed\n";
}
