#include <stdio.h>
#include <iostream>

template<typename T>
class Element 
{
    T myValue;
    Element<T> *next;
    Element<T> *previous;
    public:

        Element(T a)
        {
            myValue = a;
            next = NULL;
            previous = NULL;
        }

        void SetNextElement(Element<T> *a)
        {
            next = a;
        }

        void SetPreviousElement(Element<T> *a)
        {
            previous = a;
        }

        Element<T>* GetNextElement()
        {
            return next;
        }

        Element<T>* GetPreviousElement()
        {
            return previous;
        }

        T GetValue()
        {
            return myValue;
        }
};

template<typename T>
class Array
{
    Element<T> *firstElement;
    Element<T> *lastElement;
    public:
        Array()
        {
            firstElement = NULL;
            lastElement = NULL;
        }

        void Insert(T x)
        {

            Element<T> *newElement = new Element<T>(x);

            if (firstElement == NULL)
                firstElement = newElement;

            if (lastElement != NULL)
            {
                lastElement -> SetNextElement( newElement );
                newElement -> SetPreviousElement( lastElement );
            }

            lastElement = newElement;

        }

        T Get( int index )
        {
            Element<T> *cursor = firstElement;

            for (int i=0; i<index; i++)
            {
                if( cursor == NULL)
                    return NULL;

                cursor = cursor -> GetNextElement();
            }

            return cursor -> GetValue();
        }

        bool Remove( int index )
        {
            Element<T> *cursor = firstElement;

            int i=0;
            while( i < index)
            {
                cursor = cursor->GetNextElement();
                i++;
            }

            if (cursor == NULL)
                return false;

            Element<T> * prevElement = cursor->GetPreviousElement();
            Element<T> * nextElement = cursor->GetNextElement();

            if(prevElement)
                prevElement->SetNextElement( cursor->GetNextElement() );
            else
                firstElement = cursor->GetNextElement();
            
            if(nextElement)
                nextElement->SetPreviousElement(cursor -> GetPreviousElement());

            return true;
        }

        int Count()
        {
            int i=0;

            Element<T> *cursor = firstElement;

            while( cursor != NULL)
            {
                cursor = cursor->GetNextElement();
                i++;
            }

            return i;
        }

        void DebugDisplay()
        {
            Element<T> *cursor = firstElement;

            printf("\n------- DEBUG ARRAY --------\n");
            printf("Elements Count: %d \n", Count() );
            while( cursor != NULL)
            {
                std::cout << " -> "<< cursor->GetValue();

                cursor = cursor->GetNextElement();

            }

            std::cout << std::endl;
        }
};