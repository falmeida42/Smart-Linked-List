#ifndef LIST_H
# define LIST_H

# include <iostream>
# include <memory>

template <class T>
class Node
{
    public:
        std::shared_ptr<T> data;
        std::shared_ptr<Node<T>> next;
        Node(void);
};


template <class T>
class List
{
    private:
        std::shared_ptr<Node<T>> List;
    public:
        List();
        void    insert(const T data);
        void    delet(void);
        void    search(const T data) const;
        void    print(void) const;

};


#endif