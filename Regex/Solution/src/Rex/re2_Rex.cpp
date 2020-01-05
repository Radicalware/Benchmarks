
#include "Rex/re2_Rex.h"


re2_Rex::re2_Rex()
{

}

re2_Rex::~re2_Rex()
{
    
}

void re2_Rex::loop_match()
{
    m_timer.reset();
    RE2 rex(m_regex_str);
    int count = 0;
    for (int i = 0; i < m_max_loop; i++) 
    {
        for (const auto& email : m_emails)
        {
            if(RE2::FullMatch(email, rex))
            {
                //if (!m_printed) {
                //    cout << "Email Found: " + email + '\n';
                //    m_printed = true;
                //}
                count++;
            }
        }
    }
    cout << count << ":   re2 Time: " << m_timer.elapsed() << endl;
}
