/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberenge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 15:23:03 by aberenge          #+#    #+#             */
/*   Updated: 2025/09/14 12:24:01 by aberenge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>
#include "Data.hpp"

void	print_data(const Data* data)
{
	std::cout << "Data address: " << data << std::endl;
	std::cout << "Value: " << data->value << std::endl;
	std::cout << "Name: " << data->name << std::endl;
	std::cout << "Grade: " << data->grade << std::endl;
}

void	test_serialization()
{
	Data		original;
	Data*		deserialized;
	uintptr_t	serialized;

	original.value = 42;
	original.name = "Student";
	original.grade = 'A';

	std::cout << "ORIGINAL DATA" << std::endl;
	print_data(&original);

	serialized = Serializer::serialize(&original);
	std::cout << std::endl << "Serialized value: " << serialized << std::endl;

	deserialized = Serializer::deserialize(serialized);
	print_data(deserialized);

	std::cout << std::endl << "Pointers equal: ";
	std::cout << (&original == deserialized ? "YES" : "NO");
	std::cout << std::endl;
}

int	main(void)
{
	test_serialization();
	return (0);
}
