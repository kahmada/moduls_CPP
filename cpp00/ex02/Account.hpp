/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahmada <kahmada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:53:35 by kahmada           #+#    #+#             */
/*   Updated: 2024/12/05 14:09:36 by kahmada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

class Account {
private:
    static int _nbAccounts;
    static int _totalAmount;
    static int _totalNbDeposits;
    static int _totalNbWithdrawals;

    int _accountIndex;
    int _amount;
    int _nbDeposits;
    int _nbWithdrawals;

    static void _displayTimestamp();
public:
    Account(int initial_deposit);
    ~Account();

    void makeDeposit(int deposit);
    bool makeWithdrawal(int withdrawal);
    int checkAmount() const;
    void displayStatus() const;
    static void displayAccountsInfos();
};
#endif