#include <stdio.h>
#include "array.hpp"

int main()
{
    std::Array<int> *m_Array = new Array<int>;
    m_Array -> Insert(5);
    m_Array -> Insert(10);
    m_Array -> Insert(6);

    m_Array->DebugDisplay();

    m_Array->Remove(2);

    m_Array->DebugDisplay();

    return 1;
}