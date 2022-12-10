#include "BlackJackGame.h"
#include <vcclr.h>
#include <iostream>
#include <ctime>

namespace trump {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class BlackJack : public System::Windows::Forms::Form
	{
	private: System::Collections::Generic::List< System::Windows::Forms::Button^> button_list;
	private: System::Void BlackJack_Load(System::Object^ sender, System::EventArgs^ e) {
		


		int xPos = 45, yPos = 10;		// ��ư�� x, y ��ġ
		for (int x = 0; x < 2; x++)		// ��ư 6�� ����
		{
			
			button_list.Add(gcnew Button); // ��ư ����Ʈ�� ��ư�� �߰�
			button_list[x]->Location = Point(xPos, yPos); // ��ư�� ��ġ
			
			if (x == 0) {
				button_list[x]->Text = "Draw";
			}

			else if (x == 1) {
				button_list[x]->Text = "Hit";
			}

			button_list[x]->Font = (gcnew System::Drawing::Font(L"Kristen ITC", 8));
			button_list[x]->Size = System::Drawing::Size(100, 50); // ��ư�� ũ��
			button_list[x]->Click += gcnew System::EventHandler(this, &BlackJack::ButtonClick); // ��ư�� Ŭ������ �� �̺�Ʈ
			this->Controls->Add(button_list[x]);
			xPos += 100;
		}
	}

	private: System::Void ButtonClick(System::Object^ sender, System::EventArgs^ e)
	{
		System::Windows::Forms::Button^ btn = (System::Windows::Forms::Button^)sender;	// Ŭ���� ��ư
		//MessageBox::Show(btn->Text);
		int sum;
		if (btn->Text == "Draw") {
			blackjack->PickNewCard(textBox1);
			if (sum = blackjack->getPlayerSum() >= 21) { // �÷��̾��� ���� ���� 21 �̻��� ��� �ڵ� ó��
				goto Hit;
			}
		}

		else if (btn->Text == "Hit") {
			Hit:
			blackjack->DealerAction(textBox1);
		}

	}

	public:
		BlackJackGame* blackjack;
		BlackJack(void)
		{
			blackjack = new BlackJackGame;
			InitializeComponent();
			//
			//TODO: ������ �ڵ带 ���⿡ �߰��մϴ�.
			//
		}
	private: System::Windows::Forms::TextBox^ textBox1;
	protected:
		/// <summary>
		/// ��� ���� ��� ���ҽ��� �����մϴ�.
		/// </summary>
		~BlackJack()
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
			// BlackJack
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 450);
			this->Controls->Add(this->textBox1);
			this->Name = L"BlackJack";
			this->Text = L"BlackJack";
			this->Load += gcnew System::EventHandler(this, &BlackJack::BlackJack_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
