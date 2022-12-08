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
	/// OldMaid에 대한 요약입니다.
	/// </summary>
	public ref class OldMaid : public System::Windows::Forms::Form
	{

	private: System::Collections::Generic::List< System::Windows::Forms::Button^> button_list;
	private: System::Void OldMaid_Load(System::Object^ sender, System::EventArgs^ e) {


		int playernum = oldmaidgame->getplayernum();
		
		std::vector<Draw*> playercard = oldmaidgame->getplayercard();
		playercard[0]->print();
		printf("\n");


		


		int xPos = 10, yPos = 10;		// 버튼의 x, y 위치
		for (int x = 0; x < 1; x++)		// 버튼 6개 생성
		{
			button_list.Add(gcnew Button); // 버튼 리스트에 버튼을 추가
			button_list[x]->Location = Point(xPos, yPos); // 버튼의 위치

			if (x == 0) {
				button_list[x]->Text = "pull out next player's card";
			}
			

			button_list[x]->Size = System::Drawing::Size(90, 50); // 버튼의 크기
			button_list[x]->Click += gcnew System::EventHandler(this, &OldMaid::ButtonClick); // 버튼을 클릭했을 때 이벤트
			this->Controls->Add(button_list[x]);
			xPos += 100;
		}
	}
	private: System::Void ButtonClick(System::Object^ sender, System::EventArgs^ e)
	{
		System::Windows::Forms::Button^ btn = (System::Windows::Forms::Button^)sender;	// 클릭한 버튼
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
		/// 사용 중인 모든 리소스를 정리합니다.
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
