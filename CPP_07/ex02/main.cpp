#include "Array.hpp"

int main() 
{
	std ::cout << "========== SIMPLE TYPE ==========" << std::endl << std::endl;

    std::cout << "----- TEST : EMPTY ARRAY -----" << std::endl;
    Array<int> emptyArray;
    std::cout << "Empty array created. Size : " << emptyArray.size() << std::endl;

    std::cout << "----- TEST : ARRAY OF SPECIFIC SIZE -----" << std::endl;
    Array<int> sizeArray(5);
    std::cout << "Array of size 5 created. Size : " << sizeArray.size() << std::endl;

    std::cout << "----- TEST : WRITING -----" << std::endl;
    for (unsigned int i = 0; i < sizeArray.size(); i++) 
	{
        sizeArray[i] = i * 10;
    }

    std::cout << "Writing completed" << std::endl;

    std::cout << "----- TEST : READING -----" << std::endl;
    for (unsigned int i = 0; i < sizeArray.size(); i++) 
	{
        std::cout << "Element " << i << ": " << sizeArray[i] << std::endl;
    }

	std::cout << "----- TEST : READING (CONST) -----" << std::endl;
	const Array<int> constArray = sizeArray;
    std::cout << "Reading from a const instance: " << std::endl;
  	for (unsigned int i = 0; i < constArray.size(); i++) 
	{
        std::cout << "Element " << i << ": " << constArray[i] << std::endl;
    }
	std::cout << std::endl;

	std ::cout << "========== COMPLEX TYPE ==========" << std::endl;
	
	std::cout << "\n----- TEST : ARRAY OF STRINGS -----" << std::endl;
    Array<std::string> stringArray(5);
    std::cout << "String array of size 5 created. Size : " << stringArray.size() << std::endl;

    std::cout << "----- TEST : WRITING TO STRING ARRAY -----" << std::endl;
    stringArray[0] = "One";
    stringArray[1] = "must";
    stringArray[2] = "imagine";
	stringArray[3] = "Sisyphus";
	stringArray[4] = "happy";

    std::cout << "Writing completed" << std::endl;

    std::cout << "----- TEST : READING FROM STRING ARRAY -----" << std::endl;
    for (unsigned int i = 0; i < stringArray.size(); i++) 
    {
        std::cout << "Element " << i << ": " << stringArray[i] << std::endl;
    }
	std::cout << std::endl;

	std ::cout << "========== TEST : OUT OF RANGE ==========" << std::endl << std::endl;

    try 
	{
        std::cout << "Tryin to  access an element that is out of range : ";
        int outOfRangeValue = sizeArray[10];
		(void)outOfRangeValue;
    } 
	catch (const std::exception &e) 
	{
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}