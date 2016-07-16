#include <iostream>
#include <vector>

using namespace std;
int main()
{
    vector <int> preacher;         
    preacher.push_back(2202);         
    preacher.push_back(2101);        
    preacher.push_back(1101); 
	preacher.push_back(3101);
    
    for(int x=0; x<preacher.size(); x++) 
    {
        cout<<preacher[x]<<" ";    //Should output: 2202  2101  1101  3101
    }
    if(!preacher.empty())          //Checks if empty
        preacher.clear();          
    vector <int> another_vector;  
    another_vector.push_back(4110); 
    preacher.push_back(4110);        
    if(preacher==another_vector)   //To show testing equality
    {
        preacher.push_back(6120); 
    }
    for(int y=0; y<preacher.size(); y++)
    {
        cout<<preacher[y]<<" "<< endl;    
    }
   
    vector<int>::iterator it;  
	int n = 3;  // nth element to be found.
	int i = 3;  // counter.


	for(it=preacher.begin() ; it < preacher.end(); it++,i++ ) {
    
		if(i == n) {
			cout<< *it;  
			break;
		}
	}



    return 0;
}