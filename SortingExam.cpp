
#include <iostream>

template<class T>
class Sorting{
private:
    size_t length;
    std::shared_ptr<T[]>arr;

public:
    Sorting(): length(0){
        this->arr=std::make_shared<T[]>(0);
    }
    Sorting (T* &arr_, int length_): length(length_) {
        this->arr=std::make_shared<T[]>(this->length);
        for (int i=0; i<this->length; i++){
            this->arr[i]=arr_[i];
        }
    }

    void addValue(T value){
        this->length++;
        std::shared_ptr<T[]>tmp=std::make_shared<T[]>(this->length);
        for (int i=0; i<this->length-1; i++){
            tmp[i] = this->arr[i];
        }
        tmp[this->length-1]=value;
        this->arr.swap(tmp);
    }
    void printArr(){
        for(int i=0; i<length; i++){
            std::cout<<this->arr[i]<<" ";
        }
        std::cout<<std::endl;
    }

    void bubbleSort (){
        T tmp;
        for (int i=0; i< this->length-1; i++){
            for(int j=0; j< this->length-1-i; j++){
                if(this->arr[j]>this->arr[j+1]){
                    tmp=this->arr[j];
                    this->arr[j]=this->arr[j+1];
                    this->arr[j+1]=tmp;
                }
            }
        }
    }

    void selectionSort(){
        T tmp;
        T min_index;
        for(int i=0; i<this->length; i++){
            min_index=i;
            for(int j=i+1; j<this->length; j++){
                if(this->arr[min_index]>this->arr[j]){
                    min_index=j;
                }
                if(min_index!=1){
                    tmp=this->arr[i];
                    this->arr[i]=this->arr[min_index];
                    this->arr[min_index]=tmp;
                }
            }
        }
    }

    void insertionSort(){
        T key;
        T j;
        for(int i=1; i<this->length; i++){
            key=this->arr[i];
            j=i-1;
            while(j>=0 && this->arr[j]>key){
                this->arr[j+1]=this->arr[j];
                j-=1;
            }
           this->arr[j+1]=key;
        }
    }
 void hoareSort(T*& arr, T left, T right) {
     if (left > right) return;
     T tmp;
     T i = left-1; // = this->arr[0];
     T j = right+1; // = this->arr[length - 1];
     T middle = this->arr[(right + left) / 2];
     while (left <= right) {
         while (this->arr[i] < middle) left++;
         while (this->arr[j] > middle) right--;
         if (i >= j) {return;}
         else{
             tmp = this->arr[i];
             this->arr[i] = this->arr[j];
             this->arr[j] = tmp;
             i++;
             j--;
         }
     }
     hoareSort(arr, left, j);
     hoareSort(arr, i, right);
 }
};



int main(){
 int* arr= new int[5];
 arr[0]=1;  arr[1]=5; arr[2]=7; arr[3]=0; arr[4]=3;
 int* arr1= new int[5];
 arr1[0]=1;  arr1[1]=5; arr1[2]=7; arr1[3]=0; arr1[4]=3;
 int* arr2= new int[6];
 arr2[0]=22;  arr2[1]=45; arr2[2]=7; arr2[3]=9; arr2[4]=0;arr2[5]=39;
 int* arr3= new int[4];
 arr3[0]=22;  arr2[1]=45; arr2[2]=7; arr2[3]=9;
 int n= sizeof(arr)/sizeof(arr[0]);
 Sorting <int> s(arr,5);
 Sorting <int> s1(arr1,5);
 Sorting <int> s2(arr2,6);
 Sorting <int> s3(arr2,4);
 s.printArr();
 s.addValue(99);
 s.addValue(57);
 s.addValue(34);
 s.addValue(44);
 s.addValue(32);
 s.printArr();
 s.bubbleSort();
 s.printArr();
 s1.addValue(6);
 s1.addValue(76);
 s1.addValue(99);
 s1.addValue(2);
 s1.printArr();
 s1.insertionSort();
 s.printArr();
 s2.selectionSort();
 s2.printArr();
 s3.hoareSort(arr3, 0, n-1);
 for (int i=0; i<n; i++){
     std::cout<<arr[i]<<" ";
    }
    std::cout<<std::endl;
}

