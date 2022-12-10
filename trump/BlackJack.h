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
		


		int xPos = 45, yPos = 10;		// 버튼의 x, y 위치
		for (int x = 0; x < 2; x++)		// 버튼 6개 생성
		{
			
			button_list.Add(gcnew Button); // 버튼 리스트에 버튼을 추가
			button_list[x]->Location = Point(xPos, yPos); // 버튼의 위치
			
			if (x == 0) {
				button_list[x]->Text = "Draw";
			}

			else if (x == 1) {
				button_list[x]->Text = "Hit";
			}

			button_list[x]->Font = (gcnew System::Drawing::Font(L"Kristen ITC", 8));
			button_list[x]->Size = System::Drawing::Size(100, 50); // 버튼의 크기
			button_list[x]->Click += gcnew System::EventHandler(this, &BlackJack::ButtonClick); // 버튼을 클릭했을 때 이벤트
			this->Controls->Add(button_list[x]);
			xPos += 100;
		}
	}

	private: System::Void ButtonClick(System::Object^ sender, System::EventArgs^ e)
	{
		System::Windows::Forms::Button^ btn = (System::Windows::Forms::Button^)sender;	// 클릭한 버튼
		//MessageBox::Show(btn->Text);
		int sum;
		if (btn->Text == "Draw") {
			blackjack->PickNewCard(textBox1);
			if (sum = blackjack->getPlayerSum() >= 21) { // 플레이어의 패의 합이 21 이상일 경우 자동 처리
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
			//TODO: 생성자 코드를 여기에 추가합니다.
			//
		}
	private: System::Windows::Forms::TextBox^ textBox1;
	protected:
		/// <summary>
		/// 사용 중인 모든 리소스를 정리합니다.
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
		/// 필수 디자이너 변수입니다.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 디자이너 지원에 필요한 메서드입니다. 
		/// 이 메서드의 내용을 코드 편집기로 수정하지 마세요.
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
