// UI header logic
#include "StaffLogin.h"
#include "staffDashboard.h"

using namespace System;
using namespace System::Windows::Forms;

void main(array<String^>^ args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    // load the login section first for authentication
    StudentMonitor::StaffLogin staffLogin;
    staffLogin.ShowDialog();

    User^ user = staffLogin.user;

    if (user != nullptr)
    {
        // should the users login attempt be successful, direct them to the dashboard
        MessageBox::Show("Authentication success! " + user->name, "Login Success", MessageBoxButtons::OK);
        StudentMonitor::staffDashboard staffDash;
        staffDash.ShowDialog();
    }
    else
    {
        // otherwise output failure if the details aren't matched with the ones saved in the database
        MessageBox::Show("Authentication failed! ", "Login Failed", MessageBoxButtons::OK);
    }
 }

