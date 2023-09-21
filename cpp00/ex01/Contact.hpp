/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thed6bel <thed6bel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 09:47:43 by hucorrei          #+#    #+#             */
/*   Updated: 2023/08/23 21:32:48 by thed6bel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <iostream>
# include <iomanip>
# include <string>
# include <limits>
# include <cstdlib>

class Contact
{
	public:
		Contact			(void);
		~Contact		(void);
		void			add_contact(int buff);
		void			search_contact(int p, int char_disp);
		std::string		info[6];
		
	private:
		std::string		_index;
		std::string		_first_name;
		std::string		_last_name;
		std::string		_nickname;
		std::string		_phone_number;
		std::string		_darkest_secret;
		std::string		_obj[6];
};

#endif
