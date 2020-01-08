#ifndef SORTINGALGORITHMS_H
#define SORTINGALGORITHMS_H

#include <vector>

template <typename T>
class SortingAlgorithms
{
public:
    SortingAlgorithms(){

    }
    static void swap(T &a, T &b) {
        T::swap();
        T temp = a;
        a = b;
        b = temp;
    }
    static void SelectionSort(std::vector<T> &arr)
    {

        int len  = arr.size();
        std::vector<T> arr2;
        T lowest;
        int lowest_index;
        for(int i=0;i<len;i++){
            lowest  =  arr[0];
            lowest_index = 0;
            for(int j=0;j<arr.size();j++){
                //int a = arr[j]->value();
                if(*(arr[j])<*lowest){
                    lowest = arr[j];
                    lowest_index = j;
                }
            }

            arr2.push_back(lowest);
            arr.erase(arr.begin()+lowest_index);
        }
        arr=arr2;
    }
    static void SelectionSort2(std::vector<T> &arr)
    {

        int len  = arr.size();
        T lowest;
        int lowest_index;
        for(int i=0;i<len;i++){
            lowest  =  arr[i];
            lowest_index = i;
            for(int j=i;j<len;j++){
                if(*(arr[j])<*lowest){
                    lowest = arr[j];
                    lowest_index = j;
                }
            }

            swap(arr[lowest_index], arr[i]);
        }
    }
};

#endif // SORTINGALGORITHMS_H
