/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaisi <aalkaisi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 17:00:26 by aalkaisi          #+#    #+#             */
/*   Updated: 2024/07/13 17:37:23 by aalkaisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv)
{
	if (argc == 1)
		std::cout<<"* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		for (int i = 1; argv[i] != NULL; i++)
			for (int j = 0; argv[i][j] != '\0'; j++)
				std::cout<<(char)(std::toupper(argv[i][j]));
	}
	std::cout<<std::endl;
	return (0);
}
