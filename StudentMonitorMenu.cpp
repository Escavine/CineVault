#include "StudentMonitorMenu.h"
#include "StaffLogin.h"

using namespace System;
using namespace System::Windows::Forms;
[STAThreadAttribute]
int main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	StudentMonitor::StudentMonitorMenu form;
	Application::Run(% form);
}
