#include "MyForm.h"
#include "BlackJack.h"

using namespace System;
using namespace System::Windows::Forms;
[STAThreadAttribute]

void main(array<String^>^ args) {
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	trump::MyForm form;	// Project1 - 본인 프로젝트 이름
	Application::Run(% form);
}

