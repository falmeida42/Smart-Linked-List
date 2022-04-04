#ifndef LIST_HPP
# define LIST_HPP

# include <iostream>
# include <memory>
# include <bits/stdc++.h>

template <class T>
struct Node
{
    std::shared_ptr<T> data;
    std::shared_ptr<Node<T>> next;
    std::weak_ptr<Node<T>> prev;
    
};


template <class T>
class List
{
    private:
        std::shared_ptr<Node<T>> head;
        std::shared_ptr<Node<T>> tail;

    public:
        List();

        //ELEMENT ACESS
        T&      front(void);
        T&      back(void);

        //CAPACITY
        bool    empty(void) const;
        size_t  size(void) const;
        void clear();

        //MODIFIERS
        size_t  get_size(void) {return (size);};
        void    push_back(const T &value);
        void    pop_back(void);
        void    push_front( const T &value );
        void    pop_front(void);
        void    print(void) const;
        void    reverseprint(void) const;
};


#endif