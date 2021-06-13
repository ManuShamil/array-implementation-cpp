#include <stdio.h>
#include "array.hpp"

int main()
{
    std::Array<int> *m_Array = new Array<int>;
    m_Array -> Insert(5);
    m_Array -> Insert(10);

    printf( "%d", m_Array->Get(1) );

    return 1;
}