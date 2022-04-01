#ifndef LIST_HPP
# define LIST_HPP

# include <iostream>
# include <memory>

template <class T>
struct Node
{
    std::shared_ptr<T> data;
    std::shared_ptr<Node<T>> next;
};


template <class T>
class List
{
    private:
        std::shared_ptr<Node<T>> _List;
        std::shared_ptr<Node<T>> head;
        std::shared_ptr<Node<T>> tail;

    public:
        List();
        //CAPACITY
        bool    empty(void) const;
        size_t  size(void) const;

        //MODIFIERS
        void    push_back(const T &value);
        void    pop_back(void);
        void    push_front( const T &value );
        void    pop_front(void);
        void    print(void) const;

};


#endif