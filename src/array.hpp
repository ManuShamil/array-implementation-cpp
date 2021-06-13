

template<typename T>
class Element 
{
    T myValue;
    Element<T> *next;
    public:
        Element(T a)
        {
            myValue = a;
        }
        void SetNextElement(Element<T> *a)
        {
            next = a;
        }
        Element<T>* GetNextElement()
        {
            return next;
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
                lastElement -> SetNextElement( newElement );

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
};