#include<iostream>
using namespace std;


class subvector {

public:
    int *mas;
    unsigned int top;
    unsigned int capacity;

    bool init(subvector *qv)
    {
        //initializing an empty non-vector
        qv ->top = 0;
        qv ->capacity =0;
        qv-> mas = NULL;
        return true;
    }

    int get_element(subvector* qv, int  where)
    {
        // where -index, that is, from scratch

        return qv->mas[where];


    }


    int pop_forward(subvector *qv)
    {
        int data = 0;
        if (qv->top != 0)
        {
            int * new_mas = new int[qv->capacity-1];
            for (int i = 0; i < qv->top - 1; i++) // ошибка была i < qv->top
            {

                new_mas[i] = qv->mas[i+1];

            }

            data = qv->mas[0];
            delete[] qv->mas;
            qv->mas= new_mas;

            qv->capacity -= 1;
            qv->top -= 1;

        }

        return data;
    }


    bool push_forward(subvector *qv, int d)
    {
        if (qv->top == 0)
        {
             int* mas_1 = new int [1];
            *mas_1 = d;
            delete[] qv->mas;
            qv->mas = mas_1;
            qv ->capacity = 1;
            qv ->top = 1;

        }

        else if (qv->top < qv->capacity)
        {
            qv->mas[qv->top+1] = d;
            qv->top ++;


        }

        else
        {
            int* new_mas = new int [qv->capacity + 1];
            for (int i = 0; i < qv->top; i++)// ошибка была i <= qv->top
            {
                new_mas[i+1] = qv->mas[i];

            }
            new_mas[0] = d;
            qv->capacity ++;
            qv->top++;
            delete[] qv->mas;
            qv->mas = new_mas;

        }
        return true;
    }

    bool push_back(subvector *qv, int d)
 // adding an element to the end of a non-vector
//with additional memory allocation if necessary

    {

        if (qv->top == 0)
        {
            //int* new_mas = new int  [1];
            //*(new_mas) = d;
            //delete[] qv-> mas; //удалять не нужно так как он указывает на ноль, находящейся в начале памяти

            int* mas_1 = new int [1];
            *mas_1 = d;
            qv->mas = mas_1;
            qv ->capacity = 1;
            qv ->top = 1;


        }

        else if ((qv ->capacity == qv ->top) && (qv->capacity != 0))

        {


            int* new_mas = new int  [qv->capacity+1];
            for (unsigned int i = 0; i < (qv ->capacity); ++i)
            {
                 new_mas[i] = *(qv ->mas + i);


            }

            new_mas[qv->top] = d;
            delete [] qv->mas;
            qv ->mas = new_mas;
            qv->top ++;
            qv ->capacity ++;
        }


        else if (qv->top < qv->capacity)
        {

            qv->mas[qv ->top] = d;
            qv ->top ++;

        }

        return true;
    }



    int pop_back(subvector *qv)// removing an element from the end of a sub-vector
    {

       int data = 0;

        if (qv->top == 0)
        {
            data =0;
        }
        else
        {
            data = qv->mas[(qv->top)-1];
            qv->top -= 1;
        }


        return data;
    }
    bool resize(subvector *qv, unsigned int new_capacity) //increase the capacity of the under-vector
    {
        int* new_mas = new int  [new_capacity];
        for (unsigned int i = 0; i < qv ->top; ++i)
        {
            new_mas[i] = qv->mas[i];


        }

        delete[] qv ->mas;
        qv ->mas = new_mas;
        qv->capacity = new_capacity;


        return 0;

    }
    void shrink_to_fit(subvector *qv) // clear unused memory
    {

        if (qv->top == qv->capacity)
        {


        }

        else
        {

            int* mas_new = new int [qv->top];
            for (unsigned int i = 0; i < qv->top; ++i)
            {

                mas_new[i] = qv ->mas[i];

            }

            delete [] qv ->mas;
            qv ->mas = mas_new;
            qv ->capacity = qv->top;

        }



    }
    void clear(subvector *qv)
    // clear the contents of the under-vector, the space occupied
//does not change at the same time
    {

        qv->top = 0;


    }
    void destructor(subvector *qv)
    // clear all used memory, initialize
/ / the under-vector as empty
    {
        delete [] qv ->mas;
        init(qv);
    }
    bool init_from_file(subvector *qv, char *filename) // initialize a non-vector from a file
    {

        return true;
    }

};
