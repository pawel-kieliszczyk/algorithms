#ifndef PK_NTHFIBONACCINUMBER_HPP
#define PK_NTHFIBONACCINUMBER_HPP


#include <algorithm>


namespace pk
{


int nth_fibonacci_number(int n)
{
    if(n == 0)
        return 0;

    int m_prev[2][2] = {{1, 0}, {0, 1}};
    int m_next[2][2];

    int (*m_prev_p)[2] = m_prev;
    int (*m_next_p)[2] = m_next;

    int c_next[2][2] = {{1, 1}, {1, 0}};
    int c_prev[2][2];

    int (*c_next_p)[2] = c_next;
    int (*c_prev_p)[2] = c_prev;

    --n;
    while(n > 0)
    {
        if(n % 2 == 1)
        {
            m_next_p[0][0] = m_prev_p[0][0] * c_next_p[0][0] + m_prev_p[0][1] * c_next_p[1][0];
            m_next_p[0][1] = m_prev_p[0][0] * c_next_p[0][1] + m_prev_p[0][1] * c_next_p[1][1];
            m_next_p[1][0] = m_prev_p[1][0] * c_next_p[0][0] + m_prev_p[1][1] * c_next_p[1][0];
            m_next_p[1][1] = m_prev_p[1][0] * c_next_p[0][1] + m_prev_p[1][1] * c_next_p[1][1];

            std::swap(m_prev_p, m_next_p);
        }

        c_prev_p[0][0] = c_next_p[0][0] * c_next_p[0][0] + c_next_p[0][1] * c_next_p[1][0];
        c_prev_p[0][1] = c_next_p[0][0] * c_next_p[0][1] + c_next_p[0][1] * c_next_p[1][1];
        c_prev_p[1][0] = c_next_p[1][0] * c_next_p[0][0] + c_next_p[1][1] * c_next_p[1][0];
        c_prev_p[1][1] = c_next_p[1][0] * c_next_p[0][1] + c_next_p[1][1] * c_next_p[1][1];

        std::swap(c_prev_p, c_next_p);

        n /= 2;
    }

    return m_prev_p[0][0];
}


} // namespace pk


#endif // PK_NTHFIBONACCINUMBER_HPP
