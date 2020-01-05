
#include "Rex/STL_Rex.h"


STL_Rex::STL_Rex()
{

}

STL_Rex::~STL_Rex()
{
    
}

void STL_Rex::loop_match()
{
    m_timer.reset();
    std::regex rex(m_regex_str, rxm::ECMAScript);
    int count = 0;
    for (int i = 0; i < m_max_loop; i++) 
    {
        for (const auto& email : m_emails)
        {
            if (std::regex_match(email, rex))
            {
                //if (!m_printed) {
                //    cout << "Email Found: " + email + '\n';
                //    m_printed = true;
                //}
                count++;
            }
        }
    }

    cout << count << ":   STL Time: " << m_timer.elapsed() << endl;
}
