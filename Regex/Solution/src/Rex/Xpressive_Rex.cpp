
#include "Rex/Xpressive_Rex.h"


Xpressive_Rex::Xpressive_Rex()
{

}

Xpressive_Rex::~Xpressive_Rex()
{
    
}

void Xpressive_Rex::loop_match()
{
    m_timer.reset();
    boost::xpressive::cregex  rex = boost::xpressive::cregex::compile(m_regex_str);
    int count = 0;
    for (int i = 0; i < m_max_loop; i++)
    {
        for (auto& email : m_emails)
        {
            if (boost::xpressive::regex_match(email.c_str(), rex))
            {
                //if (!m_printed) {
                //    cout << "Email Found: " + *it + '\n';
                //    m_printed = true;
                //}
                count++;
            }
        }
    }
    cout << count << ": Xpres Time: " << m_timer.elapsed() << endl;
}
