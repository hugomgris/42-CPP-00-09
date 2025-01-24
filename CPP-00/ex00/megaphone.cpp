/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:12:12 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/01/23 18:16:04 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

/*class Megaphone {
	public:
		std::string msg;
	void shout(std::string words = "* loud and unbearable feedback noise *");
};

void Megaphone::shout(std::string words){
	for (int i = 0; words[i]; i++)
		std::isalpha(words[i]) ? std::cout << (unsigned char)std::toupper(words[i]) :  std::cout << words[i];
}

int	main(int argc, char **argv)
{
	Megaphone megaphone;
	int	i = 1;

	if (argc == 1)
	{
		megaphone.shout();
		return(0);
	}
	while (argv[i])
	{
		megaphone.shout((argv[i]));
		i++;
	}
	std::cout << std::endl;
	return (0);
}*/

int	main(int argc, char **argv)
{
	int	i = 1, j;

	if (argc < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			std::cout << (unsigned char)std::toupper(argv[i][j]);
			j++;
		}
		i++;
	}
	std::cout << std::endl;
}
