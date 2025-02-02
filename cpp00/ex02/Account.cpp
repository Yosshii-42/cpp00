#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <chrono>
#include <ctime>

std::vector<std::string> logStorage;

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts( void ) {
    return _nbAccounts;
}

int	Account::getTotalAmount( void ) {
    return _totalAmount;
}

int	Account::getNbDeposits( void ) {
    return _totalNbDeposits;
}

int	Account::getNbWithdrawals( void ) {
    return _totalNbWithdrawals;
}

void	Account::displayAccountsInfos( void ) {
    Account::_displayTimestamp();
    std::cout << "accounts:" << _nbAccounts
                << ";total:" << _totalAmount
                << ";deposits:" << _totalNbDeposits
                << ";withdrawals:" << _totalNbWithdrawals
                << std::endl;
}

Account::Account( int initial_deposit ) 
    :_accountIndex(_nbAccounts), _amount(initial_deposit),
        _nbDeposits(0), _nbWithdrawals(0) {
    _totalAmount += _amount;
    _nbAccounts++;

    _displayTimestamp();
    std::cout << "index:" << _accountIndex
                << ";amount:" << _amount
                << ";created" << std::endl; 
}

Account::~Account () {
    char logBuffer[50];
    std::snprintf(logBuffer, sizeof(logBuffer),
        "index:%d;amount:%d;closed", _accountIndex, _amount);
    logStorage.push_back(logBuffer);

    if (_accountIndex == 0) {
        for (int i = logStorage.size() - 1; i >= 0; --i) {
            _displayTimestamp();
            std::cout << logStorage[i] << std::endl;
        }
    }
}

void	Account::makeDeposit( int deposit ) {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
                << ";p_amount:" << _amount;
    _amount += deposit;
    _totalAmount += deposit;
    _totalNbDeposits++;
    _nbDeposits = 1;
    std::cout << ";deposit:" << deposit
                << ";amount:" << _amount
                << ";nb_deposit" << _nbDeposits
                << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal ) {
    if (checkAmount() < withdrawal)
    {
        _displayTimestamp();
        std::cout << "index:" << _accountIndex
                  << ";p-amount:" << _amount
                  << "withdawal:refused" << std::endl;
        return (false);
    }
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";p_amount:" << _amount
              << ";withdrawal:" << withdrawal
              << ";amount:" << _amount - withdrawal
              << ";nb_withdrawals:1" << std::endl;
    _totalAmount -= withdrawal;
    _totalNbWithdrawals++;
    _nbWithdrawals = 1;
    _amount -= withdrawal;
    return (true);
}

int		Account::checkAmount( void ) const {
    return (_amount);
}

void	Account::displayStatus( void ) const {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
                << ";amount:" << _amount
                << ";deposits:" << _nbDeposits
                << ";withdrawal:" << _nbWithdrawals
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
