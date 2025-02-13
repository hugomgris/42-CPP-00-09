/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileReplacer.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 08:51:14 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/02/12 10:16:40 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILEREPLACER_HPP
# define FILEREPLACER_HPP

#include <iostream>
#include <fstream>

# define OPEN_IERROR "Error: unable to open input file"
# define GEN_IERROR "Error: general error while input file handling"
# define OPEN_OERROR "Error: unable to open output file"
# define GEN_OERROR "Error: general error while output file handling"

class FileReplacer{
	private:
		const std::string _filename;
		const std::string _s1;
		const std::string _s2;
	
	public:
		FileReplacer(const std::string &filename, const std::string &s1, const std::string &s2);
		~FileReplacer();

		bool replaceInFile();
};

#endif