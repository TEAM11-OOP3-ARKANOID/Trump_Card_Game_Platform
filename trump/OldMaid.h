#pragma once

#include "OldMaidGame.h"



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
			this->Controls->Add(button_list[x]);
			xPos += 100;
		}
	}




	public:
		OldMaid(void)
		{
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

			
			OldMaidGame oldmaidgame;
			int playernum = oldmaidgame.getplayernum();
			std::vector<Draw> playercard = oldmaidgame.getplayercard();
			
			
			//this->Load += gcnew System::EventHandler(this, &OldMaid::OldMaid_Load);
		}
#pragma endregion
	};
}
