/*
 *	Author	:	Manjeet Kumar <kumar.manjeet13@gmail.com>
 *	Date	:	5th March 2017
 */

#include <iostream>
#include <vector>

using namespace std;


int main(){
	int decimal_number;

	cout << "Enter the decimal number" << endl;
	cin >> decimal_number;

	vector<int> binary_place;       //vector for storing bit positions
	int count_bit_place = 0;

	while(decimal_number){
		if(decimal_number&1)
			binary_place.push_back(count_bit_place);   //push positions of 1 into the vector as they come
		decimal_number>>=1;
		count_bit_place++;
	}

    //printing the result
	cout << endl << "The position of 1s in binary from LSB to MSB is: " << endl;
	for(unsigned int counter=0; counter < binary_place.size(); counter++)
		cout << binary_place[counter] << " ";
	cout << endl;
	return 0;
}

/*
 *	Author	:	Manjeet Kumar <kumar.manjeet13@gmail.com>
 *	Date	:	5th March 2017
 */
