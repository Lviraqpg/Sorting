
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
            tmp[i] = this->length-1;
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



};



int main(){
 int* arr= new int[5];
 arr[0]=1;  arr[1]=5; arr[2]=7; arr[3]=0; arr[4]=3;
 Sorting <int> s(arr, 5);
 s.printArr();
 s.addValue(99);
 s.printArr();

}
