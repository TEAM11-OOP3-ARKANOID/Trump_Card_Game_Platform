#include "MyForm.h"
#include "BlackJack.h"

using namespace System;
using namespace System::Windows::Forms;
[STAThreadAttribute]

void main(array<String^>^ args) {
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	trump::MyForm form;	// Project1 - ���� ������Ʈ �̸�
	Application::Run(% form);
}

