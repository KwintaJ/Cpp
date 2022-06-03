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
    T *array; // dynamic array
    int max_size;
    int size_;

public:
    /* constructors */
    Vector()
    {
        array = new T[8];
        max_size = 8;
        size_ = 0;
    }
    Vector(T &elements, int init_size)
    {
        max_size = init_size * 2;
        array = new T[max_size];
        for(size_ = 0; size_ < init_size; size_++)
        {
            array[size_] = elements;
        }
    }
    
    /* methods */
    void push_back(T &element)
    {
        if(size_ == max_size) // resize function
        {
            T *temporary_array = new T[2 * max_size];
            
            for(int i = 0; i < max_size; i++)
                temporary_array[i] = array[i];
               
            delete[] array;
            max_size *= 2;
            array = temporary_array;
        }
        
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
    T &operator[](int pos)
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
    
    /* reverse iterator */
    class reverse_iterator
    {
    private:
        T* pos;
        
    public:
        reverse_iterator(T* p): pos(p) 
        {
        }

        reverse_iterator(): pos(0)
        {
        }

        T &operator*()
        { 
            return *pos;
        }

        T *operator->()
        {
            return &pos;
        }

        reverse_iterator operator++(int)
        {
            pos--; 
            return *this; 
        }

        reverse_iterator operator--(int)
        {
            pos--; 
            return *this; 
        }

        bool operator!=(const reverse_iterator &X)
        {
            return this->pos != X.pos; 
        }
    };
    
    reverse_iterator rbegin()
    { 
        return &array[size_ - 1];
    }
    reverse_iterator rend()
    {
        reverse_iterator it = &array[0];
        it--;
        return it; 
    }
};

#endif

