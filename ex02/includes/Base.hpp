/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberenge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 10:46:17 by aberenge          #+#    #+#             */
/*   Updated: 2025/09/15 12:48:08 by aberenge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

class Base
{
	public:
		virtual ~Base();
};

class A: public Base
{};

class B: public Base
{};

class C: public Base
{};

Base	*generate(void);
void	identify(Base *p);
void	identify(Base &p);

#endif
