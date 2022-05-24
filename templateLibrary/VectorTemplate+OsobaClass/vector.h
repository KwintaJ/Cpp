//############################################//
//                                            //
//    Jan Kwinta                24.05.2022    //
//                                            //
//    Projekt: C++ templatka vectora          //
//                                            //
//    vector.h                                //
//                                            //
//############################################//

#include <cstdio>

#ifndef VECTOR_H
#define VECTOR_H

template<typename T>
class Vector
{
private:
    T array[100];
    int size_ = 0;

public:
    /* constructors */
    Vector(): size_(0)
    {
    }
    Vector(T elements, int init_size)
    {
        for(size_ = 0; size_ < init_size; size_++)
        {
            array[size_] = elements;
        }
    }
    
    /* methods */
    void push_back(T element)
    {
        array[size_] = element;
        size_++;
    }
    T pop_back()
    {
        if(size_ == 0)
            return NULL;
            
        size_--;
        return array[size_];
    }
    T operator[](int pos)
    {
        return array[pos];
    }
    int size()
    {
        return size_;
    }
    
    /* iterator */
    typedef T* iterator;
    iterator begin()
    {
        return &array[0];
    }
    iterator end()
    {
        return &array[size_];
    }
};

#endif

