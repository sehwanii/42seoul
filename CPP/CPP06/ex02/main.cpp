/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 18:47:12 by sehwjang          #+#    #+#             */
/*   Updated: 2024/12/30 19:00:28 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main() {
	Base* test1;

	test1 = generate();
	identify(test1);
	identify(*test1);

	delete test1;
}