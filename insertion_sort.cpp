#include <iostream> 
#include <vector>
using namespace std;


unsigned get_rand_in_range(unsigned low, unsigned high);

void printArray(vector <int> ptr, int size, int begin = 0){
    for (int i = begin; i < size; i++){
        cout << ptr[i] << " ";
    }
    cout << endl;
};
//key holds tempo value. find where key would be appropriate and place it in index. 
int insertion_sort(vector <int> & ptr, int size){
    int count = 0;
    int key;
    for (int i = 0; i < size; i++){
        key = ptr[i]; 
        int j = i - 1;
        while (j >= 0 && ptr[j] > key ){ //comparison is another step
            count++;
            ptr[j+1] = ptr[j];
            count++; //swapping array element
            j = j-1;
        }
        ptr [j+1] = key;  
        count++; //swapping element
    }
    return count;
};
int main() {
    srand(time(0)); // in order to generate random numbers
    const int VECTOR_SIZE = 50000;
    vector<int> test_values;
    double sumOfComparison = 0;
    int comp_ran=0, comp_asc=0, comp_desc=0;
    test_values.clear();
    // generating 1000 random values and storing them to the vector
    for(int k=0;k<VECTOR_SIZE;k++)
    {
      int value = get_rand_in_range(1, VECTOR_SIZE);
      test_values.push_back(value); 
    }
    vector<int> asc_test_values = test_values;
    vector<int> desc_test_values = test_values;
    sort(asc_test_values.begin(), asc_test_values.end());
    sort(desc_test_values.begin(), desc_test_values.end(), greater<int>());
    comp_ran = insertion_sort(test_values, VECTOR_SIZE);
    comp_asc = insertion_sort(asc_test_values, VECTOR_SIZE);
    comp_desc = insertion_sort(desc_test_values, VECTOR_SIZE);
    //}
    sumOfComparison = comp_ran + comp_asc + comp_desc;
    cout<<"\nNumber of comparisons in random vector: " <<comp_ran<<endl; // /simul_size
    cout<<"\nNumber of comparisons in ascending vector: " <<comp_asc<<endl;
    cout<<"\nNumber of comparisons in descending vector: " <<comp_desc<<endl;
    cout<<"\nAverage number of comparisons: " <<sumOfComparison/3<<endl;
    return 0;
}
unsigned get_rand_in_range(unsigned low, unsigned high)
{
  int random_number=0;
  // generate the random number
  random_number = low + rand() % (high - low + 1);
  return random_number;
}
