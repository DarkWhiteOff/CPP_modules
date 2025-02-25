#include "Account.hpp"
#include "iostream"
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

// CONSTRUCTOR
Account::Account(void) : _accountIndex(_nbAccounts), _amount(0),
                    _nbDeposits(0), _nbWithdrawals(0)
{
    _nbAccounts++;
    return ;
}
Account::Account(int initial_deposit) : _accountIndex(_nbAccounts), _amount(initial_deposit),
                    _nbDeposits(0), _nbWithdrawals(0)
{
    _nbAccounts++;
    _totalAmount += initial_deposit;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
            << ";amount:" << _amount << ";created"
            << std::endl;
    return ;
}
// DESTRUCTOR
Account::~Account(void)
{
    _nbAccounts--;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
            << ";amount:" << _amount << ";closed"
            << std::endl;
    return ;
}

int	Account::getNbAccounts( void )
{
    return (_nbAccounts);
}

int	Account::getTotalAmount( void )
{
    return (_totalAmount);
}

int	Account::getNbDeposits( void )
{
    return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
    return (_totalNbWithdrawals);
}

void	Account::_displayTimestamp( void )
{
    std::time_t t = std::time(0);
    std::tm* now = std::localtime(&t);
    std::cout << "[" << (now->tm_year + 1900);
    if ((now->tm_mon + 1) < 10)
        std::cout << "0";
    std::cout << (now->tm_mon + 1);
    std::cout << now->tm_mday << "_";
    if ((now->tm_hour) < 10)
        std::cout << "0";
    std::cout << now->tm_hour;
    if ((now->tm_min) < 10)
        std::cout << "0";
    std::cout << now->tm_min;
    if ((now->tm_sec) < 10)
        std::cout << "0";
    std::cout << now->tm_sec;
    std::cout << "] ";
}

void	Account::displayAccountsInfos( void )
{
    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts
        << ";total:" << _totalAmount << ";deposits:"
        << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals
        << std::endl;
}

void	Account::displayStatus( void ) const
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
        << ";amount:" << _amount << ";deposits:"
        << _nbDeposits << ";withdrawals:" << _nbWithdrawals
        << std::endl;
}

void	Account::makeDeposit( int deposit )
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
        << ";p_amount:" << _amount << ";deposit:"
        << deposit << ";amount:" << (_amount + deposit)
        << ";nb_deposits:" << ++_nbDeposits << std::endl;
        _amount += deposit;
        _totalAmount += deposit;
        _totalNbDeposits++;
}

int		Account::checkAmount( void ) const
{
    return (_amount);
}

bool	Account::makeWithdrawal( int withdrawal )
{
    _displayTimestamp();
    if ((checkAmount() - withdrawal) >= 0)
    {
        std::cout << "index:" << _accountIndex
            << ";p_amount:" << _amount << ";withdrawal:"
            << withdrawal << ";amount:" << (_amount - withdrawal)
            << ";nb_withdrawals:" << ++_nbWithdrawals
            << std::endl;
            _amount -= withdrawal;
            _totalAmount -= withdrawal;
            _totalNbWithdrawals++;
    }
    else
    {
        std::cout << "index:" << _accountIndex
            << ";p_amount:" << _amount << ";withdrawal:refused"
            << std::endl;
    }
    return (true);
}