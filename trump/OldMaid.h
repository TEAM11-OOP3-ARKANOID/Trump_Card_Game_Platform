#pragma once

#include "OldMaidGame.h"
#include <vcclr.h>
#include <string>
#include <sstream>
namespace trump {


	

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	
	/// <summary>
	/// OldMaid�� ���� ����Դϴ�.
	/// </summary>
	public ref class OldMaid : public System::Windows::Forms::Form
	{

	private: System::Collections::Generic::List< System::Windows::Forms::Button^> button_list;
	private: System::Void OldMaid_Load(System::Object^ sender, System::EventArgs^ e) {


		int playernum = oldmaidgame->getplayernum();
		
		std::vector<Draw*> playercard = oldmaidgame->getplayercard();
		
		//playercard[0]->print();
		//textBox1->AppendText("Lets start the game" + "\r\n");�̷������� ����Ʈ
		playercard[0]->print_winform(textBox1);
		printf("\n");


		


		int xPos = 90, yPos = 10;		// ��ư�� x, y ��ġ
		for (int x = 0; x < 1; x++)		// ��ư 6�� ����
		{
			button_list.Add(gcnew Button); // ��ư ����Ʈ�� ��ư�� �߰�
			button_list[x]->Location = Point(xPos, yPos); // ��ư�� ��ġ

			if (x == 0) {
				button_list[x]->Text = "pull out next player's card";
			}
			
			button_list[x]->Font = (gcnew System::Drawing::Font(L"Kristen ITC", 8));
			button_list[x]->Size = System::Drawing::Size(100, 50); // ��ư�� ũ��
			button_list[x]->Click += gcnew System::EventHandler(this, &OldMaid::ButtonClick); // ��ư�� Ŭ������ �� �̺�Ʈ
			this->Controls->Add(button_list[x]);
			xPos += 100;
		}
	}
	private: System::Void ButtonClick(System::Object^ sender, System::EventArgs^ e)
	{
		System::Windows::Forms::Button^ btn = (System::Windows::Forms::Button^)sender;	// Ŭ���� ��ư
		//MessageBox::Show(btn->Text);
		if (btn->Text == "pull out next player's card") {
			oldmaidgame->Myturn(textBox1);
			oldmaidgame->AIturn(textBox1);
			
		}
		
	}
	private: System::Windows::Forms::TextBox^ textBox1;






	public:
		OldMaidGame *oldmaidgame;
		OldMaid(void)
		{
			oldmaidgame = new OldMaidGame;
			InitializeComponent();
			//
			
			//
		}

	protected:
		/// <summary>
		/// ��� ���� ��� ���ҽ��� �����մϴ�.
		/// </summary>
		~OldMaid()
		{
			if (components)
			{
				delete components;
			}
		}

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
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->ForeColor = System::Drawing::SystemColors::WindowText;
			this->textBox1->Location = System::Drawing::Point(29, 114);
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->textBox1->Size = System::Drawing::Size(230, 300);
			this->textBox1->TabIndex = 0;
			this->textBox1->Multiline = true;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Kristen ITC", 8));
			textBox1->AppendText("Lets start the game" + "\r\n");
			
			// 
			// OldMaid
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 450);
			this->Controls->Add(this->textBox1);
			this->Name = L"OldMaid";
			this->Text = L"OldMaid";
			this->Load += gcnew System::EventHandler(this, &OldMaid::OldMaid_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
