#include "Account.hpp"
#include <iostream>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

int		Account::getNbAccounts( void ) { return _nbAccounts; }
int		Account::getTotalAmount( void ) { return _totalAmount; }
int		Account::getNbDeposits( void ) { return _totalNbDeposits; }
int		Account::getNbWithdrawals( void ) { return _totalNbWithdrawals; }
int		Account::checkAmount( void ) const { return _amount; }

void	Account::_displayTimestamp( void )
{
	std::cout << "[19920104_091532] ";
}

Account::Account( void ) :
	_amount(0), _nbDeposits(0), _nbWithdrawals(0)
{
	_displayTimestamp();
	_accountIndex = _nbAccounts++;
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
	++_nbAccounts;
}

Account::Account( int initial_deposit ) :
	_amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
	_displayTimestamp();
	_accountIndex = _nbAccounts++;
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
	_totalAmount += _amount;
}

Account::~Account()
{
	--_nbAccounts;
	_totalAmount -= _amount;
	_totalNbDeposits -= _nbDeposits;
	_totalNbWithdrawals -= _nbWithdrawals;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

void	Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts
			  << ";total:" << _totalAmount
			  << ";deposits:" << _totalNbDeposits
			  << ";withdrawals:" << _totalNbWithdrawals
			  << std::endl;
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			  << ";amount:" << _amount
			  << ";deposits:" << _nbDeposits
			  << ";withdrawals:" << _nbWithdrawals
			  << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			  << ";p_amount:" << _amount
			  << ";deposit:" << deposit
			  << ";amount:" << (_amount + deposit)
			  << ";nb_deposits:" << ++_nbDeposits
			  << std::endl;
	_amount += deposit;
	_totalAmount += deposit;
	++_totalNbDeposits;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			  << ";p_amount:" << _amount
			  << ";withdrawal:";
	if (withdrawal > _amount)
	{
		std::cout << "refused" << std::endl;
		return false;
	}
	std::cout << withdrawal
			  << ";amount:" << (_amount - withdrawal)
			  << ";nb_withdrawals:" << ++_nbWithdrawals
			  << std::endl;
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	++_totalNbWithdrawals;
	return true;
}