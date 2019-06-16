#include <iostream>
#include <algorithm>
#include <vector> 

//TColon 
//Short program to find the longest key schedule available 
//in a 2x2 matrix mod 10:  

using namespace std;

int det (vector<int>arr){
	return arr[0] * arr[3] - arr[1] * arr[2];
}//end det()

void printMatrix(vector<int>arr)
{
	cout << arr[0] << " " << arr[1] << endl << arr[2] << " " << arr[3] << endl;  		
}//end printMatrix()
	
int returnKeySchedule (vector<int>arr)
{
	int lengthOfSchedule = 1;
	vector<int> starting = arr; 
	vector<int> temp = arr; 
	bool startValuesAreEqual = false;
	
	while (startValuesAreEqual == false){
		//set up a temp array so that later calculations arent affected by earlier ones 
		temp = arr; 
		//this is the power step:
		//the new arr value is equal to the old arr values times the original matrix: 
		arr[0] = ( (temp[0] * starting[0]) + (temp[1] * starting[2]) ) % 10; 
		arr[1] = ( (temp[0] * starting[1]) + (temp[1] * starting[3]) ) % 10;
		arr[2] = ( (temp[2] * starting[0]) + (temp[3] * starting[2]) ) % 10; 
		arr[3] = ( (temp[2] * starting[1]) + (temp[3] * starting[3]) ) % 10; 
		
		lengthOfSchedule++;
		
		//if the values of the matrix match the start values, the schedule has been determined 
		if (arr[0] == starting[0] && arr[1] == starting[1] && arr[2] == starting[2] && arr[3] == starting[3]){
			startValuesAreEqual = true; 
		}//end if 
		
	}//end while loop
	return lengthOfSchedule; 
	
}//end returnKeySchedule()

int main()
{
	vector<int>arr (4,0);
	vector<int>longest (4,0); 
	int longestScheduleValue = 0;
	int tempScheduleValue = 0; 
	
	//generate all matrices below 101 in all positions:
	//1000  1000
	//1000  1000
	
	for (int i = 0; i < 10; i++){
		arr[0] = i;
		
		for (int j = 0; j < 10; j++){
			arr[1] = j; 
			
			for (int k = 0; k < 10; k++){
				arr[2] = k;
				
				for (int l = 0; l < 10; l++){
					arr[3] = l; 
					
					if (det(arr) != 0){

						tempScheduleValue = returnKeySchedule(arr); 
						if (tempScheduleValue > longestScheduleValue){
							longest = arr; 
							longestScheduleValue = tempScheduleValue; 
						}//end inner if
					}//end outer if 
				
					else{}
				
				}//end l-loop
			}//end k-loop			
		}//end j-loop
	}//end i-loop
	
	printMatrix(longest);
	cout << endl << "Has a key schedule of: " << longestScheduleValue << endl;  
	
}//end main()
