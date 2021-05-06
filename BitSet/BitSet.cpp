#include <iostream>
#include <math.h>

using namespace std;
//template <int T>
class Bitset
{
public:
   Bitset(int size)
 {
     m_bits = size;
     m_size =   (size +9)/ 32;
     buffer = new unsigned int[m_size] {0};
     bit_system = sizeof(int) * 8;
    }
   ~Bitset() {
       delete buffer;
   }

void set(unsigned int position, unsigned int value=1)
{
    int index = get_index(position);
    int shifting = (position - bit_system * index);   
    
    buffer[index] |= 1 << (shifting); 
    buffer[index] &= value << (shifting);
}

int count() const
{
        unsigned int count = 0;
        for (int i = 0; i < m_size; i++)
        {
            while (buffer[i]) {
                count += buffer[i] & 1;
                buffer[i] >>= 1;
            }
        }
     return count;
}

int size() const
{
    return m_bits;
}

bool any() const
{
    for (int i = 0; i < m_size; i++)
    {
        if (!buffer[i])
            return true;
    }
    return false;
}

bool none() const
{
    for (int i = 0; i < m_size; i++)
    {
        if (!buffer[i])
            return false;
    }
    return true;
}

void reset()
{
    for (int i = 0; i < m_size; i++)
    {
        buffer[i] = 0;
    }
}

void reset(int position)
{
    int index = get_index(position);
    int shifting = (position - bit_system * index);

    buffer[index] &= 0 << (shifting);
}

void resize(int size)
{
    unsigned int* temp_buffer = new unsigned int[size];
    for (int i = 0; i < m_size; ++i) //copy
    {
        temp_buffer[i] = buffer[i];
    }
    delete[] this->buffer; //delete old
    buffer = temp_buffer;
}


 void operator&(unsigned int rhs)
{

    for (int i = 0; i < m_size; i++)
    {
        buffer[i] & rhs;
    }
}
 Bitset& operator&=(unsigned int rhs)
{

    for (int i = 0; i < m_size; i++)
    {
        buffer[i] &= rhs;
    }
    return *this;
}
 void operator|(unsigned int rhs)
{

    for (int i = 0; i < m_size; i++)
    {
        buffer[i] | rhs;
    }
}

 Bitset& operator|=(unsigned int rhs)
{

    for (int i = 0; i < m_size; i++)
    {
        buffer[i] |= rhs;
    }
    return *this;
}
private:
    int get_index(int position)
    {
        return position / bit_system;
        
    }

private:
    int m_size;
    double m_bits;
    unsigned int bit_system;
   unsigned  int* buffer;
};



int main()
{

 
 }

