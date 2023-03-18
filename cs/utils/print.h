#include<iostream>
void print_int_arr(int arr[], int length){
    for(int i = 0;i < length;i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}