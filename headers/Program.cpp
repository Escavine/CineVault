#include "StudentMonitorMenu.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void main(array<String^>^ args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    bool showMenu = true;  // Set this condition based on your logic

    if (showMenu)
    {
        StudentMonitor::StudentMonitorMenu form;
        Application::Run(% form);
    }
    else
    {
        try
        {
            StudentMonitor::StaffLogin staffLogin;
            staffLogin.ShowDialog();
            User^ user = staffLogin.user;  // Adjust this line based on your implementation

            if (user != nullptr)
            {
                MessageBox::Show("Successful authentication of " + user->name, "StaffLogin.cpp", MessageBoxButtons::OK);
            }
            else
            {
                MessageBox::Show("Authentication failed", "StaffLogin.cpp", MessageBoxButtons::OK);
            }
        }
        catch (Exception^ ex)
        {
            MessageBox::Show("Error: " + ex->Message, "Error", MessageBoxButtons::OK);
        }
    }
}