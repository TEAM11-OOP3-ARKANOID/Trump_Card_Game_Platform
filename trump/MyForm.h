#pragma once
#include "OldMaid.h"
#include "GetOldMaidPlayerNum.h"
namespace trump {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// MyForm�� ���� ����Դϴ�.
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{

	private: System::Collections::Generic::List< System::Windows::Forms::Button^> button_list;
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		int xPos = 10, yPos = 10;		// ��ư�� x, y ��ġ
		for (int x = 0; x < 3; x++)		// ��ư 6�� ����
		{
			button_list.Add(gcnew Button); // ��ư ����Ʈ�� ��ư�� �߰�
			button_list[x]->Location = Point(xPos, yPos); // ��ư�� ��ġ
			
			if (x == 0) {
				button_list[x]->Text = "Black Jack";
			}
			else if (x == 1) {
				button_list[x]->Text = "Old Maid";
			}
			else if (x == 2) {
				button_list[x]->Text = "One Card";
			}

			button_list[x]->Size = System::Drawing::Size(90, 50); // ��ư�� ũ��
			button_list[x]->Click += gcnew System::EventHandler(this, &MyForm::ButtonClick); // ��ư�� Ŭ������ �� �̺�Ʈ
			this->Controls->Add(button_list[x]);
			xPos += 100;
		}
	}
	private: System::Void ButtonClick(System::Object^ sender, System::EventArgs^ e)
	{
		System::Windows::Forms::Button^ btn = (System::Windows::Forms::Button^)sender;	// Ŭ���� ��ư
		//MessageBox::Show(btn->Text);
		if (btn->Text == "Black Jack") {
			//MessageBox::Show("???");
		}
		if (btn->Text == "Old Maid") {
			//OldMaid^ oldmaidForm = gcnew OldMaid;
			//oldmaidForm->Show();
			GetOldMaidPlayerNum^ getplayernumForm = gcnew GetOldMaidPlayerNum;
			getplayernumForm ->Show();
		}
		//���� â �̵�
	}

	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: ������ �ڵ带 ���⿡ �߰��մϴ�.
			//
		}

	protected:
		/// <summary>
		/// ��� ���� ��� ���ҽ��� �����մϴ�.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:

	private:
		/// <summary>
		/// �ʼ� �����̳� �����Դϴ�.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// �����̳� ������ �ʿ��� �޼����Դϴ�. 
		/// �� �޼����� ������ �ڵ� ������� �������� ������.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Kristen ITC", 15));
			this->label1->Location = System::Drawing::Point(20, 98);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(277, 28);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Tump Card Game Platform";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(309, 161);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
