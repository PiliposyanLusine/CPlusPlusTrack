#include <iostream>

int* foo_set(int*, int, int);
int* foo_reset(int*, int, int );

int main() {
    
    std::cout<<"Enter a size of bitSet: "<<std::endl;
    int bitSetSize = 0;
    std::cin>>bitSetSize;
    
    int arraySize = (bitSetSize/32)+1;
    
    std::cout<<"Creaded arrays "<<arraySize<<std::endl;
    int *arr = new int[arraySize];
    
    for(int i=0; i<arraySize; ++i)
    {
        arr[i]=0;
        std::cout<<"arr["<<i<<"] = "<<arr[i]<<std::endl;
    }
    
    do {
        int functionMap = 0;
        std::cout<<"Enter a function set or reset: for set enter 1 for reset enter 2"<<std::endl;
        std::cin>>functionMap;  
        
        if( (functionMap != 1) && (functionMap != 2)){
            std::cout<<"Enter a valid function number"<<std::endl;
            continue;
        }
        
        int index =0;
        std::cout<<"Enter a index"<<std::endl;
        std::cin>>index;
        
        if(functionMap == 1 )
        {
           arr = foo_set(arr,arraySize, index ); 
        } else {
            arr = foo_reset(arr,arraySize, index ); 
        }
        
        
        
        for(int i=0; i<arraySize; ++i)
        {
            std::cout<<"arr["<<i<<"] = "<<arr[i]<<std::endl;
        }
    }
    while (true);
}


int* foo_set(int *arr, int size, int index) {


    int arr_index = index/32;
    int bitIndex = index - (arr_index * 32);
    
    arr[arr_index] = arr[arr_index] + (1 << (bitIndex-1));
    return arr;
}

int* foo_reset(int *arr, int size, int index) {

    int arr_index = index/32;
    int bitIndex = index - (arr_index * 32);
    
    if(arr[arr_index] == 0) return arr;
    
    if((1 << (bitIndex-1)) > arr[arr_index]) 
    return arr;
    
    arr[arr_index] = arr[arr_index] - (1 << (bitIndex-1));
    return arr;
}
