#include <algorithm>
#include <utility>

#ifndef LIST_H
#define LIST_H

template<typename T>
struct ListNode
{
    ListNode(const T &e): data(e), next(nullptr), prev(nullptr)
    {
    }

    T data;
    ListNode<T> *next;
    ListNode<T> *prev;
};

template<typename T>
class List
{
private:
    ListNode<T> *head;
    ListNode<T> *tail;
    int listSize;

public:
    /* iterator */
    class iterator
    {
    private:
        ListNode<T> *position_;

    public:
        iterator(ListNode<T> *p = nullptr): position_(p)
        {
        }

        T &operator*()
        {
            return position_->data;
        }
        T *operator->()
        {
            return &(position_->data);
        }
        bool operator!=(const iterator &X)
        {
            return this->position_ != X.position_;
        }
        iterator operator++()
        {
            position_ = position_->next;
            return *this;
        }
        iterator operator--()
        {
            position_ = position_->prev;
            return *this;
        }
        iterator operator++(int)
        {
            ListNode<T> *help = position_;
            position_ = position_->next;
            return iterator{help};
        }
        iterator operator--(int)
        {
            ListNode<T> *help = position_;
            position_ = position_->prev;
            return iterator{help};
        }
    };

    /* reverse iterator */
    class reverse_iterator
    {
    private:
        ListNode<T> *position_;

    public:
        reverse_iterator(ListNode<T> *p = nullptr): position_(p)
        {
        }

        T &operator*()
        {
            return position_->data;
        }
        T *operator->()
        {
            return &(position_->data);
        }
        bool operator!=(const reverse_iterator &X)
        {
            return this->position_ != X.position_;
        }
        reverse_iterator operator++()
        {
            position_ = position_->prev;
            return *this;
        }
        reverse_iterator operator--()
        {
            position_ = position_->next;
            return *this;
        }
        reverse_iterator operator++(int)
        {
            ListNode<T> *help = position_;
            position_ = position_->prev;
            return reverse_iterator{help};
        }
        reverse_iterator operator--(int)
        {
            ListNode<T> *help = position_;
            position_ = position_->next;
            return reverse_iterator{help};
        }
    };

    /* constructors */
    List(): head(nullptr), tail(nullptr), listSize(0)
    {
    }

    ~List()
    {
        ListNode<T> *nowAccessed{head};

        while(nowAccessed != nullptr)
        {
            ListNode<T> *nextAccessed{nowAccessed->next};
            delete nowAccessed;
            nowAccessed = nextAccessed;
        }
    }

    /* methods */
    int size() const
    {
        return listSize;
    }
    T front()
    {
        return head->data;
    }
    T back()
    {
        return tail->data;
    }
    ListNode<T>* insert(const T &e, ListNode<T> *position)
    {
        ListNode<T> *n = new ListNode<T>(e);
        listSize++;

        n->next = position;

        if(position != nullptr)
        {
            n->prev = position->prev;
            position->prev = n;
        }
        else
        {
            n->prev = tail;
            tail = n;
        }

        if(n->prev != nullptr)
            n->prev->next = n;
        else
            head = n;

        return n;        
    }
    void remove(ListNode<T> *position)
    {
        if(position == nullptr)
            return;

        if(position->prev != nullptr)
            position->prev->next = position->next;

        if(position->next != nullptr)
            position->next->prev = position->prev;

        if(position == head)
            head = position->next;

        if(position == tail)
            tail = position->prev;
        
        delete position;
        listSize--;  
    }

    void push_back(const T &e)
    {
        insert(e, 0);
    }
    void push_front(const T &e)
    {
        insert(e, head);
    }
    void pop_back()
    {
        remove(tail);
    }
    void pop_front()
    {
        remove(head);
    }
    iterator begin()
    { 
        return iterator{head};
    }
    iterator end()
    {
        return iterator{nullptr}; 
    }
    reverse_iterator reverse_begin()
    { 
        return reverse_iterator{tail};
    }
    reverse_iterator reverse_end()
    {
        return reverse_iterator{nullptr}; 
    }
    void sort()
    {
        if(listSize < 2)
            return; 

        for(int i = 0; i < listSize; i++)
        {
            for(iterator it1 = begin(); it1 != iterator{tail}; ++it1)
            {
                iterator it2 = it1;
                ++it2;
                if((*it2) < (*it1))
                    std::swap(*it1, *it2);
            }
        }
    }
};

#endif