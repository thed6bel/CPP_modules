/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 09:47:38 by hucorrei          #+#    #+#             */
/*   Updated: 2023/08/04 10:53:00 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
	public:
		PhoneBook			(void);
		~PhoneBook			(void);
		void				search_contact();
		void				add_contact();		
	private:
		Contact				_contacts[8];
		int					_buff;
};

#endif
