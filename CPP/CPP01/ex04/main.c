/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 20:44:34 by sehwjang          #+#    #+#             */
/*   Updated: 2024/08/09 17:11:03 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

void replaceStringInFile(const std::string& filename, const std::string& s1, const std::string& s2) {
    std::ifstream inputFile(filename);
    if (!inputFile) {
        std::cerr << "Error: Could not open the input file." << std::endl;
        return;
    }

    std::string outputFilename = filename + ".replace";
    std::ofstream outputFile(outputFilename);
    if (!outputFile) {
        std::cerr << "Error: Could not open/create the output file." << std::endl;
        return;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
		std::string result;
        size_t pos = 0;
        while ((pos = line.find(s1, pos)) != std::string::npos) {
            result.append(line, 0, pos);
            result.append(s2);
            line = line.substr(pos + s1.length());
            pos = 0;
        }
        result.append(line);
        outputFile << result << std::endl;
    }
	
    inputFile.close();
    outputFile.close();
}

int main(int argc, char *argv[]){
	if (argc != 4){
		std::cout<<"Wrong input!"<<std::endl;
		return (1);
	}
	replaceStringInFile(argv[1], argv[2], argv[3]);
}