
#include "Rex/Boost_Rex.h"


Boost_Rex::Boost_Rex()
{

}

Boost_Rex::~Boost_Rex()
{
    
}

void Boost_Rex::loop_match()
{
    m_timer.reset();
    boost::regex rex(m_regex_str);
    int count = 0;
    for (int i = 0; i < m_max_loop; i++) 
    {
        for (auto& email : m_emails)
        {
            if (boost::regex_match(email, rex))
            {
                //if (!m_printed) {
                //    cout << "Email Found: " + *it + '\n';
                //    m_printed = true;
                //}
                count++;
            }
        }
    }
    cout << count << ": Boost Time: " << m_timer.elapsed() << endl;
}
