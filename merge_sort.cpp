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
void merge(vector<int> &ptr, int left, int mid, int right, int &count){
    const int length_array1= mid -left +1;
    const int length_array2 = right - mid;
    int left_arr[length_array1];
    int right_arr[length_array2];
    for(int i = 0 ; i < length_array1; i++){
        left_arr[i] = ptr[left+i];
    }
    for(int i =0 ; i < length_array2; i++){
        right_arr[i] = ptr[i+1+mid];
    }
    int index_arr1 = 0, index_arr2 = 0;
    int index_merge = left;
    while(index_arr1 < length_array1 && index_arr2 < length_array2){
        if(left_arr[index_arr1] <= right_arr[index_arr2]){
            ptr[index_merge] = left_arr[index_arr1];
            index_arr1++;
            count++;
        }
        else{
            ptr[index_merge] = right_arr[index_arr2];
            index_arr2++;
            count++;
        }
        index_merge++;
    }
    while (index_arr1 < length_array1){ //when left subarray is longer than the right one
        ptr[index_merge] = left_arr[index_arr1];
        index_merge++;
        index_arr1++;
         count++;}
    while (index_arr2 < length_array2){ //when right subarray is longer than the left one
        ptr[index_merge] = right_arr[index_arr2];
        index_merge++;
        index_arr2++;
         count++;
    }
};

void merge_sort(vector <int> &ptr, int begin, int end, int & count){
    if(begin < end){
    int mid =  begin + (end-begin)/2;
    merge_sort(ptr, begin, mid, count);
    merge_sort(ptr, (mid+1), end, count);
    merge(ptr, begin, mid, end, count);}
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

    merge_sort(test_values,0, VECTOR_SIZE-1,comp_ran); 
    merge_sort(asc_test_values,0,VECTOR_SIZE-1,comp_asc); 
    merge_sort(desc_test_values,0,VECTOR_SIZE-1, comp_desc); 
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


