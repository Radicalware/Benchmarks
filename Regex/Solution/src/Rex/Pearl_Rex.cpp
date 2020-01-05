
#include "Rex/Pearl_Rex.h"


Pearl_Rex::Pearl_Rex()
{

}

Pearl_Rex::~Pearl_Rex()
{
    
}

void Pearl_Rex::loop_match()
{
    m_timer.reset();
    Rex rex(m_regex_str);

    int count = 0;
    for (int i = 0; i < m_max_loop; i++) 
    {
        for (const auto& email : m_emails)
        {
            if (rex.match(email))
            {
                //if (!m_printed) {
                //    cout << "Email Found: " + email + '\n';
                //    m_printed = true;
                //}
                count++;
            }
        }
    }
    
    cout << count << ": Pearl Time: " << m_timer.elapsed() << endl;
}