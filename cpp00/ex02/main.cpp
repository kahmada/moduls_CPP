/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahmada <kahmada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:58:36 by kahmada           #+#    #+#             */
/*   Updated: 2024/12/05 15:00:03 by kahmada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>

int main()
{
    Account::displayAccountsInfos();

    Account account1(100); //hadi rah functiuon ya3ni hiya responsable 3la had message [20241205_145729] index:0;amount:100;created
    Account account2(200);
    Account account3(300);

    account1.displayStatus();
    account2.displayStatus();
    account3.displayStatus();
    account1.makeDeposit(50);
    account2.makeDeposit(20);
    account3.makeDeposit(300);
    account1.makeWithdrawal(30);
    account2.makeWithdrawal(150);
    account3.makeWithdrawal(500);  // Should fail due to insufficient funds

    // Display status of individual accounts after transactions
    account1.displayStatus();
    account2.displayStatus();
    account3.displayStatus();

    // Display overall account information
    Account::displayAccountsInfos();

    return 0;
}
