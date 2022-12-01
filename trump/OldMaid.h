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
	/// OldMaid에 대한 요약입니다.
	/// </summary>
	public ref class OldMaid : public System::Windows::Forms::Form
	{

	private: System::Collections::Generic::List< System::Windows::Forms::Button^> button_list;
	private: System::Void OldMaid_Load(System::Object^ sender, System::EventArgs^ e) {
		int xPos = 10, yPos = 10;		// 버튼의 x, y 위치
		for (int x = 0; x < 3; x++)		// 버튼 6개 생성
		{
			button_list.Add(gcnew Button); // 버튼 리스트에 버튼을 추가
			button_list[x]->Location = Point(xPos, yPos); // 버튼의 위치

			if (x == 0) {
				button_list[x]->Text = "Black Jack";
			}
			else if (x == 1) {
				button_list[x]->Text = "Old Maid";
			}
			else if (x == 2) {
				button_list[x]->Text = "One Card";
			}

			button_list[x]->Size = System::Drawing::Size(90, 50); // 버튼의 크기
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

			
			OldMaidGame oldmaidgame;
			int playernum = oldmaidgame.getplayernum();
			std::vector<Draw> playercard = oldmaidgame.getplayercard();
			
			
			//this->Load += gcnew System::EventHandler(this, &OldMaid::OldMaid_Load);
		}
#pragma endregion
	};
}
