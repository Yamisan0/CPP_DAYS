#include "BitcoinExchange.hpp"

int main(int ac, char **argv){
    (void)ac;

    if (ac > 2){
        std::cerr << "Error: Too much arguments." << std::endl;
    }
    std::ifstream dataFile, inputFile;

    inputFile.open(argv[1]);
    
    if (!(inputFile.is_open())){
        std::cerr << "Error: could not open input file." << std::endl;
        return -1;
    }

    dataFile.open("data.csv");
    if (!(dataFile.is_open())){
        std::cerr << "Error: could not open data file." << std::endl;
        return -1;
    }

    BitcoinExchange obj(dataFile);

    std::map<unsigned int, float>::iterator iter;

    if (obj.getError() == 1 )
        return (0);

    obj.displayResult(inputFile);

}