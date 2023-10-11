/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 11:29:33 by hucorrei          #+#    #+#             */
/*   Updated: 2023/10/06 11:37:44 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Base
{
	public:
		virtual ~Base() {};
		static Base * generate(void);
		void identify(Base* p);
		void identify(Base& p);
};

class A : public Base {};
class B : public Base {};
class C : public Base {};
