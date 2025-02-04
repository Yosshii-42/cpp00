#include <vector>
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdio>
#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// default constructor
Account::Account() 
    : _accountIndex(_nbAccounts), _amount(0),
        _nbDeposits(0), _nbWithdrawals(0) {
    _nbAccounts++;

    _displayTimestamp();
    std::cout << "index:" << _accountIndex
                << ";amount:" << _amount
                << ";created" << std::endl;
}

// constructor
Account::Account( int initial_deposit ) 
    : _accountIndex(_nbAccounts), _amount(initial_deposit),
        _nbDeposits(0), _nbWithdrawals(0) {
    _totalAmount += _amount;
    _nbAccounts++;

    _displayTimestamp();
    std::cout << "index:" << _accountIndex
                << ";amount:" << _amount
                << ";created" << std::endl;
}

// destructor
Account::~Account() {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";amount:" << _amount
              << ";closed"
              << std::endl;
}

int	Account::getNbAccounts( void ) { return _nbAccounts; }
int	Account::getTotalAmount( void ) { return _totalAmount; }
int	Account::getNbDeposits( void ) { return _totalNbDeposits; }
int	Account::getNbWithdrawals( void ) { return _totalNbWithdrawals; }

void	Account::displayAccountsInfos( void ) {
    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts
                << ";total:" << _totalAmount
                << ";deposits:" << _totalNbDeposits
                << ";withdrawals:" << _totalNbWithdrawals
                << std::endl;
}

void	Account::makeDeposit( int deposit ) {

    _displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";p_amount:" << _amount
              << ";deposit:" << deposit
              << ";amount:" << _amount + deposit
              << ";nb_deposits:1" 
              << std::endl;

    _amount += deposit;
    _nbDeposits = 1;
    _totalAmount += deposit;
    _totalNbDeposits++;
}

bool	Account::makeWithdrawal( int withdrawal ) {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";p_amount:" << _amount;

    if (checkAmount() < withdrawal) {
        std::cout << ";withdrawal:refused"
                  << std::endl;
        return (false);
    } else {
        std::cout << ";withdrawal:" << withdrawal
                << ";amount:" << _amount - withdrawal
                << ";nb_withdrawals:1"
                << std::endl;
        _amount -= withdrawal;
        _nbWithdrawals = 1;
        _totalAmount -= withdrawal;
        _totalNbWithdrawals++;
        return (true);
    }
}

int		Account::checkAmount( void ) const { return (_amount); }

void	Account::displayStatus( void ) const {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";amount:" << _amount
              << ";deposits:" << _nbDeposits
              << ";withdrawals:" << _nbWithdrawals
              << std::endl;
}

void	Account::_displayTimestamp( void ) {
    std::time_t     now;
    struct std::tm* timeInfo;
    char            buffer[20];

    now = std::time(NULL);
    timeInfo = std::localtime(&now);
    std::strftime(buffer, sizeof(buffer), "%Y%m%d_%H%M%S", timeInfo);
    std::cout << "[" << buffer << "] ";
}
