
#include "Rex/C_Rex.h"

#ifdef __unix__

C_Rex::C_Rex()
{

}

C_Rex::~C_Rex()
{
    
}

void C_Rex::loop_match()
{
    m_timer.reset();

    regex_t regex; 
    int reti = regcomp(&regex, R"(^.*999.*$)", 0);
    if (reti) {
        fprintf(stderr, "Could not compile regex\n");
        exit(1);
    }

    int count = 0;
    for (int i = 0; i < m_max_loop; i++) 
    {
        for (const auto& email : m_emails)
        {
            if (!regexec(&regex, email.c_str(), 0, NULL, 0))
            {
                //if (!m_printed) {
                //    cout << "Email Found: " + email + '\n';
                //    m_printed = true;
                //}
                count++;
            }
        }
    }

    regfree(&regex);
    cout << count << ": C_Rex Time: with VERY basic regex (.*999.*): " << m_timer.elapsed() << endl;
}

#endif