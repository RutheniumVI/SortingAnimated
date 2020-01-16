#ifndef SORTINGALGORITHMS_H
#define SORTINGALGORITHMS_H

#include <vector>

template <typename T>
class SortingAlgorithms
{

public:
    SortingAlgorithms(){
    }
    virtual void swap(T &a, T &b) {
        T temp = a;
        a = b;
        b = temp;
    }

    void SelectionSort(std::vector<T> &arr){

        int len  = arr.size();
        T lowest;
        int lowest_index;
        for(int i=0; i<len; i++){
            lowest  =  arr[i];
            lowest_index = i;
            for(int j=i; j<len; j++){
                if(*(arr[j])<*lowest){
                    lowest = arr[j];
                    lowest_index = j;
                }
            }

            swap(arr[lowest_index], arr[i]);
        }
    }

    void BubbleSort(std::vector<T> &arr){
        int len = arr.size();
        bool swapped;
        for(int i=0;i<len-1;i++){
            swapped = false;
            for(int j=0;j<len-1-i;j++){
                if(*(arr[j+1])<*(arr[j])){
                    swapped = true;
                    swap(arr[j], arr[j+1]);
                }
            }
            if(!swapped)
                break;
        }
    }
};

#endif // SORTINGALGORITHMS_H
