/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:04:45 by hucorrei          #+#    #+#             */
/*   Updated: 2023/09/21 11:19:39 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void){

    ClapTrap Luffy("Luffy");
    ClapTrap Baggy("Baggy");

    Luffy.attack("Baggy");
    Baggy.takeDamage(2);
    Luffy.attack("Baggy");
    Baggy.takeDamage(2);
    Baggy.beRepaired(1);
    Luffy.attack("Baggy");
    Baggy.takeDamage(2);
    Luffy.attack("Baggy");
    Baggy.takeDamage(2);
    Luffy.attack("Baggy");
    Baggy.takeDamage(2);
    Luffy.attack("Baggy");
    Baggy.takeDamage(2);
    Luffy.attack("Baggy");
    Baggy.takeDamage(2);
    Luffy.attack("Baggy");
    Baggy.takeDamage(2);
    Luffy.attack("Baggy");
    Baggy.takeDamage(2);
    Luffy.attack("Baggy");
    Baggy.takeDamage(2);
    Luffy.attack("Baggy");
    Baggy.takeDamage(2);
    Luffy.attack("Baggy");
    Baggy.takeDamage(2);
    Luffy.attack("Baggy");
    Baggy.takeDamage(2);
    Luffy.attack("Baggy");
    Baggy.takeDamage(2);

    Baggy.beRepaired(10);

    return 0;
}
