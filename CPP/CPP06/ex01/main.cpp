/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 18:27:05 by sehwjang          #+#    #+#             */
/*   Updated: 2024/12/30 18:39:54 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int main(){
	Data data;
	data.str = "Hello World!";
	data.n = 1234;

	std::cout << &data << " | " << data.str << " | " << data.n<<std::endl;

	Serializer s;
	Data *reserialized_struct = s.deserialize(s.serialize(&data));

	std::cout << reserialized_struct << " | " << reserialized_struct->str << " | " << reserialized_struct->n<<std::endl;
}