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
int partition(vector <int> &ptr, int begin, int end, int &count){
    int pivot = ptr[begin];
    int k = 0;
    for( int i = begin+1; i <= end; i++) {
        if(ptr[i]<= pivot) k++; count++;}
        int pivotIndex = begin+k;
        int temp = ptr[pivotIndex];
        ptr[pivotIndex] = ptr[begin];
        ptr[begin] = temp;
        count++;
        int i = begin, j = end; 
        while( i < pivotIndex && j > pivotIndex){
            while (ptr[i] <= pivot) i++;
            while (ptr[j] > pivot) j--;
            if (i < pivotIndex && j > pivotIndex) {
            int index1 = i++, index2 = j--;
            int tempo = ptr[index1];
            ptr[index1] = ptr[index2];
            ptr[index2] = tempo;
            count++;}
        }
        return pivotIndex;
};

void quick_sort(vector <int> &ptr, int begin, int end, int &count){
    if(begin >= end){return;}
    count++;
    int p = partition(ptr, begin, end, count);
    quick_sort(ptr, begin, p-1, count);
    quick_sort(ptr, p+1, end, count);
};
int main() {
    srand(time(0)); // in order to generate random numbers
    const int VECTOR_SIZE = 50000;
    vector<int> test_values;
    double sumOfComparison = 0;
    int comp_ran=0, comp_asc=0, comp_desc=0;
//    for(int i=0;i<SIMUL_SIZE; i++)
//     { 
    // clearing the vector, so, we can start with an empty vector
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

    quick_sort(test_values,0, VECTOR_SIZE-1,comp_ran ); 
    quick_sort(asc_test_values,0,VECTOR_SIZE-1,comp_asc); 
    quick_sort(desc_test_values,0,VECTOR_SIZE-1, comp_desc); 
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

