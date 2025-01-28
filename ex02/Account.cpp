#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <chrono>
#include <ctime>


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
        
    }

	Account::Account( int initial_deposit ) {

    }

    void	makeDeposit( int deposit );
	bool	makeWithdrawal( int withdrawal );
	int		checkAmount( void ) const;
	void	displayStatus( void ) const;

    void	_displayTimestamp( void ) {
        auto    now = std::chrono::system_clock::now();
        std::time_t currentTime = std::chrono::system_clock::to_time_t(now);

        std::cout << "[" << std::put_time(std::localtime(&currentTime), "%Y%m%d_%H%M%S") << "] ";
    }
