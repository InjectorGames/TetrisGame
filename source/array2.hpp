#pragma once
#include <QException>

template<typename T, size_t sx, size_t sy>
struct Array2
{
protected:
    T items[sx][sy];

public:
    inline T get(size_t x, size_t y)
    {
        if(x >= sx || y >= sy)
            throw QException();
        return items[y][x];
    }
    inline void set(size_t x, size_t y, T item)
    {
        if(x >= sx || y >= sy)
            throw QException();
        items[y][x] = item;
    }

    inline T getUnsafe(size_t x, size_t y)
    {
       return items[y][x];
    }
    inline void setUnsafe(size_t x, size_t y, T item)
    {
        items[y][x] = item;
    }
};
