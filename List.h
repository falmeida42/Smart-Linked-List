#ifndef LIST_H
# define LIST_H

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
    public:
        List();
        void    pushback(const T &value);
        void    delet(void);
        void    search(const T data) const;
        void    print(void) const;

};


#endif