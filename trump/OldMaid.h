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
		playercard[0]->print();
		printf("\n");


		


		int xPos = 10, yPos = 10;		// ��ư�� x, y ��ġ
		for (int x = 0; x < 1; x++)		// ��ư 6�� ����
		{
			button_list.Add(gcnew Button); // ��ư ����Ʈ�� ��ư�� �߰�
			button_list[x]->Location = Point(xPos, yPos); // ��ư�� ��ġ

			if (x == 0) {
				button_list[x]->Text = "pull out next player's card";
			}
			

			button_list[x]->Size = System::Drawing::Size(90, 50); // ��ư�� ũ��
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
			oldmaidgame->Myturn();
			oldmaidgame->AIturn();
			
		}
		
	}




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
			

			this->components = gcnew System::ComponentModel::Container();
			this->Size = System::Drawing::Size(300,300);
			this->Text = L"OldMaid";
			this->Padding = System::Windows::Forms::Padding(0);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;

			
			
			
			
			
			this->Load += gcnew System::EventHandler(this, &OldMaid::OldMaid_Load);
		}
#pragma endregion
	};
}
